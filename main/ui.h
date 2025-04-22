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

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */

#include "lvgl.h"
#include "todoist_serv.h"
/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */

void addCircle(int centerX, int centerY);

void lvgl_app_ui(lv_display_t *disp);

void setWeatherData(char *data);
void setTime(int hr, int min, char *date);
void flashPomodoroOverlay(bool red);
void setPomodoro(char *text);
void setCalendarData(char *data);
void setSpotifyTextData(char *name, char *artist, bool playing);
void setSpotifyData(char *name, char *artist, char *image, bool playing);
void setTodoistData(TodoistTaskData *data, int count);

#endif // UI_H