/**
 * @file ui.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - LVGL UI
 * @version 0.1
 * @date 2025-04-09
 *
 */

#ifndef UI_H
#define UI_H

#include "lvgl.h"

/*
 * PUBLIC FUNCTIONS
 */
void addCircle(int centerX, int centerY);
void lvgl_demo_ui(lv_display_t *disp);
void lv_obj_remove_border_paddin_scrollbar(lv_obj_t *sp_cover_rect);
void addCircles(lv_obj_t *c, int centerX, int centerY, int size);
void setWeatherData(char *data);
void setTime(int hr, int min, char *date);

#endif // UI_H