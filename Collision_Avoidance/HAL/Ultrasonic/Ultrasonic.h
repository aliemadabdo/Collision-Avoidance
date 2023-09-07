/*
 * Ultrasonic.h
 *
 *  Created on: Sep 6, 2023
 *      Author: hp
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#define ULTRASONIC_TRIG_PORT		DIO_PORTD
#define ULTRASONIC_TRIG_PIN			DIO_PIN5
#define ULTRASONIC_ECHO_PORT		DIO_PORTD
#define ULTRASONIC_ECHO_PIN			DIO_PIN6


void ULTRASONIC_voidInit(void);
void ULTRASONIC_voidStartTrigger(void);
void ULTRASONIC_TravelTimeCB (void);
u32 ULTRASONIC_voidReturnDistanceCm(void);


#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
