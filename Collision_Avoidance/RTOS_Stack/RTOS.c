/*
 * RTOS.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mega Store
 */
/* includes */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "RTOS.h"
#include "TIM0.h"
/****************************/

/* Preprocessors */
#define NUM_OF_TASKS 3
/****************************/

/* Typedefs */
typedef struct{
	// priority will be represented as the order of the task in the array
	u16 Copy_u16periodicity;
	void (* pfTaskFunc)(void);
}Task_t;
/****************************/

/* Global array of system tasks */
Task_t RTOS_arrStrTasks[NUM_OF_TASKS];
/****************************/

/* Private functions */
static void Scheduler(void);
/****************************/

/* Public Functions */
void RTOS_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8CmpMatVal){
	sei(); //set global intr
	TIM0_voidInit();
	TIM0_voidSetCmpValue(Copy_u8CmpMatVal);
	TIM0_voidCmpCallback(&Scheduler);

	/* -> check every task period
	 * -> set prescaler value based on it */
	TIM0_voidTimerStart(Copy_u8Prescaler);
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u8 Copy_u8Periodicity, void (*Copy_pfTaskFunc)(void) ){
	RTOS_arrStrTasks[Copy_u8Priority].Copy_u16periodicity = Copy_u8Periodicity;
	RTOS_arrStrTasks[Copy_u8Priority].pfTaskFunc 		  = Copy_pfTaskFunc;

}
/****************************/
static void Scheduler(void){

	static u16 Local_u16Ticks = 0;
	u8 Local_u8counter;

	Local_u16Ticks++;
	for(Local_u8counter = 0; Local_u8counter < NUM_OF_TASKS; Local_u8counter++ ){
		if (Local_u16Ticks % RTOS_arrStrTasks[Local_u8counter].Copy_u16periodicity == 0){
				RTOS_arrStrTasks[Local_u8counter].pfTaskFunc();
		}
		else{
			/*do nothing*/
		}
	}
}


