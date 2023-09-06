/*
 * File name: RTOS.c
 *
 *  Created on: Sep 6, 2023
 *      Authors: Ali Emad | Nada Atia | Amr Ramadan
 * 
 * Brief: A light version of RTOS for ATmega32.
 */


/* DEPENECIES BEGIN */
#include "RTOS.h"
#include <string.h>
/* DEPENECIES END */

/* PV BEGIN */
RTOS_Task RTOS_tasks_array[RTOS_MAX_NUMBER_OF_TASKS];
u8 RTOS_tasks_array_index = 0;
char RTOS_running_task[] = "NULL";
/* PV END */

/* PFI BEGIN */
RTOS_error_t RTOS_create_task(char copy_name[], u8 copy_priority, u8 copy_piriodicty, void (*copy_service_routine_ptr)(void)){
    RTOS_tasks_array[RTOS_tasks_array_index].name = copy_name;
    RTOS_tasks_array[RTOS_tasks_array_index].ID = RTOS_tasks_array_index;
    RTOS_tasks_array[RTOS_tasks_array_index].priority = copy_priority;
    RTOS_tasks_array[RTOS_tasks_array_index].pirodicity = copy_piriodicty;
    RTOS_tasks_array[RTOS_tasks_array_index].wait_countdown = copy_piriodicty;
    RTOS_tasks_array[RTOS_tasks_array_index].service_routine_ptr = copy_service_routine_ptr;
    
    RTOS_tasks_array_index ++;

    return(TASK_OK);
}

void RTOS_bubble_sort_task(u8 copy_start_index){
    RTOS_Task temp_task;
    for(int index=copy_start_index; index<RTOS_MAX_NUMBER_OF_TASKS; index++){
        if(RTOS_tasks_array[index].prority > RTOS_tasks_array[copy_start_index].prority){
            // swap to get the higher priority task at the start of the task array 
            temp_task = RTOS_tasks_array[copy_start_index];
            RTOS_tasks_array[copy_start_index] = RTOS_tasks_array[index];
            RTOS_tasks_array[index] = temp_task;
        }
    }
}

void RTOS_schedule(void){
    for(int index=0; index<RTOS_tasks_array_index; index++){
            if(RTOS_tasks_array[index].wait_countdown <= 0){
                // task ready to run
                RTOS_tasks_array[index].wait_countdown = RTOS_tasks_array[index].pirodicity;
                strcpy(RTOS_running_task, RTOS_tasks_array[index].name);
                RTOS_tasks_array[index].service_routine_ptr();
            }
            else{
                // task should wait for upcoming ticks
                RTOS_tasks_array[index].wait_countdown--;
            }

            // bubble sort the at the current index (highest priority on the left)
            RTOS_bubble_sort_task(index); 
    }
}

void RTOS_set_priority(char copy_name[], u8 copy_prioirty){
    // serach for the name in the tasks array and set the priopirty to the given value
    for(int index=0; index<RTOS_tasks_array_index; index++){
        if(!strcmp(RTOS_tasks_array[index].name, copy_name)){
            strcpy(RTOS_tasks_array[index].prority,copy_prioirty);
            break; 
        }
    }
}
/* PFI END */