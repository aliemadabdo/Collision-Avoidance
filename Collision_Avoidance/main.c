/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Ali Emad | Nada Atia | Amr Ramadan
 */
#include <util/delay.h>
#include "HAL/DCMotor/DCMotor.h"
#include "LIB/RTOS/RTOS.h"


void LED0_ISR (void){
	// BlInk LED WITH PERiod = 10 us
}
void LED1_ISR (void){
	// BlInk LED WITH PERiod = 500 us
}
void LED2_ISR (void){
	// BlInk LED WITH PERiod = 50 ms
}


/* you can pass any value between 0 and 100 as a speed to the functions*/

int main(void){
	int reading = 49 ;

	DCMotor_voidInit();

	RTOS_create_task(
		"LED0",
		0,                 //PRIORITY
		1,				   //PIRODICITY
		&LED0_ISR);

	RTOS_create_task(
		"LED1",
		1,                 //PRIORITY
		2,                 //PIRODICITY
		&LED1_ISR);

	RTOS_create_task(
		"LED2",
		2,                //PRIORITY
		4,                //PIRODICITY
		&LED2_ISR);

	while(1){

		DCMotor_voidForward(MAX_SPEED);

		if (reading < 50){
			DCMotor_voidForward(LOW_SPEED);
		}
		else if(reading < 10){
			DCMotor_voidRotRight();
			_delay_ms(300);
			DCMotor_voidForward(MAX_SPEED);

		}

		reading = 0;

		if (reading == 0){
			DCMotor_voidBackward(LOW_SPEED);
			_delay_ms(300);
			DCMotor_voidStop();
			_delay_ms(300);
			DCMotor_voidRotRight();
			_delay_ms(300);
			DCMotor_voidForward(MED_SPEED);

		}

	}
	return 0;
}
