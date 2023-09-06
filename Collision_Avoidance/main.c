/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Ali Emad
 */
#include <util/delay.h>
#include "HAL/DCMotor/DCMotor.h"

/* you can pass any value between 0 and 100 as a speed to the functions*/

int main(void){
	int reading = 49 ;

	DCMotor_voidInit();

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
