/**
 * @file display_manager.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - Display manager for initializing and managing the display, touch controller and LVGL.
 * @version 0.1
 * @date 2025-04-09
 *
 */

#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

/*
 * PUBLIC MACROS
 */

#define LCD_HOST SPI2_HOST // SPI2_HOST - HSPI

#define LCD_PIXEL_CLOCK_HZ (20 * 1000 * 1000)         // 20 MHz
#define LCD_BK_LIGHT_ON_LEVEL 1                       // Backlight on level -> GPIO high
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL // Backlight off level -> GPIO low

#define LCD_H_RES 320 // 320 pixels in horizontal direction
#define LCD_V_RES 240 // 240 pixels in vertical direction

#define LCD_CMD_BITS 8   // 8 bits for LCD command
#define LCD_PARAM_BITS 8 // 8 bits for LCD parameter

#define LVGL_DRAW_BUF_LINES 20          // Number of display lines in each draw buffer
#define LVGL_TICK_PERIOD_MS 2           // LVGL tick period in milliseconds
#define LVGL_TASK_MAX_DELAY_MS 500      // Maximum delay for LVGL task in milliseconds
#define LVGL_TASK_MIN_DELAY_MS 1        // Minimum delay for LVGL task in milliseconds
#define LVGL_TASK_STACK_SIZE (4 * 1024) // Stack size for LVGL task
#define LVGL_TASK_PRIORITY 2            // Priority for LVGL task


extern _lock_t lvgl_api_lock; // mutex for LVGL API
extern SemaphoreHandle_t lvgl_mutex; // mutex for LVGL API
/*
 * PUBLIC FUNCTIONS
 */
void display_manager_init(void);

#endif // DISPLAY_MANAGER_H