/*
 * File name: RTOS.h
 *
 *  Created on: Sep 6, 2023
 *      Authors: Ali Emad | Nada Atia | Amr Ramadan
 * 
 * Brief: A light version of RTOS for ATmega32.
 */


#ifndef RTOS_H
#define RTOS_H

/* DEPENECIES BEGIN */
#include "../STD_Types.h"
/* DEPENECIES END */

#define RTOS_TICK_TIME 100
#define RTOS_MAX_NUMBER_OF_TASKS 5

typedef enum {
    TASK_OK, 
    TASK_CREATION_ERROR,
    } RTOS_error_t; 

typedef struct {
    char name[];
    u8 ID;
    u8 prority;
    u8 pirodicity;
    u8 wait_countdown;
    void (*service_routine_ptr) (void);
} RTOS_Task;

RTOS_error_t RTOS_create_task(char copy_name[], u8 copy_priority, u8 copy_piriodicty, void (*copy_service_routine_ptr)(void));
void RTOS_schedule(void);
void RTOS_set_priority(char copy_name[], u8 copy_prioirty);
void
#endif