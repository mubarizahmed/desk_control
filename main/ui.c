/**
 * @file ui.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief LVGL UI
 * @version 0.1
 * @date 2025-04-09
 *
 */

#include "ui.h"
#include "lvgl.h"
#include "string.h"
#include "esp_log.h"

// colors
#define UI_BLACK lv_color_hex(0x000000)
#define UI_WHITE lv_color_hex(0xFFFFFF)
#define UI_YELLOW lv_color_hex(0Xffb700)

#define LV_LVGL_H_INCLUDE_SIMPLE

extern const lv_font_t jetbrains_mono_bold_50;
extern const lv_font_t jetbrains_mono_light_50;

static lv_obj_t *btn;
static lv_obj_t *scr;
static lv_obj_t *label;
static lv_display_rotation_t rotation = LV_DISP_ROTATION_0;

static lv_obj_t *time_hr_label;
static lv_obj_t *time_min_label;

static lv_obj_t *circle = NULL;

static const char *TAG = "UI";

static int currentCenterX;
static int currentCenterY;

static void btn_cb(lv_event_t *e) {
    // lv_display_t *disp = lv_event_get_user_data(e);
    // rotation++;
    // if (rotation > LV_DISP_ROTATION_270) {
    //     rotation = LV_DISP_ROTATION_0;
    // }
    // lv_disp_set_rotation(disp, rotation);
}
static void set_angle(void *obj, int32_t v) {
    lv_arc_set_value(obj, v);
}

void centeredGrowing(lv_obj_t *obj, int32_t size) {
    lv_obj_set_size(obj, size, size);
    lv_obj_set_pos(obj, currentCenterX - size / 2, currentCenterY - size / 2);
}

void addCircle(int centerX, int centerY) {
    // delete the previous circle if it exists
    if (circle)
        lv_obj_del(circle);

    // create style
    lv_style_t *style = malloc(sizeof(lv_style_t));
    lv_style_init(style);
    lv_style_set_radius(style, 10);
    lv_style_set_bg_opa(style, LV_OPA_COVER);
    lv_style_set_bg_color(style, lv_color_hex(0));

    // create object for drawing a circle, set style, and remove clickable flag
    circle = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(circle);
    lv_obj_add_style(circle, style, 0);
    lv_obj_clear_flag(circle, LV_OBJ_FLAG_CLICKABLE);

    // initial size is 0
    lv_obj_set_size(circle, 0, 0);
    currentCenterX = centerX;
    currentCenterY = centerY;
    lv_obj_set_pos(circle, centerX, centerY);

    // animation for increasing the size of the circle
    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, circle);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)centeredGrowing);
    lv_anim_set_values(&a, 0, 20);
    lv_anim_set_time(&a, 300);
    a.act_time = 0;
    lv_anim_start(&a);
}

void addCircles(lv_obj_t *c, int centerX, int centerY, int size) {
    // delete the previous circle if it exists

    // create style
    lv_style_t *style = malloc(sizeof(lv_style_t));
    lv_style_init(style);
    lv_style_set_radius(style, 10);
    lv_style_set_bg_opa(style, LV_OPA_COVER);
    lv_style_set_bg_color(style, lv_color_hex(0));

    // create object for drawing a circle, set style, and remove clickable flag
    c = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(c);
    lv_obj_add_style(c, style, 0);
    lv_obj_clear_flag(c, LV_OBJ_FLAG_CLICKABLE);

    // size is 6
    lv_obj_set_size(c, size, size);
    lv_obj_set_pos(c, centerX, centerY);
}

void lvgl_demo_ui(lv_display_t *disp) {
    scr = lv_display_get_screen_active(disp);

    // btn = lv_button_create(scr);
    // lv_obj_t *lbl = lv_label_create(btn);
    // lv_label_set_text_static(lbl, LV_SYMBOL_REFRESH " ROTATE");
    // lv_obj_align(btn, LV_ALIGN_BOTTOM_LEFT, 30, -30);
    // /*Button event*/
    // lv_obj_add_event_cb(btn, btn_cb, LV_EVENT_CLICKED, disp);

    /*Create an Arc*/
    lv_obj_t *arc = lv_arc_create(scr);
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
    lv_obj_remove_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_center(arc);

    // Create text weather data
    label = lv_label_create(scr);
    lv_label_set_text(label, "T °C");
    lv_obj_center(label);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(label, lv_color_hex(0x000000), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_letter_space(label, 2, 0);

    createTimeWidget();

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);

    // // CALIBRATION
    // // create circles at 5 points
    // lv_obj_t *c1 = NULL;
    // lv_obj_t *c2 = NULL;
    // lv_obj_t *c3 = NULL;
    // lv_obj_t *c4 = NULL;
    // lv_obj_t *c5 = NULL;

    // addCircles(c1, 25, 300, 5);
    // addCircles(c2, 170, 170, 10);
    // addCircles(c3, 140, 210, 15);
    // addCircles(c4, 170, 10, 20);
    // addCircles(c5, 64, 0, 25);
}

void createTimeWidget() {
    // create a rectangle for the time
    lv_obj_t *t_rect1 = lv_obj_create(scr);
    lv_obj_set_size(t_rect1, 84, 108);
    // lv_obj_align(t_rect1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_pos(t_rect1, 6, 6);
    lv_obj_set_style_bg_color(t_rect1, UI_YELLOW, 0);
    lv_obj_set_style_radius(t_rect1, 0, LV_PART_MAIN);
    lv_obj_set_style_border_color(t_rect1, UI_BLACK, 0);
    lv_obj_set_style_border_width(t_rect1, 2, 0);
    lv_obj_set_style_border_side(t_rect1, LV_BORDER_SIDE_FULL, 0);

    // disable scrollbar
    lv_obj_set_scrollbar_mode(t_rect1, LV_SCROLLBAR_MODE_OFF);

    time_hr_label = lv_label_create(t_rect1);
    lv_label_set_text(time_hr_label, "10");
    lv_obj_set_style_text_font(time_hr_label, &jetbrains_mono_bold_50, 0);
    lv_obj_set_style_text_color(time_hr_label, UI_BLACK, 0);
    lv_obj_set_style_text_align(time_hr_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_center(time_hr_label);
    lv_obj_set_style_text_letter_space(time_hr_label, -5, 0);
    lv_obj_set_pos(time_hr_label, 0, -25);

    time_min_label = lv_label_create(t_rect1);
    lv_label_set_text(time_min_label, "24");
    lv_obj_set_style_text_font(time_min_label, &jetbrains_mono_light_50, 0);
    lv_obj_set_style_text_color(time_min_label, UI_BLACK, 0);
    lv_obj_set_style_text_align(time_min_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(time_min_label, time_hr_label, LV_ALIGN_OUT_BOTTOM_MID, 0, -20);
    lv_obj_set_style_text_letter_space(time_min_label, -5, 0);
}

/**
 * @brief Set the weather data to the label.
 *
 *
 *
 * @param data Weather data string in the format "weather_location_temp_wind_humidity_moon_pressure"
 */
void setWeatherData(char *data) {
    // split on _
    char *token = strtok(data, "_");
    char *temp = NULL;
    char *wind = NULL;
    char *humidity = NULL;
    char *pressure = NULL;
    char *moon = NULL;
    char *weather = NULL;
    char *location = NULL;

    int i = 0;
    while (token != NULL) {
        switch (i) {
        case 0:
            weather = token;
            break;
        case 1:
            location = token;
            break;
        case 2:
            temp = token;
            break;
        case 3:
            wind = token;
            break;
        case 4:
            humidity = token;
            break;
        case 5:
            moon = token;
            break;
        case 6:
            pressure = token;
            break;
        default:
            break;
        }
        i++;
        token = strtok(NULL, "_");
    }
    // set the text of the label to the weather data
    lv_label_set_text(label, temp);
    // ESP_LOGI(TAG, "Weather data: %s", data);
}

void setTime(int hr, int min) {
    // check if the time labels are created
    if (time_hr_label == NULL || time_min_label == NULL) {
        ESP_LOGE(TAG, "Time labels not created yet.");
        return;
    }

    // create a string for the time data
    char hr_str[3];  // 2 digits + null terminator
    char min_str[3]; // 2 digits + null terminator

    // Convert the integers to strings
    hr_str[0] = '0' + (hr / 10); // Tens place
    hr_str[1] = '0' + (hr % 10); // Units place
    hr_str[2] = '\0';            // Null terminator

    min_str[0] = '0' + (min / 10); // Tens place
    min_str[1] = '0' + (min % 10); // Units place
    min_str[2] = '\0';             // Null terminator

    // set the text of the label to the time data
    lv_label_set_text(time_hr_label, hr_str);
    lv_label_set_text(time_min_label, min_str);
}