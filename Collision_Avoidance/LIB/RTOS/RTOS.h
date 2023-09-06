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

#define TICK_TIME 20
#define MAX_NUMBER_OF_TASKS 5

typedef enum {
    TASK_OK, 
    TASK_CREATION_ERROR,
    } error_type; 

typedef struct {
    char name[];
    u8 ID;
    u8 prority;
    u8 pirodicity;
    void (*service_routine) (void);
} RTOS_Task;

void RTOS_create_task(char copy_name[], u8 copy_priority, u8 copy_piriodicty, void (*copy_service_routine)(void));
void RTOS_schedule(void);
void RTOS_set_priority(char copy_name[], u8 copy_prioirty);

#endif