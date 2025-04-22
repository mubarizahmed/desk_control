/**
 * @file events.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - Manage events for the application.
 * @version 0.1
 * @date 2025-04-22
 *
 */

#ifndef EVENTS_H
#define EVENTS_H

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */
#include "freertos/FreeRTOS.h"

/* ------------------------------------------------------ */
/*                      PUBLIC MACROS                     */
/* ------------------------------------------------------ */
#define TIME_SET_EVENT BIT0
#define WEATHER_SET_EVENT BIT1
#define CALENDAR_SET_EVENT BIT2
#define TODOIST_SET_EVENT BIT3
#define SPOTIFY_AUTH_EVENT BIT4

/* ------------------------------------------------------ */
/*                    PUBLIC VARIABLES                    */
/* ------------------------------------------------------ */
extern EventGroupHandle_t app_event_group;

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */
void app_events_init(void);

#endif // EVENTS_H