/*
 * DCMotor.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Ali Emad
 */

#ifndef HAL_DCMOTOR_DCMOTOR_H_
#define HAL_DCMOTOR_DCMOTOR_H_

/******************* Configurations ***********************/
#define MAX_SPEED 	100
#define HIGH_SPEED 	75
#define MED_SPEED 	50
#define LOW_SPEED 	25

/******************* APIs ***********************/

void DCMotor_voidInit();
void DCMotor_voidForward( u8 copy_u8Speed );
void DCMotor_voidRotRight();
void DCMotor_voidRotLeft();
void DCMotor_voidBackward( u8 copy_u8Speed );
void DCMotor_voidStop();

#endif /* HAL_DCMOTOR_DCMOTOR_H_ */
