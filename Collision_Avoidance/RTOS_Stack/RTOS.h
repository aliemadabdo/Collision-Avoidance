/*
 * RTOS.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Mega Store
 */

#ifndef RTOS_STACK_RTOS_H_
#define RTOS_STACK_RTOS_H_

/****************** Prescaler ******************************/
#define TIM0_STOPPED				0
#define TIM0_NO_PRESCALER			1
#define TIM0_PRESCALER_8			2
#define TIM0_PRESCALER_64			3
#define TIM0_PRESCALER_256			4
#define TIM0_PRESCALER_1024			5
#define TIM0_EXT_FALLING			6
#define TIM0_EXT_RISINGING			7

/***************************** APIs ************************************************/

/* here we will set the prescaler based on processes priodicity */
void RTOS_voidInit(u8 Copy_u8Prescaler, u8 Copy_u8CmpMatVal);
/* Task = Priodicity + Priority + C code function */
void RTOS_voidCreateTask(u8 Copy_u8Priority, u8 Copy_u8Periodicity, void (*Copy_pfTaskFunc)(void) );


#endif /* RTOS_STACK_RTOS_H_ */
