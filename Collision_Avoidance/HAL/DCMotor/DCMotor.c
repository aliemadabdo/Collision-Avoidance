/*
 * DCMotor.c

 *
 *  Created on: Sep 6, 2023
 *      Author: Ali Emad
 */
#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "DCMotor.h"

/*
 * Right motor : PB3 & PB5
 * Left motor  : PB3 & PB4
 * */


void DCMotor_voidInit(){
	/* Set PB3 PB4 PB5 as output pins */
	DDRB |= 0b00111000;

	/* Clear OCR0 */
	OCR0 = 0x00;

	/* Set Timer0 in Fast PWM mode*/
	//TIM0_voidInit(); and change mode in the TIM0.h file OR:
	SET_BIT(TCCR0, WGM00); //WGM : Wave generation mode
	SET_BIT(TCCR0, WGM01);

	/* Set Prescaler */
	TCCR0 &= 0b11111000; //clear prescaler bits (CS00 CS01 CS02)
	TCCR0 |= 0b00000010; //prescaler 1/8

	/* Set Compare match action inverting or non-inverting*/
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
}

void DCMotor_voidForward( u8 copy_u8Speed ){

	/* Set Pins Values*/
	OCR0 = 0xff * copy_u8Speed / 100 ; //PB3 PWM value
	PORTB &= ~(1<<4); // back left
	PORTB &= ~(1<<5); // back right

}

void DCMotor_voidRotRight(){
	OCR0 = 0xff * MED_SPEED / 100 ;  //forward
	PORTB &= ~(1<<4);				 // back left
	PORTB |=  (1<<5); 				 // back right
}

void DCMotor_voidRotLeft(){
	OCR0 = 0xff * MED_SPEED / 100 ; //forward
	PORTB &= ~(1<<5); 				// back right
	PORTB |=  (1<<4); 				// back left
}

void DCMotor_voidBackward( u8 copy_u8Speed ){
	OCR0 = 0xff * (100 - copy_u8Speed) / 100 ; // forward: limits back speed
	PORTB |= (1<<4); 						   // back left : HIGH
	PORTB |= (1<<5); 						   // back right: HIGH
}

void DCMotor_voidStop(){
	OCR0 = 0x00 ; 		//forward
	PORTB &= ~(1<<5); 	// back right
	PORTB &= ~(1<<4); 	// back left
}


