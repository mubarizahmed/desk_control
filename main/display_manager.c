/**
 * @file display_manager.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Display manager for initializing and managing the display, touch controller and LVGL.
 * @version 0.1
 * @date 2025-04-09
 *
 */

#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "pin_definitions.h"
#include <sys/lock.h>
#include <sys/param.h>
#include <unistd.h>

#include "esp_lcd_ili9341.h"
#include "esp_lcd_touch_xpt2046.h"

#include "ui.h"

#include "display_manager.h"

static const char *TAG = "DISPLAY_MANAGER"; // Log tag

static _lock_t lvgl_api_lock; // mutex for LVGL API

/**
 * @brief LVGL flush callback function. Called when LVGL needs to update the display.
 *
 * @param panel_io 	Pointer to the panel IO handle
 * @param edata 	Pointer to the event data
 * @param user_ctx 	Pointer to the user context (LVGL display object)
 * @return false 	if the event was not handled
 */
static bool notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx) {
    lv_display_t *disp = (lv_display_t *)user_ctx;
    lv_display_flush_ready(disp);
    return false;
}

/**
 * @brief LVGL display update callback function. Called when the display rotation changes.
 *
 * @param disp Pointer to the LVGL display object
 */
static void lvgl_port_update_callback(lv_display_t *disp) {
    esp_lcd_panel_handle_t panel_handle = lv_display_get_user_data(disp);
    lv_display_rotation_t rotation = lv_display_get_rotation(disp);

    switch (rotation) {
    case LV_DISPLAY_ROTATION_0:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, true, false);
        break;
    case LV_DISPLAY_ROTATION_90:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, true, true);
        break;
    case LV_DISPLAY_ROTATION_180:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, false, true);
        break;
    case LV_DISPLAY_ROTATION_270:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, false, false);
        break;
    }
}

/**
 * @brief  LVGL flush callback function. Called when LVGL needs to update the display.
 *
 * @param disp Pointer to the LVGL display object
 * @param area Pointer to the area to be updated
 * @param px_map Pointer to the pixel map (buffer) containing the pixel data
 */
static void lvgl_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
    lvgl_port_update_callback(disp);
    esp_lcd_panel_handle_t panel_handle = lv_display_get_user_data(disp);
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;
    // because SPI LCD is big-endian, we need to swap the RGB bytes order
    lv_draw_sw_rgb565_swap(px_map, (offsetx2 + 1 - offsetx1) * (offsety2 + 1 - offsety1));
    // copy a buffer's content to a specific area of the display
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, px_map);
}

/**
 * @brief LVGL touch callback function. Called when the touch event occurs.
 *
 * @param indev Pointer to the LVGL input device object
 * @param data Pointer to the LVGL input device data object
 */
static void lvgl_touch_cb(lv_indev_t *indev, lv_indev_data_t *data) {

    uint16_t touchpad_x[1] = {0};
    uint16_t touchpad_y[1] = {0};
    uint8_t touchpad_cnt = 0;

    esp_lcd_touch_handle_t touch_pad = lv_indev_get_user_data(indev);
    esp_lcd_touch_read_data(touch_pad);

    // read touch pressed state and coordinates
    bool touchpad_pressed = esp_lcd_touch_get_coordinates(touch_pad, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

    if (touchpad_pressed && touchpad_cnt > 0) {

        ESP_LOGI(TAG, "Touchpad: %d, %d", touchpad_x[0], touchpad_y[0]);

        // calibration using precalculated values
        int32_t temp_x = touchpad_x[0];
        int32_t temp_y = touchpad_y[0];

        touchpad_x[0] = 0.0672 * temp_x - 0.0040 * temp_y - 11.16;
        touchpad_y[0] = 0.0004 * temp_x - 0.0920 * temp_y + 333.81;

        // rotate 270 degrees
        // int32_t rotated_x = LCD touchpad_y[0];
        // int32_t rotated_y = LCD_V_RES - touchpad_x[0];
        // touchpad_x[0] = rotated_x;
        // touchpad_y[0] = rotated_y;
  


        ESP_LOGI(TAG, "Touchpad CORRECTED: %d, %d", touchpad_x[0], touchpad_y[0]);

        data->point.x = touchpad_x[0];
        data->point.y = touchpad_y[0];
        data->state = LV_INDEV_STATE_PRESSED;

        // add a circle to the display at the touch coordinates
        addCircle(touchpad_x[0], touchpad_y[0]);

    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

/**
 * @brief   Increase LVGL tick every LVGL_TICK_PERIOD_MS milliseconds
 *
 *
 * @param arg unused
 */
static void increase_lvgl_tick(void *arg) {
    /* Tell LVGL how many milliseconds has elapsed */
    lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

/**
 * @brief LVGL task. This task is responsible for handling LVGL events and updating the display.
 *
 *
 * @param arg unused
 */
static void lvgl_port_task(void *arg) {
    ESP_LOGI(TAG, "Starting LVGL task");

    uint32_t time_till_next_ms = 0;
    uint32_t time_threshold_ms = 1000 / CONFIG_FREERTOS_HZ;

    while (1) {
        // Lock the mutex due to the LVGL APIs are not thread-safe
        _lock_acquire(&lvgl_api_lock);
        // Handle LVGL tasks and events
        time_till_next_ms = lv_timer_handler();
        _lock_release(&lvgl_api_lock);
        // in case of triggering a task watch dog time out
        time_till_next_ms = MAX(time_till_next_ms, time_threshold_ms);
        // Wait for the next tick
        usleep(1000 * time_till_next_ms);
    }
}

/**
 * @brief   Initialize the display, touch controller, and LVGL library.
 *
 */
void display_manager_init() {
    ESP_LOGI(TAG, "Initialize display and touch controller");

    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << PIN_NUM_BK_LIGHT};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_LOGI(TAG, "Initialize SPI bus");
    spi_bus_config_t buscfg = {
        .sclk_io_num = PIN_NUM_SCLK,
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = LCD_H_RES * 80 * sizeof(uint16_t),
    };
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));

    ESP_LOGI(TAG, "Install panel IO");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = PIN_NUM_LCD_DC,
        .cs_gpio_num = PIN_NUM_LCD_CS,
        .pclk_hz = LCD_PIXEL_CLOCK_HZ,
        .lcd_cmd_bits = LCD_CMD_BITS,
        .lcd_param_bits = LCD_PARAM_BITS,
        .spi_mode = 0,
        .trans_queue_depth = 10,
    };
    // Attach the LCD to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));

    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };

    ESP_LOGI(TAG, "Install ILI9341 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_ili9341(io_handle, &panel_config, &panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, true, false));

    // user can flush pre-defined pattern to the screen before we turn on the screen or backlight
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(PIN_NUM_BK_LIGHT, LCD_BK_LIGHT_ON_LEVEL);

    ESP_LOGI(TAG, "Initialize LVGL library");
    lv_init();

    // create a lvgl display
    lv_display_t *display = lv_display_create(LCD_H_RES, LCD_V_RES);

    // alloc draw buffers used by LVGL
    // it's recommended to choose the size of the draw buffer(s) to be at least 1/10 screen sized
    size_t draw_buffer_sz = LCD_H_RES * LVGL_DRAW_BUF_LINES * sizeof(lv_color16_t);

    void *buf1 = spi_bus_dma_memory_alloc(LCD_HOST, draw_buffer_sz, 0);
    assert(buf1);
    void *buf2 = spi_bus_dma_memory_alloc(LCD_HOST, draw_buffer_sz, 0);
    assert(buf2);
    // initialize LVGL draw buffers
    lv_display_set_buffers(display, buf1, buf2, draw_buffer_sz, LV_DISPLAY_RENDER_MODE_PARTIAL);
    // associate the mipi panel handle to the display
    lv_display_set_user_data(display, panel_handle);
    // set color depth
    lv_display_set_color_format(display, LV_COLOR_FORMAT_RGB565);
    // set the callback which can copy the rendered image to an area of the display
    lv_display_set_flush_cb(display, lvgl_flush_cb);

    ESP_LOGI(TAG, "Install LVGL tick timer");
    // Tick interface for LVGL (using esp_timer to generate 2ms periodic event)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &increase_lvgl_tick,
        .name = "lvgl_tick"};
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, LVGL_TICK_PERIOD_MS * 1000));

    ESP_LOGI(TAG, "Register io panel event callback for LVGL flush ready notification");
    const esp_lcd_panel_io_callbacks_t cbs = {
        .on_color_trans_done = notify_lvgl_flush_ready,
    };
    /* Register done callback */
    ESP_ERROR_CHECK(esp_lcd_panel_io_register_event_callbacks(io_handle, &cbs, display));

    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_panel_io_spi_config_t tp_io_config = ESP_LCD_TOUCH_IO_SPI_XPT2046_CONFIG(PIN_NUM_TOUCH_CS);
    // Attach the TOUCH to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &tp_io_config, &tp_io_handle));

    esp_lcd_touch_config_t tp_cfg = {
        .x_max = LCD_V_RES,
        .y_max = LCD_H_RES,
        .rst_gpio_num = -1,
        .int_gpio_num = -1,
        .flags = {
            .swap_xy = 0,
            .mirror_x = 0,
            .mirror_y = 0,
        },
    };
    esp_lcd_touch_handle_t tp = NULL;

    // #elif CONFIG_LCD_TOUCH_CONTROLLER_XPT2046
    ESP_LOGI(TAG, "Initialize touch controller XPT2046");
    ESP_ERROR_CHECK(esp_lcd_touch_new_spi_xpt2046(tp_io_handle, &tp_cfg, &tp));
    // #endif

    static lv_indev_t *indev;
    indev = lv_indev_create(); // Input device driver (Touch)
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_display(indev, display);
    lv_indev_set_user_data(indev, tp);
    lv_indev_set_read_cb(indev, lvgl_touch_cb);

    ESP_LOGI(TAG, "Create LVGL task");
    xTaskCreate(lvgl_port_task, "LVGL", 6 * LVGL_TASK_STACK_SIZE, NULL, LVGL_TASK_PRIORITY, NULL);

    lv_disp_set_rotation(display, LV_DISP_ROTATION_270);

    ESP_LOGI(TAG, "Display LVGL Meter Widget");
    // Lock the mutex due to the LVGL APIs are not thread-safe
    _lock_acquire(&lvgl_api_lock);
    lvgl_demo_ui(display);
    _lock_release(&lvgl_api_lock);
}