/**
 * @file pomodoro.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - Pomodoro timer implementation.
 * @version 0.1
 * @date 2025-04-11
 *
 */

#ifndef POMODORO_H
#define POMODORO_H

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */
void startPomodoro(int duration); // in minutes
void stopPomodoro(void);          // stop the timer and reset the screen
void pomodoro_task(void *pvParameters);

#endif // POMODORO_H