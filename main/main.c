/**
 * @file main.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Application entry point.
 * @version 0.1
 * @date 2025-04-09
 *
 */

#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include <stdio.h>
#include <sys/lock.h>
#include <sys/param.h>
#include <unistd.h>

#include "display_manager.h"
#include "esp_event.h"
#include "pin_definitions.h"
#include "ui.h"
#include "weather_serv.h"
#include "wifi_manager.h"
#include "time_serv.h"

static const char *TAG = "MAIN";

/**
 * @brief Main application entry point.
 *
 */
void app_main(void) {
    // Initialize Display and LVGL
    display_manager_init();

    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Initialize WiFi
    if (CONFIG_LOG_MAXIMUM_LEVEL > CONFIG_LOG_DEFAULT_LEVEL) {
        /* If you only want to open more logs in the wifi module, you need to make the max level greater than the default level,
         * and call esp_log_level_set() before esp_wifi_init() to improve the log level of the wifi module. */
        esp_log_level_set("wifi", CONFIG_LOG_MAXIMUM_LEVEL);
    }
    wifi_init_sta();

    // create task to get time and keep widget updated
    xTaskCreate(&time_task, "time_task", 1024*4, NULL, 3, NULL);

    // create new task to fetch data
    xTaskCreate(&weather_task, "weather_task", 1024 * 10, NULL, 2, NULL);
}
