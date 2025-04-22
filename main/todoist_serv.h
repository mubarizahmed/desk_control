/**
 * @file todoist_serv.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - Todoist service for handling Todoist tasks and authentication.
 * @version 0.1
 * @date 2025-04-21
 *
 */

#ifndef TODOIST_SERV_H
#define TODOIST_SERV_H

/* ------------------------------------------------------ */
/*                        TYPEDEFS                        */
/* ------------------------------------------------------ */

typedef struct {
    char task_name[18];
    char task_id[20];
    uint8_t task_priority;
} TodoistTaskData;

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */
void todoist_task(void *pvParameters);

#endif /* TODOIST_SERV_H */
