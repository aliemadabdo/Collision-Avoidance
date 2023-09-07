/*
 * TIM2.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Salem Elfaidy
 */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include "TIM2.h"

/* Global pointer to function */
void (*TIM2_pfTIM2Cmp)(void);


void TIM2_voidInit	(void){
	/* select CTC mode */

	CLR_BIT(TCCR2, WGM00);
	SET_BIT(TCCR2, WGM01);

	/* CTC INT Enable for RTOS*/
	SET_BIT(TIMSK, OCIE2);
}

void TIM2_voidTimerStart	(u8 Copy_u8Prescaler){
	/* Set prescaler */
	TCCR2 &= 0b11111000;
	TCCR2 |= Copy_u8Prescaler;

}

void TIM2_voidSetCmpValue	(u8 Copy_u8CmpMatVal){

	/* Set Compare value */
	OCR2 = Copy_u8CmpMatVal;

}

void TIM2_voidTimerStop		(void){

	TCCR2 &= 0b11111000;

}

void TIM2_voidCmpCallback   ( void (*Copy_pfTIM2Cmp)(void) ){

	TIM2_pfTIM2Cmp = Copy_pfTIM2Cmp;

}


ISR(TIMER2_COMP_vect){

	TIM2_pfTIM2Cmp();
}
