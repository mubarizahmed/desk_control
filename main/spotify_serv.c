/**
 * @file spotify_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Spotify service for handling Spotify authentication and token management.
 * @version 0.1
 * @date 2025-04-17
 *
 */

#include "cJSON.h"
#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_https_server.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "mbedtls/base64.h"
#include "string.h"
#include <sys/param.h>

#include "display_manager.h"
#include "spotify_serv.h"
#include "ui.h"
#include "wifi_manager.h"

static const char *TAG = "SPOTIFY_SERV";

#define DEBUG 1

// char g_refresh_token[300] = "";
// char g_client_id[100] = CLIENT_ID;
// char g_client_secret[100] = CLIENT_SECRET;
// uint16_t g_port = 80;

#define MAX_HTTP_OUTPUT_BUFFER 4024
static char response_buffer[MAX_HTTP_OUTPUT_BUFFER];

SpotifyContext g_spotify_ctx = {
    .client_id = "",
    .client_secret = "",
    .refresh_token = "",
    .access_token = "",
    .auth_code = "",
    .debug_on = false,
    .port = 443,
    .retry = 0,
    .max_retry = 3,
    .no_credentials = false,
};

const char *spotify_scopes = "user-read-currently-playing user-modify-playback-state";

extern const uint8_t server_cert_pem_start[] asm("_binary_server_cert_pem_start");
extern const uint8_t server_cert_pem_end[] asm("_binary_server_cert_pem_end");
extern const uint8_t server_key_pem_start[] asm("_binary_server_key_pem_start");
extern const uint8_t server_key_pem_end[] asm("_binary_server_key_pem_end");

const char credentials_input[] =
    "<HTML>"
    "<HEAD>"
    "<TITLE>Enter Credentials</TITLE>"
    "</HEAD>"
    "<BODY>"
    "<h1>Enter your Credentials</h1>"
    "<p>If you don't have a refresh token leave empty</p>"
    "<form action=\"/get\">"
    "Client ID: <input type=\"text\" name=\"id\">"
    "<p></p>"
    "Client Secret: <input type=\"text\" name=\"secret\">"
    "<p></p>"
    "Refreshtoken: <input type=\"text\" name=\"token\">"
    "<input type=\"submit\" value=\"Submit\">"
    "</form>"
    "</BODY>"
    "</HTML>";

const char login_page_template[] =
    "<HTML>"
    "<HEAD>"
    "<TITLE>ESP Spotify Login</TITLE>"
    "</HEAD>"
    "<BODY>"
    "<CENTER>"
    "<h1>Login to Spotify</h1>"
    "<p>Click the link below to login to Spotify</p>"
    "<a href=\"https://accounts.spotify.com/authorize?client_id=%s&response_type=code&redirect_uri=%s&scope=user-read-currently-playing user-modify-playback-state\">Login</a>"
    "</CENTER>"
    "</BODY>"
    "</HTML>";

const char *_spotify_root_ca =
    "-----BEGIN CERTIFICATE-----\n"
    "MIIEyDCCA7CgAwIBAgIQDPW9BitWAvR6uFAsI8zwZjANBgkqhkiG9w0BAQsFADBh\n"
    "MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n"
    "d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBH\n"
    "MjAeFw0yMTAzMzAwMDAwMDBaFw0zMTAzMjkyMzU5NTlaMFkxCzAJBgNVBAYTAlVT\n"
    "MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxMzAxBgNVBAMTKkRpZ2lDZXJ0IEdsb2Jh\n"
    "bCBHMiBUTFMgUlNBIFNIQTI1NiAyMDIwIENBMTCCASIwDQYJKoZIhvcNAQEBBQAD\n"
    "ggEPADCCAQoCggEBAMz3EGJPprtjb+2QUlbFbSd7ehJWivH0+dbn4Y+9lavyYEEV\n"
    "cNsSAPonCrVXOFt9slGTcZUOakGUWzUb+nv6u8W+JDD+Vu/E832X4xT1FE3LpxDy\n"
    "FuqrIvAxIhFhaZAmunjZlx/jfWardUSVc8is/+9dCopZQ+GssjoP80j812s3wWPc\n"
    "3kbW20X+fSP9kOhRBx5Ro1/tSUZUfyyIxfQTnJcVPAPooTncaQwywa8WV0yUR0J8\n"
    "osicfebUTVSvQpmowQTCd5zWSOTOEeAqgJnwQ3DPP3Zr0UxJqyRewg2C/Uaoq2yT\n"
    "zGJSQnWS+Jr6Xl6ysGHlHx+5fwmY6D36g39HaaECAwEAAaOCAYIwggF+MBIGA1Ud\n"
    "EwEB/wQIMAYBAf8CAQAwHQYDVR0OBBYEFHSFgMBmx9833s+9KTeqAx2+7c0XMB8G\n"
    "A1UdIwQYMBaAFE4iVCAYlebjbuYP+vq5Eu0GF485MA4GA1UdDwEB/wQEAwIBhjAd\n"
    "BgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwdgYIKwYBBQUHAQEEajBoMCQG\n"
    "CCsGAQUFBzABhhhodHRwOi8vb2NzcC5kaWdpY2VydC5jb20wQAYIKwYBBQUHMAKG\n"
    "NGh0dHA6Ly9jYWNlcnRzLmRpZ2ljZXJ0LmNvbS9EaWdpQ2VydEdsb2JhbFJvb3RH\n"
    "Mi5jcnQwQgYDVR0fBDswOTA3oDWgM4YxaHR0cDovL2NybDMuZGlnaWNlcnQuY29t\n"
    "L0RpZ2lDZXJ0R2xvYmFsUm9vdEcyLmNybDA9BgNVHSAENjA0MAsGCWCGSAGG/WwC\n"
    "ATAHBgVngQwBATAIBgZngQwBAgEwCAYGZ4EMAQICMAgGBmeBDAECAzANBgkqhkiG\n"
    "9w0BAQsFAAOCAQEAkPFwyyiXaZd8dP3A+iZ7U6utzWX9upwGnIrXWkOH7U1MVl+t\n"
    "wcW1BSAuWdH/SvWgKtiwla3JLko716f2b4gp/DA/JIS7w7d7kwcsr4drdjPtAFVS\n"
    "slme5LnQ89/nD/7d+MS5EHKBCQRfz5eeLjJ1js+aWNJXMX43AYGyZm0pGrFmCW3R\n"
    "bpD0ufovARTFXFZkAdl9h6g4U5+LXUZtXMYnhIHUfoyMo5tS58aI7Dd8KvvwVVo4\n"
    "chDYABPPTHPbqjc1qCmBaZx2vN4Ye5DUys/vZwP9BFohFrH/6j/f3IL16/RZkiMN\n"
    "JCqVJUzKoZHm1Lesh3Sz8W2jmdv51b2EQJ8HmA==\n"
    "-----END CERTIFICATE-----\n";

void start_webserver(SpotifyContext *ctx);

// get access token
// build the request
bool is_auth(SpotifyContext *ctx) {
    return !(strcmp(ctx->refresh_token, "") == 0 || strcmp(ctx->client_id, "") == 0 || strcmp(ctx->client_secret, "") == 0);
}

void get_access_token(SpotifyContext *ctx) {
    // This function should be implemented to get the access token from Spotify API
    // using the client_id, client_secret, and refresh_token.
    // The access token should be stored in ctx->access_token.

    // check if refresh token is empty
    if (!is_auth(ctx)) {
        ESP_LOGE("SPOTIFY", "No refresh token available");

        // start web server for authentication
        if (!is_auth(ctx)) {
            if (ctx->port == 443) {
                char redirect_uri[40];

                snprintf(ctx->redirect_uri, sizeof(redirect_uri), "https://%d.%d.%d.%d/", IP2STR(&ip_addr));

                ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&ip_addr));
                ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: %s\n", ctx->redirect_uri);
                // snprintf(redirect_uri, sizeof(redirect_uri), "http://"IPSTR"/", "got ip:" IPSTR, IP2STR();
                // ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: http://%s/\n", WiFi.localIP().toString().c_str());
            } else {
                // ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: http://%s:%d/\n", WiFi.localIP().toString().c_str(), g_port);
            }
            start_webserver(ctx);
        }
    }
}

esp_err_t _http_event_handler(esp_http_client_event_t *evt) {
    static char *output_buffer; // Buffer to store response of http request from event handler
    static int output_len;      // Stores number of bytes read

    switch (evt->event_id) {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        // Clean the buffer in case of a new request
        if (output_len == 0 && evt->user_data) {
            // we are just starting to copy the output data into the use
            memset(evt->user_data, 0, MAX_HTTP_OUTPUT_BUFFER);
        }
        /*
         *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
         *  However, event handler can also be used in case chunked encoding is used.
         */
        if (!esp_http_client_is_chunked_response(evt->client)) {
            // If user_data buffer is configured, copy the response into the buffer
            int copy_len = 0;
            if (evt->user_data) {
                // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                copy_len = MIN(evt->data_len, (MAX_HTTP_OUTPUT_BUFFER - output_len));
                if (copy_len) {
                    memcpy(evt->user_data + output_len, evt->data, copy_len);
                }
            } else {
                int content_len = esp_http_client_get_content_length(evt->client);
                if (output_buffer == NULL) {
                    // We initialize output_buffer with 0 because it is used by strlen() and similar functions therefore should be null terminated.
                    output_buffer = (char *)calloc(content_len + 1, sizeof(char));
                    output_len = 0;
                    if (output_buffer == NULL) {
                        ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                        return ESP_FAIL;
                    }
                }
                copy_len = MIN(evt->data_len, (content_len - output_len));
                if (copy_len) {
                    memcpy(output_buffer + output_len, evt->data, copy_len);
                }
            }
            output_len += copy_len;
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        if (output_buffer != NULL) {
#if CONFIG_EXAMPLE_ENABLE_RESPONSE_BUFFER_DUMP
            ESP_LOG_BUFFER_HEX(TAG, output_buffer, output_len);
#endif
            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
        int mbedtls_err = 0;
        esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
        if (err != 0) {
            ESP_LOGI(TAG, "Last esp error code: 0x%x", err);
            ESP_LOGI(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
        }
        if (output_buffer != NULL) {
            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_REDIRECT:
        ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
        esp_http_client_set_header(evt->client, "From", "user@example.com");
        esp_http_client_set_header(evt->client, "Accept", "text/html");
        esp_http_client_set_redirection(evt->client);
        break;
    }
    return ESP_OK;
}

bool get_refresh_token(const char *auth_code, const char *redirect_uri) {
    char post_data[512];

    // Construct POST data
    snprintf(post_data, sizeof(post_data),
             "grant_type=authorization_code&code=%s&redirect_uri=%s&client_id=%s&client_secret=%s",
             auth_code, redirect_uri, g_spotify_ctx.client_id, g_spotify_ctx.client_secret);

    ESP_LOGI(TAG, "Refresh token POST data: %s", post_data);

    // Clear the buffer before request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_config_t config = {
        .url = "https://accounts.spotify.com/api/token",
        .method = HTTP_METHOD_POST,
        .timeout_ms = 5000,
        .cert_pem = _spotify_root_ca,
        .event_handler = _http_event_handler,
        .user_data = response_buffer,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));

    esp_err_t err = esp_http_client_perform(client);
    if (err != ESP_OK) {
        ESP_LOGE("SPOTIFY", "HTTP request failed: %s", esp_err_to_name(err));
        esp_http_client_cleanup(client);
        return false;
    }

    ESP_LOGI(TAG, "Response: >>>%s<<<", response_buffer);

    // Parse JSON response
    cJSON *root = cJSON_Parse(response_buffer);
    if (!root) {
        ESP_LOGE("SPOTIFY", "Failed to parse JSON");
        esp_http_client_cleanup(client);
        return false;
    }

    cJSON *refresh_token = cJSON_GetObjectItem(root, "refresh_token");
    if (refresh_token && cJSON_IsString(refresh_token)) {
        strncpy(g_spotify_ctx.refresh_token, refresh_token->valuestring, sizeof(g_spotify_ctx.refresh_token) - 1);
        g_spotify_ctx.refresh_token[sizeof(g_spotify_ctx.refresh_token) - 1] = '\0';

        cJSON *access_token = cJSON_GetObjectItem(root, "access_token");
        if (access_token && cJSON_IsString(access_token)) {
            strncpy(g_spotify_ctx.access_token, access_token->valuestring, sizeof(g_spotify_ctx.access_token) - 1);
            g_spotify_ctx.access_token[sizeof(g_spotify_ctx.access_token) - 1] = '\0';
        }

        ESP_LOGI(TAG, "Access Token: %s", g_spotify_ctx.access_token);
        ESP_LOGI(TAG, "Refresh Token: %s", g_spotify_ctx.refresh_token);

        cJSON_Delete(root);
        esp_http_client_cleanup(client);

#ifdef DEBUG
        // print heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGI(TAG, "get_refresh_token heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
#endif

        return true;
    } else {
        ESP_LOGW("SPOTIFY", "No refresh token in response");
    }

    cJSON_Delete(root);
    esp_http_client_cleanup(client);
    return false;
}

esp_err_t root_get_handler(httpd_req_t *req) {
    char buf[100];
    size_t buf_len;

    buf_len = httpd_req_get_hdr_value_len(req, "User-Agent") + 1;
    ESP_LOGI(TAG, "User-Agent length: %d", buf_len);
    if (buf_len > 1) {
        httpd_req_get_hdr_value_str(req, "User-Agent", buf, sizeof(buf));
        ESP_LOGI(TAG, "User-Agent: %s", buf);
    }

    // Access context via `req->user_ctx`
    SpotifyContext *ctx = (SpotifyContext *)req->user_ctx;

    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, credentials_input, HTTPD_RESP_USE_STRLEN);

#ifdef DEBUG
    // print heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGI(TAG, "root_get_handler heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
#endif
    return ESP_OK;
}

esp_err_t callback_handler(httpd_req_t *req) {
    SpotifyContext *ctx = (SpotifyContext *)req->user_ctx;

    if (ctx->refresh_token[0] == '\0') {
        char query[256] = "";
        esp_err_t query_status = httpd_req_get_url_query_str(req, query, sizeof(query));

        // Case: No arguments, send login page
        if (query_status != ESP_OK || strlen(query) == 0) {
            char page[900];
            char redirect_callback[150];

            snprintf(redirect_callback, sizeof(redirect_callback), "%scallback", ctx->redirect_uri);
            snprintf(page, sizeof(page), login_page_template, ctx->client_id, redirect_callback);

            httpd_resp_set_type(req, "text/html");
            httpd_resp_sendstr(req, page);
            return ESP_OK;
        }

        ESP_LOGI(TAG, "Redirect URI: %s", ctx->redirect_uri);

        // Try to get the 'code' from query
        char code[256] = "";
        if (httpd_query_key_value(query, "code", code, sizeof(code)) == ESP_OK) {
            strncpy(ctx->auth_code, code, sizeof(ctx->auth_code));
            if (ctx->debug_on) {
                ESP_LOGI(TAG, "Auth Code: %s", ctx->auth_code);
            }

            // Get new refresh token from Spotify
            char redirect_uri_full[150];
            snprintf(redirect_uri_full, sizeof(redirect_uri_full), "%scallback", ctx->redirect_uri);

            if (get_refresh_token(ctx->auth_code, redirect_uri_full)) {
                char message[500];
                snprintf(message, sizeof(message),
                         "Setup Complete, Refresh Token: %s <br>You can now close this page",
                         ctx->refresh_token);
                httpd_resp_set_type(req, "text/html");
                httpd_resp_sendstr(req, message);
            } else {
                httpd_resp_set_type(req, "text/html");
                httpd_resp_sendstr(req, "Something went wrong, please try again");
            }

            // httpd_stop(ctx->server_handle);
            return ESP_OK;
        } else {
            // No code arg, fallback to login page
            char page[900];
            snprintf(page, sizeof(page), login_page_template, ctx->client_id, ctx->redirect_uri);

            httpd_resp_set_type(req, "text/html");
            httpd_resp_sendstr(req, page);
            return ESP_OK;
        }

    } else {
        // Refresh token already present — setup complete
        httpd_resp_set_type(req, "text/html");
        httpd_resp_sendstr(req, "Spotify setup complete");
        // httpd_stop(ctx->server_handle);
        return ESP_OK;
    }

#ifdef DEBUG
    // print heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGI(TAG, "callback_handler heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
#endif
}

esp_err_t get_handler(httpd_req_t *req) {
    SpotifyContext *ctx = (SpotifyContext *)req->user_ctx;

    char query[256];
    bool has_args = false;

    if (httpd_req_get_url_query_str(req, query, sizeof(query)) == ESP_OK) {
        has_args = true;

        char id[64] = "";
        char secret[64] = "";
        char token[128] = "";

        // Extract and copy into context
        if (httpd_query_key_value(query, "id", id, sizeof(id)) == ESP_OK) {
            strncpy(ctx->client_id, id, sizeof(ctx->client_id));
        }
        if (httpd_query_key_value(query, "secret", secret, sizeof(secret)) == ESP_OK) {
            strncpy(ctx->client_secret, secret, sizeof(ctx->client_secret));
        }
        if (httpd_query_key_value(query, "token", token, sizeof(token)) == ESP_OK) {
            strncpy(ctx->refresh_token, token, sizeof(ctx->refresh_token));
        }

        if (strlen(ctx->refresh_token) > 0) {
            httpd_resp_set_type(req, "text/html");
            httpd_resp_sendstr(req, "Credentials successfully set!");

            // Stop server after successful credential input (optional)
            // httpd_stop(ctx->server_handle);
        } else {
            // Redirect to /callback if no refresh token
            char location_header[256];
            snprintf(location_header, sizeof(location_header), "%scallback", ctx->redirect_uri);

            httpd_resp_set_status(req, "302 Found");
            httpd_resp_set_hdr(req, "Location", location_header);
            httpd_resp_send(req, NULL, 0); // No body
        }

    } else {
        // No arguments found
        httpd_resp_set_type(req, "text/html");
        httpd_resp_sendstr(req, "Something went wrong, please try again.");
    }

    return ESP_OK;
}

void start_webserver(SpotifyContext *ctx) {
    httpd_ssl_config_t conf = HTTPD_SSL_CONFIG_DEFAULT();

    // conf.httpd.max_uri_len = 512;     // default: 512
    conf.httpd.max_resp_headers = 8; // default: 8
    conf.httpd.max_open_sockets = 4; // default: 4
    // conf.httpd.max_header_len = 1024; // Bump this to 1024 or higher
    conf.httpd.stack_size = 8192; // Bump stack size for SSL

    conf.port_secure = ctx->port;

    conf.servercert = server_cert_pem_start;
    conf.servercert_len = server_cert_pem_end - server_cert_pem_start;
    conf.prvtkey_pem = server_key_pem_start;
    conf.prvtkey_len = server_key_pem_end - server_key_pem_start;

    esp_err_t ret = httpd_ssl_start(&ctx->server, &conf);
    if (ret == ESP_OK) {
        httpd_uri_t root = {
            .uri = "/",
            .method = HTTP_GET,
            .handler = root_get_handler,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &root);

        httpd_uri_t callback = {
            .uri = "/callback",
            .method = HTTP_GET,
            .handler = callback_handler,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &callback);

        httpd_uri_t get = {
            .uri = "/get",
            .method = HTTP_GET,
            .handler = get_handler,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &get);

        if (ctx->debug_on) {
            ESP_LOGI(TAG, "HTTPS server started");
        }
    } else {
        if (ctx->debug_on) {
            ESP_LOGE(TAG, "Failed to start HTTPS server: %s", esp_err_to_name(ret));
        }
    }
}

// {"access_token" : "BQDoxUgEEJBHTecdNPEHzkV0fwT9N97GC19EEhHCURvdcRELMC7rT1KarQb4wjjTH1yty92F0xqzhzVIosKbocUaFI48qd5eU-3GfERAcylmB7-Hcl4mQJEbpOygM4Cl-0If0i1IPNID2_fdX5Sm0lxIr2o8KP_AtDsuiHn1ns3MdKrCmafQf-OamrwsrPfCUUrbYoOwjYk2SZWPWtVv-l-dBz31K8uFJahoXf52KA",
//  "token_type" : "Bearer",
//  "expires_in" : 3600,
//  "refresh_token" : "AQDRo4ZUkpu1CnZKwG5NCJgHgPD9j87ooxkEkV0rn-qjSH2fs7ss12j6LflqYzqomTS3vuQW7uXHgAoUY-dn09X4iYX3GCh97mxsWiGoWjI9fN2xRlNY1EvQwWVt5NAuN90"} < < <

void get_current_playback(SpotifyContext *ctx, CurrentlyPlayingData *data) {
    ESP_LOGI(TAG, "Getting current playback");

    esp_http_client_config_t config = {
        .url = "https://api.spotify.com/v1/me/player/currently-playing?market=DE",
        .method = HTTP_METHOD_GET,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = _http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_handle_t client = esp_http_client_init(&config);

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", ctx->access_token);
    esp_err_t header_err = esp_http_client_set_header(client, "Authorization", auth_header);
    if (header_err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(header_err));
    }

    ESP_LOGI(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 200) {
            ESP_LOGI(TAG, "Current playback: %s", response_buffer);
            // Parse the response and extract relevant information
            cJSON *json = cJSON_Parse(response_buffer);
            if (json) {
                // Extract information from JSON
                const cJSON *item = cJSON_GetObjectItem(json, "item");
                if (item) {
                    const cJSON *name = cJSON_GetObjectItem(item, "name");
                    const cJSON *artist_array = cJSON_GetObjectItem(item, "artists");

                    char artist_names[128] = {0}; // Make sure it's big enough
                    if (name && cJSON_IsArray(artist_array)) {
                        int artist_count = cJSON_GetArraySize(artist_array);
                        for (int i = 0; i < artist_count && i < 3; i++) {
                            const cJSON *artist_obj = cJSON_GetArrayItem(artist_array, i);
                            const cJSON *artist_name = cJSON_GetObjectItem(artist_obj, "name");
                            if (artist_name && cJSON_IsString(artist_name)) {
                                strcat(artist_names, artist_name->valuestring);
                                if (i < artist_count - 1 && i < 2) {
                                    strcat(artist_names, ", ");
                                }
                            }
                        }
                        strcpy(data->name, name->valuestring);
                        strcpy(data->artists, artist_names);

                        const cJSON *duration_ms = cJSON_GetObjectItem(item, "duration_ms");
                        if (duration_ms && cJSON_IsNumber(duration_ms)) {
                            data->duration_ms = duration_ms->valueint;
                        }
                        const cJSON *progress_ms = cJSON_GetObjectItem(json, "progress_ms");
                        if (progress_ms && cJSON_IsNumber(progress_ms)) {
                            data->progress_ms = progress_ms->valueint;
                        }
                        const cJSON *album = cJSON_GetObjectItem(item, "album");
                        if (album) {
                            const cJSON *images = cJSON_GetObjectItem(album, "images");
                            if (images) {
                                int artist_count = cJSON_GetArraySize(images);

                                ESP_LOGI(TAG, "Images in the response %d", artist_count);

                                const cJSON *image = cJSON_GetArrayItem(images, 2);
                                if (image) {
                                    const cJSON *url = cJSON_GetObjectItem(image, "url");
                                    if (url && cJSON_IsString(url)) {

                                        strcpy(data->album_image_url, url->valuestring);
                                    }
                                }
                            }
                        }

                        const cJSON *is_playing = cJSON_GetObjectItem(json, "is_playing");
                        if (is_playing) {
                            data->is_playing = cJSON_IsTrue(is_playing);
                        } else {
                            data->is_playing = false; // Default to false if not present
                        }

                        ESP_LOGI(TAG, "Currently playing: %s by %s", name->valuestring, artist_names);
                    }
                }
                cJSON_Delete(json);
            }
        } else {
            ESP_LOGE(TAG, "Error: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
        ESP_LOGE(TAG, "Response: %s", response_buffer);
    }

    // heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGI(TAG, "get_current_playback heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

    esp_http_client_cleanup(client);
}

void spotify_task(void *pvParameters) {
    // Wait for WiFi to connect
    while (wifi_connected == 0) {
        vTaskDelay(pdMS_TO_TICKS(10000)); // 1 second delay
    }

    // Get access token
    get_access_token(&g_spotify_ctx);

    while (1) {
        CurrentlyPlayingData *data = (CurrentlyPlayingData *)malloc(sizeof(CurrentlyPlayingData));
        int32_t delay = 30000; // 30 seconds delay
        if (data == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory for CurrentlyPlayingData");
            vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
            continue;
        }
        memset(data, 0, sizeof(CurrentlyPlayingData));

        if (is_auth(&g_spotify_ctx)) {

            get_current_playback(&g_spotify_ctx, data);

            ESP_LOGI(TAG, "Currently playing: %s by %s", data->name, data->artists);
            ESP_LOGI(TAG, "Duration: %ld ms, Progress: %ld ms", data->duration_ms, data->progress_ms);
            ESP_LOGI(TAG, "Album: %s", data->album_name);
            ESP_LOGI(TAG, "Album Image URL: %s", data->album_image_url);
            ESP_LOGI(TAG, "Is Playing: %s", data->is_playing ? "true" : "false");

            delay = data->duration_ms - data->progress_ms + 5000; // Set delay to the remaining duration of the track
        }

        char name[16];
        char artists[20];

        if (strlen(data->name) > 15) {
            strncpy(name, data->name, 13);
            name[13] = '.';  // Add ellipsis
            name[14] = '.';  // Add ellipsis
            name[15] = '\0'; // Ensure null-termination
        } else {
            strcpy(name, data->name);
        }
        if (strlen(data->artists) > 19) {
            strncpy(artists, data->artists, 17);
            artists[17] = '.';  // Add ellipsis
            artists[18] = '.';  // Add ellipsis
            artists[19] = '\0'; // Ensure null-termination
        } else {
            strcpy(artists, data->artists);
        }

        _lock_acquire(&lvgl_api_lock);
        setSpotifyData(name, artists, data->is_playing);
        _lock_release(&lvgl_api_lock);

        free(data);                       // Free the allocated memory for CurrentlyPlayingData
        vTaskDelay(pdMS_TO_TICKS(delay)); // 30 seconds delay
    }
    vTaskDelete(NULL);
}

// token_refresh

// next_track

// previous_track

// play_track
// pause_track
