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

/****************** Prescaler ******************************/
#define TIM0_STOPPED				0
#define TIM0_NO_PRESCALER			1
#define TIM0_PRESCALER_8			2
#define TIM0_PRESCALER_64			3
#define TIM0_PRESCALER_256			4
#define TIM0_PRESCALER_1024			5
#define TIM0_EXT_FALLING			6
#define TIM0_EXT_RISINGING			7

#define RTOS_TICK_TIME 100
#define RTOS_MAX_NUMBER_OF_TASKS 5
#define RTOS_MAX_TASK_NAME_LEN 30

typedef enum {
    TASK_OK, 
    TASK_CREATION_ERROR,
    } RTOS_error_t; 

typedef struct {
    char name[RTOS_MAX_TASK_NAME_LEN];
    u8 ID;
    u8 priority;
    u8 pirodicity;
    u8 wait_countdown;
    void (*service_routine_ptr) (void);
} RTOS_Task;

void RTOS_voidInit(u8 copy_u8Prescaler, u8 copy_u8CmpMatVal);
RTOS_error_t RTOS_create_task(char copy_name[], u8 copy_priority, u8 copy_piriodicty, void (*copy_service_routine_ptr)(void));
void RTOS_schedule(void);
void RTOS_bubble_sort_task(u8 copy_start_index);
void RTOS_set_priority(char copy_name[], u8 copy_prioirty);
// sort RTOS_tasks_array() bassed on priority 
#endif
