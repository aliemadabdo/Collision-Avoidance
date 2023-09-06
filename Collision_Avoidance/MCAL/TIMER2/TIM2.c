/*
 * TIM2.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Salem Elfaidy
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/******************************************************/
#define NORMAL			0
#define CTC				1
#define PWM_PHASE		2
#define FAST_PWM		3
/******************************************************/
#include "TIM2.h"

/* Global pointer to function */
void (*TIM2_pfTIM2Ovf)(void);
void (*TIM2_pfTIM2Cmp)(void);


void TIM2_voidInit	(void){
	/* select ur mode */
#if TIM2_MODE == NORMAL
	CLR_BIT(TCCR2, WGM00);
	CLR_BIT(TCCR2, WGM01);
#elif TIM2_MODE == CTC
	CLR_BIT(TCCR2, WGM00);
	SET_BIT(TCCR2, WGM01);
#elif TIM2_MODE == PWM_PHASE
	CLR_BIT(TCCR2, WGM01);
	SET_BIT(TCCR2, WGM00);
#else
	SET_BIT(TCCR2, WGM00);
	SET_BIT(TCCR2, WGM01);
#endif

}


void TIM2_voidSetPreValue	(u8 Copy_u8CounterStartVal){
	/* set timer start value */
	TCNT2 = Copy_u8CounterStartVal;

}


void TIM2_voidTimerStart	(u8 Copy_u8Prescaler){
	/* Set prescaler */
	TCCR2 &= 0b11111000;
	TCCR2 |= Copy_u8Prescaler;

}


void TIM2_voidOvrINTControl (u8 Copy_u8InterruptConl){

	if(Copy_u8InterruptConl == TIM2_TIN_EABLE)
		{SET_BIT(TIMSK, TOIE2);}
	else
		{CLR_BIT(TIMSK, TOIE2);}

}


void TIM2_voidSetCompareMat (u8 Copy_u8CmpMatVal, u8 Copy_u8OC2PinAction){

	switch(Copy_u8OC2PinAction)
	{
		case TIM2_OC2_TOGGLE_PIN :
			SET_BIT(TCCR2, COM00);
			CLR_BIT(TCCR2, COM01);
			break;

		case TIM2_OC2_CLEAR_PIN  :
			SET_BIT(TCCR2, COM01);
			CLR_BIT(TCCR2, COM00);
			break;

		case TIM2_OC2_SET_PIN    :
			SET_BIT(TCCR2, COM00);
			SET_BIT(TCCR2, COM01);
			break;

		default				     :
			CLR_BIT(TCCR2, COM00);
			CLR_BIT(TCCR2, COM01);
			break;
	}

	/* Set Compare value */
	OCR2 = Copy_u8CmpMatVal;

}


void TIM2_voidPWMGenerator  (u8 Copy_u8DutyCycle, u8 Copy_u8OC2PinAction){

#if TIM2_MODE == FAST_PWM
	if(Copy_u8OC2PinAction == TIM2_OC2_SET_CMP_CLR_OVF){
		SET_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
		OCR2 = (256 - ((Copy_u8DutyCycle/100.0)*256));
	}
	else{
		SET_BIT(TCCR2, COM01);
		CLR_BIT(TCCR2, COM00);
		OCR2 = ((Copy_u8DutyCycle/100.0)*256);
	}

#elif TIM2_MODE == PWM_PHASE
	if(Copy_u8OC2PinAction == TIM2_OC2_SET_UPC_CLR_DNC){
		SET_BIT(TCCR2, COM00);
		SET_BIT(TCCR2, COM01);
		OCR2 = (255 -(((Copy_u8DutyCycle/100.0)*510)/2));
	}
	else{
		SET_BIT(TCCR2, COM01);
		CLR_BIT(TCCR2, COM00);
		OCR2 = (((Copy_u8DutyCycle/100.0)*510)/2);
	}

#endif


}




void TIM2_voidSetCmpValue	(u8 Copy_u8CmpMatVal){

	/* Set Compare value */
	OCR2 = Copy_u8CmpMatVal;

}


void TIM2_voidCmpINTControl (u8 Copy_u8InterruptConl){

	if(Copy_u8InterruptConl == TIM2_TIN_EABLE)
		{SET_BIT(TIMSK, OCIE2);}
	else
		{CLR_BIT(TIMSK, OCIE2);}

}


void TIM2_voidTimerStop		(void){

	TCCR2 &= 0b11111000;

}


void TIM2_voidOvfCallback   ( void (*Copy_pfTIM2Ovf)(void) ){

	TIM2_pfTIM2Ovf = Copy_pfTIM2Ovf;
}


void TIM2_voidCmpCallback   ( void (*Copy_pfTIM2Cmp)(void) ){

	TIM2_pfTIM2Cmp = Copy_pfTIM2Cmp;

}

//This way, you can use different functions for different events without changing the ISR code.
ISR(TIMER2_OVF_vect){

	TIM2_pfTIM2Ovf();
}

//This way, you can use different functions for different events without changing the ISR code.
ISR(TIMER2_COMP_vect){

	TIM2_pfTIM2Cmp();
}


//#else
//#  define ISR(vector, ...)            \
//    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
//    void vector (void)
//#define TIMER2_COMP_vect		_VECTOR(3)
//#define _VECTOR(N) __vector_ ## N
//void (*TIM2_pfTIM2Cmp)(void);

//
//void __vector_3 (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__;
//
//void __vector_3 (void){
//
//	TIM2_pfTIM2Cmp();
//}







