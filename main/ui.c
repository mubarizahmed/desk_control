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

static lv_obj_t *btn;
static lv_obj_t *scr;
static lv_obj_t *label;
static lv_display_rotation_t rotation = LV_DISP_ROTATION_0;

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


    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);

    // // create circles at 3points
    // lv_obj_t *c1 = NULL;
    // lv_obj_t *c2 = NULL;
    // lv_obj_t *c3 = NULL;
    // addCircles(c1, 64, 200, 5);
    // addCircles(c2, 170, 170, 10);
    // addCircles(c3, 230, 70, 15);
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