/**
 * @file spotify_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Spotify service for handling Spotify authentication and token management.
 * @version 0.1
 * @date 2025-04-17
 *
 */

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */
#include "cJSON.h"
#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_https_server.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "jpeg_decoder.h"
#include "mbedtls/base64.h"
#include "nvs_flash.h"
#include "string.h"
#include <sys/param.h>

#include "display_manager.h"
#include "secret_conf.h"
#include "spotify_serv.h"
#include "spotify_web.h"
#include "ui.h"
#include "wifi_manager.h"

/* ------------------------------------------------------ */
/*                     CONFIG MACROS                      */
/* ------------------------------------------------------ */
#define MAX_HTTP_OUTPUT_BUFFER 4024

/* ------------------------------------------------------ */
/*                    PRIVATE VARIABLES                   */
/* ------------------------------------------------------ */
static const char *TAG = "SPOTIFY_SERV";

static char response_buffer[MAX_HTTP_OUTPUT_BUFFER];

EventGroupHandle_t spotify_event_group;

SpotifyContext g_spotify_ctx = {
    .client_id = SPOTIFY_CLIENT_ID,
    .client_secret = SPOTIFY_CLIENT_SECRET,
    .refresh_token = SPOTIFY_REFRESH_TOKEN,
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

/* ------------------------------------------------------ */
/*              PRIVATE FUNCTION DECLARATIONS             */
/* ------------------------------------------------------ */
/* ------------------- Authentication ------------------- */
bool sp_is_authorized(const SpotifyContext *ctx);
bool sp_has_refresh_token(const SpotifyContext *ctx);
bool sp_exchange_code_refresh_token(const char *auth_code, const char *redirect_uri);
bool sp_fetch_access_token(SpotifyContext *ctx);
void sp_get_auth(SpotifyContext *ctx);
/* ---------------------- Webserver --------------------- */
esp_err_t sp_handle_root_get(httpd_req_t *req);
esp_err_t sp_handle_callback(httpd_req_t *req);
esp_err_t sp_handle_get(httpd_req_t *req);
esp_err_t sp_start_webserver(SpotifyContext *ctx);
/* -------------------- Playback API -------------------- */
esp_err_t sp_get_current_playback(SpotifyContext *ctx, CurrentlyPlayingData *data);
void sp_get_image(const char *url, char *out_buffer, size_t buffer_size, int64_t *out_image_size);
void sp_update_current_playback(SpotifyContext *ctx, int32_t *out_delay_ms);
esp_err_t sp_next_track();
esp_err_t sp_previous_track();
esp_err_t sp_resume_track();
esp_err_t sp_pause_track();
/* ----------------------- Utility ---------------------- */
esp_err_t sp_http_event_handler(esp_http_client_event_t *evt);

/* ------------------------------------------------------ */
/*                    PRIVATE FUNCTIONS                   */
/* ------------------------------------------------------ */
/* ------------------- Authentication ------------------- */
/**
 * @brief Check if the access token, client_id, client_secret, and refresh_token are set.
 *
 *
 * @param ctx - SpotifyContext pointer
 * @return true - if all tokens are set
 */
bool sp_is_authorized(const SpotifyContext *ctx) {
    return !(strcmp(ctx->refresh_token, "") == 0 || strcmp(ctx->client_id, "") == 0 || strcmp(ctx->client_secret, "") == 0 || strcmp(ctx->access_token, "") == 0);
}

/**
 * @brief Check if the refresh token, client_id and client_secret are set.
 *
 *
 * @param ctx - SpotifyContext pointer
 * @return true - if all tokens are set
 */
bool sp_has_refresh_token(const SpotifyContext *ctx) {
    return !(strcmp(ctx->refresh_token, "") == 0 || strcmp(ctx->client_id, "") == 0 || strcmp(ctx->client_secret, "") == 0);
}

/**
 * @brief Exchange authorization code for refresh token and access token.
 *
 * @param auth_code - Authorization code received from Spotify
 * @param redirect_uri - Redirect URI used in the authorization request
 * @return true if the exchange was successful, false otherwise
 */
bool sp_exchange_code_refresh_token(const char *auth_code, const char *redirect_uri) {
    char post_data[512];

    // Construct POST data
    snprintf(post_data, sizeof(post_data),
             "grant_type=authorization_code&code=%s&redirect_uri=%s&client_id=%s&client_secret=%s",
             auth_code, redirect_uri, g_spotify_ctx.client_id, g_spotify_ctx.client_secret);

    ESP_LOGD(TAG, "Refresh token POST data: %s", post_data);

    // Clear the buffer before request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_config_t config = {
        .url = "https://accounts.spotify.com/api/token",
        .method = HTTP_METHOD_POST,
        .timeout_ms = 5000,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
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

    ESP_LOGD(TAG, "Response: >>>%s<<<", response_buffer);

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

        ESP_LOGD(TAG, "Access Token: %s", g_spotify_ctx.access_token);
        ESP_LOGD(TAG, "Refresh Token: %s", g_spotify_ctx.refresh_token);
        ESP_LOGD(TAG, "Refresh Token Length: %zu", strlen(g_spotify_ctx.refresh_token));

        // Save the refresh token to NVS
        nvs_handle_t nvs_handle;
        esp_err_t err = nvs_open("storage", NVS_READWRITE, &nvs_handle);
        if (err == ESP_OK) {

            err = nvs_set_u16(nvs_handle, "sp_rt_size", (uint16_t)strlen(g_spotify_ctx.refresh_token));
            if (err != ESP_OK) {
                ESP_LOGE(TAG, "Failed to set refresh token size: %s", esp_err_to_name(err));
            }

            err = nvs_set_str(nvs_handle, "sp_rt", g_spotify_ctx.refresh_token);
            if (err != ESP_OK) {
                ESP_LOGE(TAG, "Failed to set refresh token string: %s", esp_err_to_name(err));
            }
            esp_err_t err_commit = nvs_commit(nvs_handle);
            if (err_commit != ESP_OK) {
                // Crahes app??
                // ESP_LOGE(TAG, "Failed to commit NVS: %s", esp_err_to_name(err_commit));
            } else {
                ESP_LOGD(TAG, "Refresh token committed to NVS");
            }
            nvs_close(nvs_handle);
            ESP_LOGI(TAG, "NVS handle closed successfully");
        } else {
            ESP_LOGE(TAG, "Failed to open NVS handle: %s", esp_err_to_name(err));
        }

        // read the refresh token from NVS
        // load from nvs
        nvs_handle_t handle;
        err = nvs_open("storage", NVS_READONLY, &handle);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Error (%s) opening NVS handle!", esp_err_to_name(err));
            // return;
        }
        uint16_t required_size = 0;
        err = nvs_get_u16(handle, "sp_rt_size", &required_size);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Error (%s) getting refresh token size!", esp_err_to_name(err));
            nvs_close(handle);
            // return;
        }
        ESP_LOGD(TAG, "Refresh token size: %d", required_size);
        nvs_close(handle);

        cJSON_Delete(root);
        esp_http_client_cleanup(client);

        // print heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGD("MEMORY", "sp_exchange_code_refresh_token heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

        return true;
    } else {
        ESP_LOGW("SPOTIFY", "No refresh token in response");
    }

    cJSON_Delete(root);
    esp_http_client_cleanup(client);
    return false;
}

/**
 * @brief Fetch access token using refresh token.
 *
 * @param ctx - SpotifyContext pointer
 * @return true if the access token was fetched successfully, false otherwise
 */
bool sp_fetch_access_token(SpotifyContext *ctx) {
    if (!sp_has_refresh_token(ctx)) {
        ESP_LOGE("SPOTIFY", "No refresh token available");
        return false;
    }

    char post_data[512];
    snprintf(post_data, sizeof(post_data),
             "grant_type=refresh_token&refresh_token=%s",
             ctx->refresh_token);

    ESP_LOGD(TAG, "Get access token POST data: %s", post_data);

    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_config_t config = {
        .url = "https://accounts.spotify.com/api/token",
        .method = HTTP_METHOD_POST,
        .timeout_ms = 5000,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
    };

    esp_http_client_handle_t client = esp_http_client_init(&config);
    if (!client) {
        ESP_LOGE("SPOTIFY", "Failed to initialize HTTP client");
        return false;
    }

    char to_encode[205];
    snprintf(to_encode, sizeof(to_encode), "%s:%s", ctx->client_id, ctx->client_secret);

    // Calculate the output size needed for Base64 (Base64 expands by ~4/3)
    char encoded_auth[256]; // Ensure it's big enough for Base64
    size_t out_len = 0;

    int ret = mbedtls_base64_encode(
        (unsigned char *)encoded_auth, sizeof(encoded_auth), &out_len,
        (const unsigned char *)to_encode, strlen(to_encode));

    if (ret != 0) {
        ESP_LOGE(TAG, "Base64 encoding failed with error: %d", ret);
        return false;
    }

    encoded_auth[out_len] = '\0'; // Null-terminate the string
    char auth_header[300];
    snprintf(auth_header, sizeof(auth_header), "Basic %s", encoded_auth);

    ESP_LOGD(TAG, "Auth Header: %s", auth_header);

    esp_http_client_set_header(client, "Content-Type", "application/x-www-form-urlencoded");
    esp_http_client_set_header(client, "Authorization", auth_header);
    esp_http_client_set_post_field(client, post_data, strlen(post_data));

    esp_err_t err = esp_http_client_perform(client);
    if (err != ESP_OK) {
        ESP_LOGE("SPOTIFY", "HTTP request failed: %s", esp_err_to_name(err));
        esp_http_client_cleanup(client);
        return false;
    }

    ESP_LOGD(TAG, "Response: >>>%s<<<", response_buffer);

    cJSON *root = cJSON_Parse(response_buffer);
    if (!root) {
        ESP_LOGE("SPOTIFY", "Failed to parse JSON");
        esp_http_client_cleanup(client);
        return false;
    }

    bool success = false;
    cJSON *access_token = cJSON_GetObjectItem(root, "access_token");
    if (access_token && cJSON_IsString(access_token)) {
        strncpy(ctx->access_token, access_token->valuestring, sizeof(ctx->access_token) - 1);
        ctx->access_token[sizeof(ctx->access_token) - 1] = '\0';

        cJSON *refresh_token = cJSON_GetObjectItem(root, "refresh_token");
        if (refresh_token && cJSON_IsString(refresh_token)) {
            strncpy(ctx->refresh_token, refresh_token->valuestring, sizeof(ctx->refresh_token) - 1);
            ctx->refresh_token[sizeof(ctx->refresh_token) - 1] = '\0';
        }

        ESP_LOGD(TAG, "Access Token: %s", ctx->access_token);
        if (refresh_token && cJSON_IsString(refresh_token)) {
            ESP_LOGD(TAG, "Updated Refresh Token: %s", ctx->refresh_token);
        }

        success = true;
    } else {
        ESP_LOGW("SPOTIFY", "No access token in response");
    }

    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGD("MEMORY", "sp_fetch_access_token heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

    cJSON_Delete(root);
    esp_http_client_cleanup(client);
    return success;
}

/**
 * @brief Try to load refresh token from NVS is set, if not, start web server for authentication.
 *        Obtain access token using refresh token if available.
 *
 * @param ctx - SpotifyContext pointer
 */
void sp_get_auth(SpotifyContext *ctx) {
    // load from nvs
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READONLY, &handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error (%s) opening NVS handle!", esp_err_to_name(err));
    }
    uint16_t required_size = 0;
    err = nvs_get_u16(handle, "sp_rt_size", &required_size);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error (%s) getting refresh token size!", esp_err_to_name(err));
        nvs_close(handle);
    }
    ESP_LOGD(TAG, "Refresh token size: %d", required_size);
    if (required_size > 0) {
        size_t size = required_size + 1;
        ctx->refresh_token[0] = '\0';
        err = nvs_get_str(handle, "sp_rt", ctx->refresh_token, &size);
        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Error (%s) getting refresh token!", esp_err_to_name(err));
            nvs_close(handle);
            // return;
        }
        ESP_LOGD(TAG, "Refresh token: %s", ctx->refresh_token);
        nvs_close(handle);
    } else {
        ESP_LOGE(TAG, "No refresh token available!");
        nvs_close(handle);
        // return;
    }

    // check if refresh token is empty
    if (!sp_has_refresh_token(ctx)) {
        ESP_LOGE("SPOTIFY", "No refresh token available");

        // start web server for authentication
        if (!sp_is_authorized(ctx)) {
            if (ctx->port == 443) {
                char redirect_uri[40];

                snprintf(ctx->redirect_uri, sizeof(redirect_uri), "https://%d.%d.%d.%d/", IP2STR(&ip_addr));

                ESP_LOGD(TAG, "got ip:" IPSTR, IP2STR(&ip_addr));
                ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: %s\n", ctx->redirect_uri);
                // snprintf(redirect_uri, sizeof(redirect_uri), "http://"IPSTR"/", "got ip:" IPSTR, IP2STR();
                // ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: http://%s/\n", WiFi.localIP().toString().c_str());
            } else {
                // ESP_LOGI(TAG, "Go to this url in your Browser to login to spotify or enter your credentials: http://%s:%d/\n", WiFi.localIP().toString().c_str(), g_port);
            }
            // heap info
            size_t free_heap = esp_get_free_heap_size();
            size_t min_free_heap = esp_get_minimum_free_heap_size();
            ESP_LOGE("MEMORY", "Start webserver heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

            sp_start_webserver(ctx);
        }
    } else {
        ESP_LOGI(TAG, "Refresh token available, getting access token...");
        // Call the function to get the access token using the refresh token
        // This function should be implemented to make a request to Spotify API
        // and retrieve the access token.
        if (sp_fetch_access_token(ctx)) {
            ESP_LOGI(TAG, "Access token retrieved successfully");
            // Store the access token in ctx->access_token
            // ctx->access_token = ...;
        } else {
            ESP_LOGE(TAG, "Failed to retrieve access token");
        }
    }
}

/* ---------------------- Webserver --------------------- */

/**
 * @brief Handles the root GET request for the web server. Displays the login page.
 *
 * @param ctx - SpotifyContext pointer
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_handle_root_get(httpd_req_t *req) {
    char buf[100];
    size_t buf_len;

    buf_len = httpd_req_get_hdr_value_len(req, "User-Agent") + 1;
    ESP_LOGD(TAG, "User-Agent length: %d", buf_len);
    if (buf_len > 1) {
        httpd_req_get_hdr_value_str(req, "User-Agent", buf, sizeof(buf));
        ESP_LOGD(TAG, "User-Agent: %s", buf);
    }

    // Access context via `req->user_ctx`
    SpotifyContext *ctx = (SpotifyContext *)req->user_ctx;

    httpd_resp_set_type(req, "text/html");
    httpd_resp_send(req, credentials_input, HTTPD_RESP_USE_STRLEN);

    // print heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGD("MEMORY", "root_get_handler heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

    return ESP_OK;
}

/**
 * @brief Handles the callback request from Spotify after authentication.
 *        It processes the authorization code, retrieves the refresh token,
 *        and displays the setup completion message. It then stops the web server.
 *
 * @param req - Pointer to the HTTP request structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_handle_callback(httpd_req_t *req) {
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

        // Try to get the 'code' from query
        char code[256] = "";
        if (httpd_query_key_value(query, "code", code, sizeof(code)) == ESP_OK) {
            strncpy(ctx->auth_code, code, sizeof(ctx->auth_code));
            if (ctx->debug_on) {
                ESP_LOGD(TAG, "Auth Code: %s", ctx->auth_code);
            }

            // Get new refresh token from Spotify
            char redirect_uri_full[150];
            snprintf(redirect_uri_full, sizeof(redirect_uri_full), "%scallback", ctx->redirect_uri);

            if (sp_exchange_code_refresh_token(ctx->auth_code, redirect_uri_full)) {
                char message[500];
                snprintf(message, sizeof(message),
                         "Setup Complete, Refresh Token: %s <br>You can now close this page",
                         ctx->refresh_token);
                httpd_resp_set_type(req, "text/html");
                httpd_resp_sendstr(req, message);

                // heap info
                size_t free_heap = esp_get_free_heap_size();
                size_t min_free_heap = esp_get_minimum_free_heap_size();
                ESP_LOGE("MEMORY", "stop webserver heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
                httpd_stop(ctx->server);

            } else {
                httpd_resp_set_type(req, "text/html");
                httpd_resp_sendstr(req, "Something went wrong, please try again");
            }

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
        httpd_stop(ctx->server);
        return ESP_OK;
    }

    // print heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGD("MEMORY", "callback_handler heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
}

/**
 * @brief Handles the GET request for the /get endpoint.
 *        It processes the query parameters and sets the credentials
 *        input in the credentials page in the context.
 *
 * @param req - Pointer to the HTTP request structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_handle_get(httpd_req_t *req) {
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

/**
 * @brief Starts the web server for Spotify authentication.
 *
 * @param ctx - Pointer to the SpotifyContext structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_start_webserver(SpotifyContext *ctx) {
    esp_err_t ret = ESP_OK;
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

    ret = httpd_ssl_start(&ctx->server, &conf);
    if (ret == ESP_OK) {
        httpd_uri_t root = {
            .uri = "/",
            .method = HTTP_GET,
            .handler = sp_handle_root_get,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &root);

        httpd_uri_t callback = {
            .uri = "/callback",
            .method = HTTP_GET,
            .handler = sp_handle_callback,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &callback);

        httpd_uri_t get = {
            .uri = "/get",
            .method = HTTP_GET,
            .handler = sp_handle_get,
            .user_ctx = ctx};
        httpd_register_uri_handler(ctx->server, &get);

        ESP_LOGI(TAG, "HTTPS server started");
    } else {
        ESP_LOGE(TAG, "Failed to start HTTPS server: %s", esp_err_to_name(ret));
    }
    return ret;
}

/* -------------------- Playback API -------------------- */
/**
 * @brief Get the current playback information from Spotify.
 *
 * @param ctx - Pointer to the SpotifyContext structure
 * @param data - Pointer to the CurrentlyPlayingData structure to store playback information
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_get_current_playback(SpotifyContext *ctx, CurrentlyPlayingData *data) {
    esp_err_t ret = ESP_OK;

    ESP_LOGI(TAG, "Getting current playback");

    esp_http_client_config_t config = {
        .url = "https://api.spotify.com/v1/me/player/currently-playing?market=DE",
        .method = HTTP_METHOD_GET,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_handle_t client = esp_http_client_init(&config);

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", ctx->access_token);
    ret = esp_http_client_set_header(client, "Authorization", auth_header);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(ret));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 200) {
            ESP_LOGD(TAG, "Current playback: %s", response_buffer);
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

                                ESP_LOGD(TAG, "Images in the response %d", artist_count);

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
            goto cleanup;
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
        ESP_LOGE(TAG, "Response: %s", response_buffer);
        goto cleanup;
    }

cleanup:
    // heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGD("MEMORY", "sp_get_current_playback heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

    esp_http_client_cleanup(client);
    return ret;
}

/**
 * @brief Get the image from the given URL and store it in the provided buffer.
 *
 * @param url - URL of the image to fetch
 * @param out_buffer - Buffer to store the image data
 * @param buffer_size - Size of the image buffer
 * @param out_image_size - Pointer to store the size of the fetched image
 */
void sp_get_image(const char *url, char *out_buffer, size_t buffer_size, int64_t *out_image_size) {
    esp_http_client_config_t config = {
        .url = url,
        .method = HTTP_METHOD_GET,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = out_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before request
    memset(out_buffer, 0, buffer_size);

    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 200) {

            *out_image_size = esp_http_client_get_content_length(client);
            ESP_LOGD(TAG, "Received image data (%lld bytes)", esp_http_client_get_content_length(client));
            ESP_LOG_BUFFER_HEXDUMP(TAG, out_buffer, 32, ESP_LOG_DEBUG); // Log first 32 bytes for debugging

        } else {
            ESP_LOGE(TAG, "Error: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
}

/**
 * @brief Obtain the current playback information and album image and
 *        update the UI with the data.
 *
 * @param ctx - Pointer to the SpotifyContext structure
 * @param out_delay_ms - Pointer to store the delay for the next update
 */
void sp_update_current_playback(SpotifyContext *ctx, int32_t *out_delay_ms) {
    CurrentlyPlayingData *data = (CurrentlyPlayingData *)malloc(sizeof(CurrentlyPlayingData));

    if (data == NULL) {
        ESP_LOGE(TAG, "Failed to allocate memory for CurrentlyPlayingData");
        vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
        free(data);
        return;
    }
    memset(data, 0, sizeof(CurrentlyPlayingData));

    if (sp_is_authorized(&g_spotify_ctx)) {

        sp_get_current_playback(&g_spotify_ctx, data);

        ESP_LOGD(TAG, "Currently playing: %s by %s", data->name, data->artists);
        ESP_LOGD(TAG, "Duration: %ld ms, Progress: %ld ms", data->duration_ms, data->progress_ms);
        ESP_LOGD(TAG, "Album: %s", data->album_name);
        ESP_LOGD(TAG, "Album Image URL: %s", data->album_image_url);
        ESP_LOGD(TAG, "Is Playing: %s", data->is_playing ? "true" : "false");

        *out_delay_ms = data->duration_ms - data->progress_ms + 5000; // Set delay to the remaining duration of the track
    }

    if (data->name[0] != '\0') {

        char name[18];
        char artists[20];

        if (strlen(data->name) > 17) {
            strncpy(name, data->name, 15);
            name[15] = '.';  // Add ellipsis
            name[16] = '.';  // Add ellipsis
            name[17] = '\0'; // Ensure null-termination
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

        // get image 64x64
        char *image_buffer = (char *)malloc(4096); // Adjust size as needed
        if (image_buffer == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory for image buffer");
            free(data);                       // Free the allocated memory for CurrentlyPlayingData
            vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
            return;
        }
        char *out_img_buf = (char *)malloc(64 * 64 * sizeof(uint16_t)); // Adjust size as needed
        if (out_img_buf == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory for output image buffer");
            free(image_buffer);               // Free the image buffer
            free(data);                       // Free the allocated memory for CurrentlyPlayingData
            vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
            return;
        }

        int64_t image_size = 0;

        // heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGD("MEMORY", "sp_get_image init heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

        sp_get_image(data->album_image_url, image_buffer, 4096, &image_size);

        esp_jpeg_image_cfg_t jpeg_cfg = {
            .indata = (uint8_t *)image_buffer,
            .indata_size = (uint32_t)image_size,
            .outbuf = (uint8_t *)out_img_buf,
            .outbuf_size = 64 * 64 * sizeof(uint16_t),
            .out_format = JPEG_IMAGE_FORMAT_RGB565,
            .out_scale = JPEG_IMAGE_SCALE_0,
            .flags = {
                // .swap_color_bytes = 1,
            }};
        esp_jpeg_image_output_t outimg;

        err_t res;
        res = esp_jpeg_decode(&jpeg_cfg, &outimg);
        if (res != ESP_OK) {
            ESP_LOGE(TAG, "JPEG decode failed: %s", esp_err_to_name(res));

            setSpotifyTextData(name, artists, data->is_playing); // Set text data without image

            free(image_buffer);               // Free the image buffer
            free(out_img_buf);                // Free the output image buffer
            free(data);                       // Free the allocated memory for CurrentlyPlayingData
            vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
            return;
        }
        ESP_LOGD(TAG, "JPEG decode done");
        ESP_LOG_BUFFER_HEXDUMP(TAG, out_img_buf, 32, ESP_LOG_DEBUG);
        ESP_LOGD(TAG, "JPEG decode size %d x %d", outimg.width, outimg.height);

        free(image_buffer); // Free the image buffer after use

        _lock_acquire(&lvgl_api_lock);
        setSpotifyData(name, artists, out_img_buf, data->is_playing);

        _lock_release(&lvgl_api_lock);
        free(out_img_buf); // Free the output image buffer after use
    }
    free(data);
}

/**
 * @brief Send a command to Spotify to play the next track.
 *
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_next_track() {
    esp_err_t ret = ESP_FAIL;
    esp_http_client_handle_t client = NULL;

    esp_http_client_config_t config = {
        .url = "https://api.spotify.com/v1/me/player/next",
        .method = HTTP_METHOD_POST,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before the request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialize HTTP client");
        return ESP_FAIL;
    }

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", g_spotify_ctx.access_token);
    esp_err_t header_err = esp_http_client_set_header(client, "Authorization", auth_header);
    if (header_err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(header_err));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 204 || status == 200) {
            ESP_LOGI(TAG, "Next command sent successfully");
            int32_t delay = 30000; // Default delay of 30 seconds
            sp_update_current_playback(&g_spotify_ctx, &delay);
            ret = ESP_OK;
        } else {
            ESP_LOGE(TAG, "Unexpected status code: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

cleanup:
    if (client != NULL) {
        esp_http_client_cleanup(client);
    }
    return ret;
}

/**
 * @brief Send a command to Spotify to play the previous track.
 *
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_previous_track() {
    esp_err_t ret = ESP_FAIL;
    esp_http_client_handle_t client = NULL;

    esp_http_client_config_t config = {
        .url = "https://api.spotify.com/v1/me/player/previous",
        .method = HTTP_METHOD_POST,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before the request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialize HTTP client");
        return ESP_FAIL;
    }

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", g_spotify_ctx.access_token);
    esp_err_t header_err = esp_http_client_set_header(client, "Authorization", auth_header);
    if (header_err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(header_err));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 204 || status == 200) {
            ESP_LOGI(TAG, "Previous command sent successfully");
            int32_t delay = 30000; // Default delay of 30 seconds
            sp_update_current_playback(&g_spotify_ctx, &delay);
            ret = ESP_OK;
        } else {
            ESP_LOGE(TAG, "Unexpected status code: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

cleanup:
    if (client != NULL) {
        esp_http_client_cleanup(client);
    }
    return ret;
}

/**
 * @brief Send a command to Spotify to pause the current track.
 *
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_pause_track() {
    esp_err_t ret = ESP_FAIL;
    esp_http_client_handle_t client = NULL;

    esp_http_client_config_t config = {
        .url = "https://api.spotify.com/v1/me/player/pause",
        .method = HTTP_METHOD_PUT,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before the request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialize HTTP client");
        return ESP_FAIL;
    }

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", g_spotify_ctx.access_token);
    esp_err_t header_err = esp_http_client_set_header(client, "Authorization", auth_header);
    if (header_err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(header_err));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 204 || status == 200) {
            ESP_LOGI(TAG, "Pause command sent successfully");
            int32_t delay = 30000; // Default delay of 30 seconds
            sp_update_current_playback(&g_spotify_ctx, &delay);
            ret = ESP_OK;
        } else {
            ESP_LOGE(TAG, "Unexpected status code: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

cleanup:
    if (client != NULL) {
        esp_http_client_cleanup(client);
    }
    return ret;
}

/**
 * @brief Send a command to Spotify to resume playback.
 *
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_resume_track() {
    esp_err_t ret = ESP_FAIL;
    esp_http_client_handle_t client = NULL;

    char root_url[45] = "https://api.spotify.com/v1/me/player/";
    char play_url[5];
    snprintf(play_url, sizeof(play_url), "play");
    strncat(root_url, play_url, sizeof(root_url) - strlen(root_url) - 1);

    esp_http_client_config_t config = {
        // somehow crashes app with this URL??
        // .url = "https://api.spotify.com/v1/me/player/play",
        .url = root_url,
        .method = HTTP_METHOD_PUT,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .cert_pem = _spotify_root_ca,
        .event_handler = sp_http_event_handler,
        .user_data = response_buffer,
        .timeout_ms = 15000,
    };

    // Clear the buffer before the request
    memset(response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    client = esp_http_client_init(&config);
    if (client == NULL) {
        ESP_LOGE(TAG, "Failed to initialize HTTP client");
        return ESP_FAIL;
    }

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", g_spotify_ctx.access_token);
    esp_err_t header_err = esp_http_client_set_header(client, "Authorization", auth_header);
    if (header_err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(header_err));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    // Set Content-Type header
    if (esp_http_client_set_header(client, "Content-Type", "application/json") != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Content-Type header");
        goto cleanup;
    }
    static const char *body = "{\"position_ms\": 0}";

    // Set body
    if (esp_http_client_set_post_field(client, body, strlen(body)) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set POST body");
        goto cleanup;
    }

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        if (status == 204 || status == 200) {
            ESP_LOGI(TAG, "Pause command sent successfully");
            int32_t delay = 30000; // Default delay of 30 seconds
            sp_update_current_playback(&g_spotify_ctx, &delay);
            ret = ESP_OK;
        } else {
            ESP_LOGE(TAG, "Unexpected status code: %d", status);
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
    }

cleanup:
    if (client != NULL) {
        esp_http_client_cleanup(client);
    }
    return ret;
}

/* ----------------------- Utility ---------------------- */
/**
 * @brief HTTP event handler for handling HTTP events.
 *
 * @param evt - Pointer to the HTTP event structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t sp_http_event_handler(esp_http_client_event_t *evt) {
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

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */
/**
 * @brief Task to handle Spotify commands and update playback information.
 *
 * @param pvParameters - Pointer to task parameters (not used)
 */
void spotify_task(void *pvParameters) {
    // Wait for WiFi to connect
    while (wifi_connected == 0) {
        vTaskDelay(pdMS_TO_TICKS(10000)); // 1 second delay
    }

    // Get access token
    sp_get_auth(&g_spotify_ctx);
    int32_t delay = 30000; // Default delay of 30 seconds
    while (1) {
        if (spotify_event_group == NULL) {
            ESP_LOGE(TAG, "Spotify event group is NULL");
            vTaskDelay(pdMS_TO_TICKS(10000)); // 10 seconds delay
            continue;
        }
        EventBits_t uxBits = xEventGroupWaitBits(
            spotify_event_group,
            // SPOTIFY_CMD_RESUME | SPOTIFY_CMD_PAUSE | SPOTIFY_CMD_PREV |
            SPOTIFY_CMD_NEXT,
            pdTRUE,              // Clear the bits before returning
            pdFALSE,             // Wait for any bit to be set
            pdMS_TO_TICKS(delay) // Wait for the specified delay
        );

        if (uxBits & SPOTIFY_CMD_RESUME) {
            ESP_LOGD(TAG, "Resume command received");
            sp_pause_track();
            vTaskDelay(pdMS_TO_TICKS(5000)); // 5 second delay
        } else if (uxBits & SPOTIFY_CMD_PAUSE) {
            ESP_LOGD(TAG, "Pause command received");
            sp_pause_track();
            vTaskDelay(pdMS_TO_TICKS(5000)); // 5 second delay
        } else if (uxBits & SPOTIFY_CMD_PREV) {
            ESP_LOGD(TAG, "Previous command received");
            sp_previous_track();
            vTaskDelay(pdMS_TO_TICKS(5000)); // 5 second delay
        } else if (uxBits & SPOTIFY_CMD_NEXT) {
            ESP_LOGD(TAG, "Next command received");
            sp_next_track();
            vTaskDelay(pdMS_TO_TICKS(5000)); // 5 second delay
        }
        sp_update_current_playback(&g_spotify_ctx, &delay);

        // heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGD("MEMORY", "get_image init heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

        // task and heap information
        // size_t free_heap = esp_get_free_heap_size();
        // size_t min_free_heap = esp_get_minimum_free_heap_size();
        // ESP_LOGD(TAG, "spotify_task heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);
        // UBaseType_t high_water_mark = uxTaskGetStackHighWaterMark(NULL);
        // ESP_LOGD(TAG, "spotify_task high water mark: %d", high_water_mark);
    }
    vTaskDelete(NULL);
}
