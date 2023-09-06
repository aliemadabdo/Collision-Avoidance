/*
 * TIM0.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Salem Elfaidy
 */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include "TIM0.h"

/* Global pointer to function */
void (*TIM0_pfTIM0Cmp)(void);


void TIM0_voidInit	(void){
	/* select CTC mode */

	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	/* CTC INT Enable for RTOS*/
	SET_BIT(TIMSK, OCIE0);
}

void TIM0_voidTimerStart	(u8 Copy_u8Prescaler){
	/* Set prescaler */
	TCCR0 &= 0b11111000;
	TCCR0 |= Copy_u8Prescaler;

}

void TIM0_voidSetCmpValue	(u8 Copy_u8CmpMatVal){

	/* Set Compare value */
	OCR0 = Copy_u8CmpMatVal;

}

void TIM0_voidTimerStop		(void){

	TCCR0 &= 0b11111000;

}

void TIM0_voidCmpCallback   ( void (*Copy_pfTIM0Cmp)(void) ){

	TIM0_pfTIM0Cmp = Copy_pfTIM0Cmp;

}


ISR(TIMER0_COMP_vect){

	TIM0_pfTIM0Cmp();
}
