/**
 * @file events.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Manage events for the application.
 * @version 0.1
 * @date 2025-04-22
 *
 */

#include "app_events.h"

EventGroupHandle_t app_event_group;

void app_events_init(void) {
    app_event_group = xEventGroupCreate();
}