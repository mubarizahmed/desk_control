/**
 * @file calendar_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Calendar service for fetching calendar data from a google script URL.
 * @version 0.1
 * @date 2025-04-13
 *
 */

#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_log.h"

#include "display_manager.h"
#include "ui.h"
#include "weather_serv.h"
#include "wifi_manager.h"

static const char *TAG = "CALENDAR_SERV";

/**
 * @brief Event handler for HTTP client events. Logs the event details and handles specific events.
 *
 *
 * @param evt  	Pointer to the HTTP client event data
 * @return 		ESP_OK on success, or an error code on failure
 */
esp_err_t calendar_event_handler(esp_http_client_event_t *evt) {
    switch (evt->event_id) {
    case HTTP_EVENT_ERROR:
        ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key,
                 evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA: {
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);

        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA: length of data: %d", evt->data_len);
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA: \n %.*s\n", evt->data_len, (char *)evt->data);

        // check if the data is not null and length is 38
        if (evt->data == NULL || evt->data_len != 44) {
            ESP_LOGE(TAG, "Wrong or null data");
            // return ESP_FAIL;
            return ESP_OK;
        }

        _lock_acquire(&lvgl_api_lock);
        setCalendarData((char *)evt->data);
        _lock_release(&lvgl_api_lock);

        break;
    }
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");

        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");

        break;
    case HTTP_EVENT_REDIRECT:
        ESP_LOGI(TAG, "HTTP_EVENT_REDIRECT");
        break;
    }
    return ESP_OK;
}

void getCalendar(esp_http_client_config_t config_get) {
    if (!wifi_connected) {
        ESP_LOGI(TAG, "WiFi not connected, skipping calendar data fetch.");
    } else {
        ESP_LOGI(TAG, "WiFi connected, fetching calendar data.");
        ESP_LOGI(TAG, "Getting calendar data...");

        esp_http_client_handle_t client = esp_http_client_init(&config_get);
        esp_err_t err = esp_http_client_perform(client);

        if (err == ESP_OK) {
            ESP_LOGI(TAG, "HTTP Status = %d, content_length = %lld",
                     esp_http_client_get_status_code(client),
                     esp_http_client_get_content_length(client));
        } else {
            ESP_LOGE(TAG, "HTTP GET failed: %s", esp_err_to_name(err));
        }

        esp_http_client_cleanup(client);
    }
}

/**
 * @brief Task to fetch calendar data from a Google script URL every 30 seconds.
 *
 *
 * @param pvParameters Pointer to task parameters (not used)
 */
void calendar_task(void *pvParameters) {
    esp_http_client_config_t config_get = {
        .url = "https://script.google.com/macros/s/AKfycbwkRlW15diVjtrKa3EpTrraQro8Sh3GGSQWKkxO9uECdRV11wfLrzwJJHzL9exkFEzhyA/exec",
        .method = HTTP_METHOD_GET,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .event_handler = calendar_event_handler};

    while (1) {
        getCalendar(config_get);
        ESP_LOGI(TAG, "Free heap: %ld", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(30000));
    }
}