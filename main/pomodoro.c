/**
 * @file pomodoro.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Pomodoro timer implementation.
 * @version 0.1
 * @date 2025-04-11
 *
 */

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include <time.h>

#include "display_manager.h"
#include "ui.h"

#include "pomodoro.h"

/* ------------------------------------------------------ */
/*                    PRIVATE VARIABLES                   */
/* ------------------------------------------------------ */
static const char *TAG = "POMODORO";

static bool pomodoro_running = false;
static int pomodoro_duration = 0; // in minutes
static time_t start_time;

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */

/**
 * @brief Task to handle the Pomodoro timer.
 *
 * @param pvParameters - Pointer to task parameters (not used).
 */
void pomodoro_task(void *pvParameters) {

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(30000));

        if (pomodoro_running) {

            time_t now;

            time(&now);

            // minus the start time from the current time to get the elapsed time
            double elapsed_time = difftime(now, start_time) / 60; // in minutes
            double remaining_time = pomodoro_duration - elapsed_time;
            int remaining = (int)remaining_time;

            if (remaining < 0) {
                // Timer is up, flash the screen and play a sound
                ESP_LOGI(TAG, "Pomodoro time is up!");

                _lock_acquire(&lvgl_api_lock);
                // Handle LVGL tasks and events
                setPomodoro("TIME'S UP!");
                _lock_release(&lvgl_api_lock);

                while (pomodoro_running) {
                    // Flash the screen
                    _lock_acquire(&lvgl_api_lock);
                    flashPomodoroOverlay(true);
                    _lock_release(&lvgl_api_lock);
                    vTaskDelay(pdMS_TO_TICKS(500));
                    _lock_acquire(&lvgl_api_lock);
                    flashPomodoroOverlay(false);
                    _lock_release(&lvgl_api_lock);
                    vTaskDelay(pdMS_TO_TICKS(500));
                }

                // Play sound

                // Stop the timer
                pomodoro_running = false;
            } else {
                ESP_LOGI(TAG, "Remaining time: %.2f minutes", remaining_time);

                // int to char* conversion
                char pomodoro_time[8];
                pomodoro_time[0] = '0' + (remaining / 10); // Tens digit
                pomodoro_time[1] = '0' + (remaining % 10); // Units digit
                pomodoro_time[2] = ' ';
                pomodoro_time[3] = 'm';  // Minutes
                pomodoro_time[4] = 'i';  // Minutes
                pomodoro_time[5] = 'n';  // Minutes
                pomodoro_time[6] = 's';  // Minutes
                pomodoro_time[7] = '\0'; // Null terminator               // Null terminator

                // Update the GUI with the remaining time
                _lock_acquire(&lvgl_api_lock);
                setPomodoro(pomodoro_time);
                _lock_release(&lvgl_api_lock);
            }
        }
    }
}

/**
 * @brief Start the Pomodoro timer.
 *
 * @param min - Duration in minutes.
 */
void startPomodoro(int min) {
    pomodoro_duration = min;
    start_time = time(NULL);
    pomodoro_running = true;
    ESP_LOGI(TAG, "Pomodoro time set to %d minutes", pomodoro_duration);
}

/**
 * @brief Stop the Pomodoro timer.
 */
void stopPomodoro() {
    pomodoro_running = false;
    ESP_LOGI(TAG, "Pomodoro timer stopped");
}