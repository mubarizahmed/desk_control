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
void createTimeWidget();
void addCircles(lv_obj_t *c, int centerX, int centerY, int size);
void setWeatherData(char *data);
void setTime(int hr, int min);

#endif // UI_H