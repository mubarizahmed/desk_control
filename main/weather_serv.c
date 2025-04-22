/**
 * @file weather_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Weather service for fetching weather data from wttr.in.
 * @version 0.1
 * @date 2025-04-09
 *
 */

#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_tls.h"
#include <sys/param.h>

#include "app_events.h"
#include "display_manager.h"
#include "ui.h"
#include "weather_serv.h"
#include "wifi_manager.h"
/* ------------------------------------------------------ */
/*                      CONFIG MACROS                     */
/* ------------------------------------------------------ */

#define WT_MAX_HTTP_OUTPUT_BUFFER 1024

/* ------------------------------------------------------ */
/*                    PRIVATE VARIABLES                   */
/* ------------------------------------------------------ */

static const char *TAG = "WEATHER_SERV";

static char wt_response_buffer[WT_MAX_HTTP_OUTPUT_BUFFER] = {0};

static bool weather_data_loaded = false;

/**
 * @brief HTTP event handler for handling HTTP events.
 *
 * @param evt - Pointer to the HTTP event structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t wt_http_event_handler(esp_http_client_event_t *evt) {
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
            memset(evt->user_data, 0, WT_MAX_HTTP_OUTPUT_BUFFER);
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
                copy_len = MIN(evt->data_len, (WT_MAX_HTTP_OUTPUT_BUFFER - output_len));
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
        } else {
            // If chunked response, we can directly print the data
            // ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA chunked: data: %.*s", evt->data_len, (char *)evt->data);
            int copy_len = 0;
            if (evt->user_data) {
                // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                copy_len = MIN(evt->data_len, (WT_MAX_HTTP_OUTPUT_BUFFER - output_len));
                if (copy_len) {
                    memcpy(evt->user_data + output_len, evt->data, copy_len);
                }
            }
            output_len += copy_len;
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        // ESP_LOGI(TAG, "Output buffer length: %d", strlen(output_buffer));
        if (output_buffer != NULL) {
            ESP_LOGI(TAG, "Output buffer: %s", output_buffer);

            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_DISCONNECTED");
        int mbedtls_err = 0;
        esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
        if (err != 0) {
            ESP_LOGW(TAG, "Last esp error code: 0x%x", err);
            ESP_LOGW(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
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

void getWeather(int *out_delay_ms) {
    esp_http_client_config_t config_get = {
        .url = "https://wttr.in/Bochum?format=%c_%l_%t_%w_%h_%m_%p",
        .method = HTTP_METHOD_GET,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .event_handler = wt_http_event_handler,
        .user_data = wt_response_buffer,
        .timeout_ms = 15000,
    };

    if (!wifi_connected) {
        ESP_LOGI(TAG, "WiFi not connected, skipping weather data fetch.");
    } else {
        ESP_LOGI(TAG, "WiFi connected, fetching weather data.");
        ESP_LOGI(TAG, "Getting weather data...");

        esp_http_client_handle_t client = esp_http_client_init(&config_get);
        esp_err_t err = esp_http_client_perform(client);

        if (err == ESP_OK) {
            ESP_LOGI(TAG, "HTTP Status = %d, content_length = %lld",
                     esp_http_client_get_status_code(client),
                     esp_http_client_get_content_length(client));
            ESP_LOGI(TAG, "Weather data: %s", wt_response_buffer);

            _lock_acquire(&lvgl_api_lock);
            setWeatherData(wt_response_buffer);
            _lock_release(&lvgl_api_lock);

            *out_delay_ms = 2000; // Set delay to 2 seconds after data is loaded
            weather_data_loaded = true;
        } else {
            ESP_LOGE(TAG, "HTTP GET failed: %s", esp_err_to_name(err));
        }

        esp_http_client_cleanup(client);
    }
}

/**
 * @brief Task to fetch weather data from wttr.in every 30 seconds.
 *
 *
 * @param pvParameters Pointer to task parameters (not used)
 */
void weather_task(void *pvParameters) {
    int delay = 30000; // 30 seconds delay
    while (weather_data_loaded == false) {
        getWeather(&delay);
        ESP_LOGI("MEMORY", "weather_task Free heap: %ld", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
    ESP_LOGI(TAG, "Weather data loaded, exiting weather task.");

    xEventGroupSetBits(app_event_group, WEATHER_SET_EVENT);

    vTaskDelete(NULL);
}