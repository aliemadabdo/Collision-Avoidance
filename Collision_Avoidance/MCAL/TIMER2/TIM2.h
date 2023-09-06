/*
 * TIM2.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Salem Elfaidy
 */

#ifndef TIM2_H
#define TIM2_H

/************************************************************ Cfg ********************************************************/

/******************** Select Mode **************************/
#define TIM2_MODE					FAST_PWM
/* NORMAL		CTC		PWM_PHASE		FAST_PWM */

/****************** Prescaler ******************************/
#define TIM2_STOPPED				0
#define TIM2_NO_PRESCALER			1
#define TIM2_PRESCALER_8			2
#define TIM2_PRESCALER_64			3
#define TIM2_PRESCALER_256			4
#define TIM2_PRESCALER_1024			5
#define TIM2_EXT_FALLING			6
#define TIM2_EXT_RISINGING			7

/****************** Interrupt control ***********************/
#define TIM2_TIN_EABLE				1
#define TIM2_TIN_DISABLE			0

/***************** CO2 Pin Action (NORMAL, CTC)**************/
#define TIM2_OC2_IN_OUT_PIN			0
#define TIM2_OC2_TOGGLE_PIN			1
#define TIM2_OC2_CLEAR_PIN			2
#define TIM2_OC2_SET_PIN			3

/***************** CO2 Pin Action (FAST PWM)**************/
#define TIM2_OC2_SET_CMP_CLR_OVF			1
#define TIM2_OC2_CLR_CMP_SET_OVF			2

/***************** CO2 Pin Action (PHASE PWM)**************/
#define TIM2_OC2_SET_UPC_CLR_DNC			1
#define TIM2_OC2_CLR_UPC_SET_DNC			2


/************************************************************** APIs ****************************************************************/

void TIM2_voidInit			(void);
void TIM2_voidSetPreValue	(u8 Copy_u8CounterStartVal);
void TIM2_voidTimerStart	(u8 Copy_u8Prescaler      );
void TIM2_voidOvrINTControl (u8 Copy_u8InterruptConl  );
void TIM2_voidSetCompareMat (u8 Copy_u8CmpMatVal, u8 Copy_u8OC2PinAction);
void TIM2_voidPWMGenerator  (u8 Copy_u8DutyCycle, u8 Copy_u8OC2PinAction);
void TIM2_voidSetCmpValue	(u8 Copy_u8CmpMatVal      );
void TIM2_voidCmpINTControl (u8 Copy_u8InterruptConl  );
void TIM2_voidTimerStop		( void);
void TIM2_voidOvfCallback   ( void (*Copy_pfTIM2Ovf)(void) );
void TIM2_voidCmpCallback   ( void (*Copy_pfTIM2Cmp)(void) );

// returned type (* pf) (input parameters)












#endif /* MCAL_TIMER2_TIM2_H_ */
