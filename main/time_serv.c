/**
 * @file TIME_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Time service for getting current time.
 * @version 0.1
 * @date 2025-04-09
 *
 */

#include "esp_err.h"
#include "esp_log.h"
#include "esp_sntp.h"
// #include "esp_netif.h"
#include "esp_netif_sntp.h"

#include "app_events.h"
#include "display_manager.h"
#include "time_serv.h"
#include "ui.h"
#include "wifi_manager.h"

static const char *TAG = "TIME_SERV";

static bool time_synced = false;

void time_task(void *pvParameters) {

    time_t now;
    struct tm timeinfo;
    char strftime_buf[64];

    while (1) {
        if (wifi_connected && !time_synced) {
            // Configure SNTP
            esp_sntp_config_t config = ESP_NETIF_SNTP_DEFAULT_CONFIG("pool.ntp.org");
            esp_netif_sntp_init(&config);
            esp_netif_sntp_start();

            // Wait for synchronization
            int retry = 0;
            const int retry_count = 10;

            while (esp_netif_sntp_sync_wait(2000 / portTICK_PERIOD_MS) == ESP_ERR_TIMEOUT && ++retry < retry_count) {
                ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
            }

            if (retry < retry_count) {
                time_t now;
                struct tm timeinfo;
                char strftime_buf[64];

                time(&now);
                setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
                tzset();

                localtime_r(&now, &timeinfo);
                strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
                ESP_LOGI(TAG, "The current date/time in Bochum is: %s", strftime_buf);

                // get date in DAY DD.MM.YYYY format
                char date[20];
                strftime(date, sizeof(date), "❱ %a %d.%m.%Y", &timeinfo);

                ESP_LOGI(TAG, "The current date is: %s", date);

                _lock_acquire(&lvgl_api_lock);
                // Handle LVGL tasks and events
                setTime(timeinfo.tm_hour, timeinfo.tm_min, date);
                _lock_release(&lvgl_api_lock);

                // setTime(timeinfo.tm_hour, timeinfo.tm_min);
                xEventGroupSetBits(app_event_group, TIME_SET_EVENT);

                time_synced = true;
            } else {
                ESP_LOGW(TAG, "SNTP sync failed after %d retries.", retry_count);
            }

            // Deinit SNTP to free memory
            esp_netif_sntp_deinit();

            // log the memory usage
            size_t free_heap = esp_get_free_heap_size();
            ESP_LOGI("MEMORY", "time_task Free heap size: %d bytes", free_heap);

        } else if (time_synced) {

            time(&now);
            localtime_r(&now, &timeinfo);

            strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
            ESP_LOGI(TAG, "The current date/time in Bochum is: %s", strftime_buf);

            // get date in DAY DD.MM.YYYY format
            char date[20];
            strftime(date, sizeof(date), "❱ %a %d.%m.%Y", &timeinfo);

            ESP_LOGI(TAG, "The current date is: %s", date);

            _lock_acquire(&lvgl_api_lock);
            // Handle LVGL tasks and events
            setTime(timeinfo.tm_hour, timeinfo.tm_min, date);
            _lock_release(&lvgl_api_lock);

            // log the memory usage
            size_t free_heap = esp_get_free_heap_size();
            ESP_LOGI(TAG, "Free heap size: %d bytes", free_heap);
        }

        vTaskDelay(pdMS_TO_TICKS(30000));
    }
}