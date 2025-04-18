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

#include "spotify_serv.h"
#include "wifi_manager.h"

#define CLIENT_ID "5f83ca14cd424647bc9e8f6085964617"
#define CLIENT_SECRET "8d5aee2526f74e1285b7a332a1ec0b44"

static const char *TAG = "SPOTIFY_SERV";

// char g_refresh_token[300] = "";
// char g_client_id[100] = CLIENT_ID;
// char g_client_secret[100] = CLIENT_SECRET;
// uint16_t g_port = 80;

#define MAX_HTTP_OUTPUT_BUFFER 2048
static char response_buffer[MAX_HTTP_OUTPUT_BUFFER];

SpotifyContext g_spotify_ctx = {
    .client_id = CLIENT_ID,
    .client_secret = CLIENT_SECRET,
    .refresh_token = "",
    .access_token = "",
    .auth_code = "",
    .debug_on = false,
    .port = 443,
    .retry = 0,
    .max_retry = 3,
    .no_credentials = false,
};

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
    "<a href=\"https://accounts.spotify.com/authorize?client_id=%s&response_type=code&redirect_uri=%s\">Login</a>"
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

void spotify_init(SpotifyContext *ctx, const char *client_id, const char *client_secret, int port, bool debug_on, int max_retry) {
    memset(ctx, 0, sizeof(SpotifyContext));
    ctx->debug_on = debug_on;
    ctx->port = port;
    ctx->retry = 0;
    ctx->max_retry = max_retry > 0 ? max_retry : 1;

    if (!client_id || !client_secret) {
        ctx->no_credentials = true;
    } else {
        strncpy(ctx->client_id, client_id, sizeof(ctx->client_id));
        strncpy(ctx->client_secret, client_secret, sizeof(ctx->client_secret));
    }
}

// bool get_refresh_token(const char *auth_code, const char *redirect_uri) {
//     char post_data[512];
//     char auth_header[128];
//     char response_buf[MAX_HTTP_RECV_BUFFER] = {0};
//     esp_err_t err;

//     // Construct POST data
//     snprintf(post_data, sizeof(post_data),
//              "grant_type=authorization_code&code=%s&redirect_uri=%s&client_id=%s&client_secret=%s",
//              auth_code, redirect_uri, g_spotify_ctx.client_id, g_spotify_ctx.client_secret);

//     ESP_LOGI("SPOTIFY", "Refresh token POST data: %s", post_data);

//     // Setup HTTP client
//     esp_http_client_config_t config = {
//         .url = "https://accounts.spotify.com/api/token",
//         .method = HTTP_METHOD_POST,
//         .timeout_ms = 5000,
//         .cert_pem = _spotify_root_ca,
//     };

//     esp_http_client_handle_t client = esp_http_client_init(&config);

//     esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
//     esp_http_client_set_post_field(client, post_data, strlen(post_data));

//     err = esp_http_client_perform(client);
//     if (err != ESP_OK) {
//         ESP_LOGE("SPOTIFY", "HTTP request failed: %s", esp_err_to_name(err));
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     int content_length = esp_http_client_fetch_headers(client);

//     // Check for chunked response
//     if (content_length == -1) {
//         ESP_LOGE("SPOTIFY", "Chunked response not supported");
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     if (content_length <= 0) {
//         ESP_LOGE("SPOTIFY", "Invalid response");
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     int data_read = esp_http_client_read_response(client, response_buf, sizeof(response_buf) - 1);
//     if (data_read <= 0) {
//         ESP_LOGE("SPOTIFY", "Failed to read response");
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     // Parse JSON response
//     cJSON *root = cJSON_Parse(response_buf);
//     if (!root) {
//         ESP_LOGE("SPOTIFY", "Failed to parse JSON");
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     cJSON *refresh_token = cJSON_GetObjectItem(root, "refresh_token");
//     if (refresh_token && cJSON_IsString(refresh_token)) {
//         strncpy(g_spotify_ctx.refresh_token, refresh_token->valuestring, 300);
//         g_spotify_ctx.refresh_token[300 - 1] = '\0';

//         if (g_spotify_ctx.debug_on) {
//             ESP_LOGI("SPOTIFY", "Refresh Token: %s", g_spotify_ctx.refresh_token);
//         }

//         cJSON_Delete(root);
//         esp_http_client_cleanup(client);
//         return true;
//     } else {
//         ESP_LOGW("SPOTIFY", "No refresh token in response");
//     }

//     cJSON_Delete(root);
//     esp_http_client_cleanup(client);
//     return false;
// }

// bool get_refresh_token(const char *auth_code, const char *redirect_uri) {
//     char post_data[512];
//     char response_buf[MAX_HTTP_RECV_BUFFER] = {0};
//     // char total_response[2048] = {0}; // Big enough for full response
//     esp_err_t err;

//     // Construct POST data
//     snprintf(post_data, sizeof(post_data),
//              "grant_type=authorization_code&code=%s&redirect_uri=%s&client_id=%s&client_secret=%s",
//              auth_code, redirect_uri, g_spotify_ctx.client_id, g_spotify_ctx.client_secret);

//     ESP_LOGI("SPOTIFY", "Refresh token POST data: %s", post_data);

//     // Setup HTTP client
//     esp_http_client_config_t config = {
//         .url = "https://accounts.spotify.com/api/token",
//         .method = HTTP_METHOD_POST,
//         .timeout_ms = 5000,
//         .cert_pem = _spotify_root_ca,
//     };

//     esp_http_client_handle_t client = esp_http_client_init(&config);

//     esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
//     esp_http_client_set_post_field(client, post_data, strlen(post_data));

//     err = esp_http_client_perform(client);
//     if (err != ESP_OK) {
//         ESP_LOGE("SPOTIFY", "HTTP request failed: %s", esp_err_to_name(err));
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     // Read response in chunks
//     // int total_read = 0;
//     int content_len = esp_http_client_get_content_length(client);
//     ESP_LOGI("SPOTIFY", "Content Length: %d", content_len); // Might be -1 for chunked

//     char total_response[MAX_HTTP_RECV_BUFFER];
//     int total_read = 0;

//     while (1) {
//         int read = esp_http_client_read(client, response_buf, sizeof(response_buf));
//         if (read <= 0)
//             break;

//         if ((total_read + read) >= MAX_HTTP_RECV_BUFFER) {
//             ESP_LOGE("SPOTIFY", "Response too large for buffer");
//             break;
//         }

//         memcpy(total_response + total_read, response_buf, read);
//         total_read += read;
//     }

//     total_response[total_read] = '\0'; // Null-terminate after last chunk

//     ESP_LOGI("SPOTIFY", "Response: >>>%s<<<", total_response);

//     // Parse JSON response
//     cJSON *root = cJSON_Parse(total_response);
//     if (!root) {
//         ESP_LOGE("SPOTIFY", "Failed to parse JSON");
//         esp_http_client_cleanup(client);
//         return false;
//     }

//     cJSON *refresh_token = cJSON_GetObjectItem(root, "refresh_token");
//     if (refresh_token && cJSON_IsString(refresh_token)) {
//         strncpy(g_spotify_ctx.refresh_token, refresh_token->valuestring, 300);
//         g_spotify_ctx.refresh_token[299] = '\0';

//         if (g_spotify_ctx.debug_on) {
//             ESP_LOGI("SPOTIFY", "Refresh Token: %s", g_spotify_ctx.refresh_token);
//         }

//         cJSON_Delete(root);
//         esp_http_client_cleanup(client);
//         return true;
//     } else {
//         ESP_LOGW("SPOTIFY", "No refresh token in response");
//     }

//     cJSON_Delete(root);
//     esp_http_client_cleanup(client);
//     return false;
// }
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

    ESP_LOGI("SPOTIFY", "Refresh token POST data: %s", post_data);

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

    ESP_LOGI("SPOTIFY", "Response: >>>%s<<<", response_buffer);

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

        if (g_spotify_ctx.debug_on) {
            ESP_LOGI("SPOTIFY", "Refresh Token: %s", g_spotify_ctx.refresh_token);
        }

        cJSON_Delete(root);
        esp_http_client_cleanup(client);
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
    if (buf_len > 1) {
        httpd_req_get_hdr_value_str(req, "User-Agent", buf, sizeof(buf));
        ESP_LOGI("HTTPS", "User-Agent: %s", buf);
    }

    // Access context via `req->user_ctx`
    SpotifyContext *ctx = (SpotifyContext *)req->user_ctx;

    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, credentials_input, HTTPD_RESP_USE_STRLEN);
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
                ESP_LOGI("SPOTIFY", "Auth Code: %s", ctx->auth_code);
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
// esp_err_t credentials_get_handler(httpd_req_t *req) {
//     httpd_resp_set_type(req, "text/html");
//     httpd_resp_send(req, credentials_input, HTTPD_RESP_USE_STRLEN);
//     return ESP_OK;
// }

// void start_webserver(SpotifyContext *ctx) {
//     .crt_bundle_attach = esp_crt_bundle_attach,

//     httpd_config_t config = HTTPD_DEFAULT_CONFIG();
//     config.server_port = ctx->port;

//     httpd_uri_t root = {
//         .uri = "/",
//         .method = HTTP_GET,

//         .handler = root_get_handler,
//         .user_ctx = ctx};

//     if (httpd_start(&ctx->server, &config) == ESP_OK) {
//         httpd_register_uri_handler(ctx->server, &root);
//         httpd_uri_t callback = {
//             .uri = "/callback",
//             .method = HTTP_GET,
//             .handler = callback_handler,
//             .user_ctx = ctx};
//         httpd_register_uri_handler(ctx->server, &callback);
//         httpd_uri_t get = {
//             .uri = "/get",
//             .method = HTTP_GET,
//             .handler = get_handler,
//             .user_ctx = ctx};
//         httpd_register_uri_handler(ctx->server, &get);
//         if (ctx->debug_on) {
//             ESP_LOGI("SPOTIFY", "Server started");
//         }
//     } else {
//         if (ctx->debug_on) {
//             ESP_LOGE("SPOTIFY", "Failed to start server");
//         }
//     }
// }

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
            ESP_LOGI("SPOTIFY", "HTTPS server started");
        }
    } else {
        if (ctx->debug_on) {
            ESP_LOGE("SPOTIFY", "Failed to start HTTPS server: %s", esp_err_to_name(ret));
        }
    }
}

bool spotify_get_token(SpotifyContext *ctx) {
    char post_data[1024];
    snprintf(post_data, sizeof(post_data),
             "grant_type=refresh_token&refresh_token=%s",
             ctx->refresh_token);

    esp_http_client_config_t config = {
        .url = "https://accounts.spotify.com/api/token",
        .method = HTTP_METHOD_POST,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);

    char auth_header[262];

    char auth_str[256];
    char auth_encoded[256];
    snprintf(auth_str, sizeof(auth_str), "%s:%s", ctx->client_id, ctx->client_secret);
    mbedtls_base64_encode((unsigned char *)auth_encoded, sizeof(auth_encoded), NULL, (const unsigned char *)auth_str, strlen(auth_str));

    snprintf(auth_header, sizeof(auth_header), "Basic %s", auth_encoded);

    esp_http_client_set_header(client, "Authorization", auth_header);
    esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
    esp_http_client_set_post_field(client, post_data, strlen(post_data));

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        char *resp_body = malloc(esp_http_client_get_content_length(client) + 1);
        esp_http_client_read(client, resp_body, esp_http_client_get_content_length(client));
        resp_body[esp_http_client_get_content_length(client)] = 0;

        cJSON *json = cJSON_Parse(resp_body);
        const cJSON *access_token = cJSON_GetObjectItem(json, "access_token");
        if (access_token && access_token->valuestring) {
            strncpy(ctx->access_token, access_token->valuestring, sizeof(ctx->access_token));
            free(resp_body);
            cJSON_Delete(json);
            esp_http_client_cleanup(client);
            return true;
        }

        free(resp_body);
        cJSON_Delete(json);
    }
    esp_http_client_cleanup(client);
    return false;
}

void spotify_task(void *pvParameters) {
    // Wait for WiFi to connect
    while (wifi_connected == 0) {
        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second delay
    }

    // Get access token
    get_access_token(&g_spotify_ctx);

    vTaskDelete(NULL);
}
