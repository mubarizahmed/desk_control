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
#include "mbedtls/platform.h"
#include "nvs_flash.h"
#include <stdio.h>
#include <sys/lock.h>
#include <sys/param.h>
#include <unistd.h>

#include "app_events.h"
#include "calendar_serv.h"
#include "display_manager.h"
#include "esp_event.h"
#include "pin_definitions.h"
#include "pomodoro.h"
#include "spotify_serv.h"
#include "time_serv.h"
#include "todoist_serv.h"
#include "ui.h"
#include "weather_serv.h"
#include "wifi_manager.h"

static const char *TAG = "MAIN";

/**
 * @brief Main application entry point.
 *
 */
void app_main(void) {

    app_events_init();
    spotify_event_group = xEventGroupCreate();

    // Initialize Display and LVGL
    display_manager_init();

    // Initialize NVS
    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOGE(TAG, "NVS flash init failed: %s", esp_err_to_name(ret));
        ESP_LOGI(TAG, "Erasing NVS flash and reinitializing");
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // check if NVS is initialized
    nvs_handle_t my_handle;
    ret = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (ret != ESP_OK) {
        printf("Error (%s) opening NVS handle!\n", esp_err_to_name(ret));
        ESP_ERROR_CHECK(ret);
    }
    ESP_LOGI(TAG, "NVS handle opened successfully");
    nvs_close(my_handle);



    // esp_log_level_set("wifi", ESP_LOG_VERBOSE);

    esp_log_level_set("MEMORY", ESP_LOG_VERBOSE);
    esp_log_level_set("STACK", ESP_LOG_VERBOSE);

    wifi_init_sta();

    while (1) {
        // Wait for WiFi to connect
        if (wifi_connected == 1) {
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second delay
    }

    // create new task for pomodoro
    xTaskCreate(&pomodoro_task, "pomodoro_task", 1024 * 1, NULL, 4, NULL);

    // create task to get time and keep widget updated
    xTaskCreate(&time_task, "time_task", 1024 * 5, NULL, 3, NULL);

    EventBits_t uxBits = xEventGroupWaitBits(
        app_event_group,
        TIME_SET_EVENT,
        pdTRUE,       // Clear the bits before returning
        pdFALSE,      // Wait for any bit to be set
        portMAX_DELAY // Wait indefinitely
    );

    // create new task to fetch data
    xTaskCreate(&weather_task, "weather_task", 1024 * 10, NULL, 2, NULL);

    uxBits = xEventGroupWaitBits(
        app_event_group,
        WEATHER_SET_EVENT,
        pdTRUE,       // Clear the bits before returning
        pdFALSE,      // Wait for any bit to be set
        portMAX_DELAY // Wait indefinitely
    );

    // create new task for calendar
    xTaskCreate(&calendar_task, "calendar_task", 1024 * 10, NULL, 2, NULL);

    uxBits = xEventGroupWaitBits(
        app_event_group,
        CALENDAR_SET_EVENT,
        pdTRUE,       // Clear the bits before returning
        pdFALSE,      // Wait for any bit to be set
        portMAX_DELAY // Wait indefinitely
    );

    // esp_log_level_set("TODOIST_SERV", ESP_LOG_INFO); // Set log level to INFO for all components

    xTaskCreate(&todoist_task, "todoist_task", 1024 * 25, NULL, 3, NULL);

    uxBits = xEventGroupWaitBits(
        app_event_group,
        TODOIST_SET_EVENT,
        pdTRUE,       // Clear the bits before returning
        pdFALSE,      // Wait for any bit to be set
        portMAX_DELAY // Wait indefinitely
    );

    xTaskCreate(&spotify_task, "spotify_task", 1024 * 20, NULL, 3, NULL);

    while (1) {
        // print heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGI(TAG, "Main heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

        vTaskDelay(pdMS_TO_TICKS(30000)); // 1 minutes delay
    }
// #define DEBUG 1
#ifdef DEBUG_MAIN
    while (1) {

        // print system state every second
        TaskStatus_t *task_status_array = NULL;
        UBaseType_t task_count = uxTaskGetNumberOfTasks();
        task_status_array = (TaskStatus_t *)malloc(task_count * sizeof(TaskStatus_t));
        if (task_status_array == NULL) {
            ESP_LOGE(TAG, "Failed to allocate memory for task status array");
            continue;
        }
        UBaseType_t task_count_filled = uxTaskGetSystemState(task_status_array, task_count, NULL);
        for (UBaseType_t i = 0; i < task_count_filled; i++) {
            ESP_LOGI(TAG, "Task: %s, State: %d, Priority: %d , HighWatermark: %ld", task_status_array[i].pcTaskName,
                     task_status_array[i].eCurrentState, task_status_array[i].uxCurrentPriority, task_status_array[i].usStackHighWaterMark);
        }
        free(task_status_array);

        // print heap information
        size_t free_heap = esp_get_free_heap_size();
        size_t min_free_heap = esp_get_minimum_free_heap_size();
        ESP_LOGI(TAG, "Main heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

        vTaskDelay(pdMS_TO_TICKS(60000)); // 1 minutes delay
    }
#endif
}
