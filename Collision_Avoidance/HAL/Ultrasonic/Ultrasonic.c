/*
 * Ultrasonic.c
 *
 *  Created on: Sep 6, 2023
 *      Author: hp
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/ICU/ICU.h"
#include "Ultrasonic.h"



volatile u16 TravelTime = 0;


void ULTRASONIC_voidInit(void) {
    // Configure trigger pin as an output
	DIO_voidSetPinDirection(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, DIO_OUTPUT);

    // Configure echo pin as an input
    DIO_voidSetPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, DIO_INPUT);

    // Set up Timer1 for input capture mode
	ICU_voidInit();
    ICU_voidSetCallback(ULTRASONIC_TravelTimeCB);
}

void ULTRASONIC_voidStartTrigger(void) {
    // Send a 10us pulse on the trigger pin
	DIO_voidSetPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, DIO_HIGH);
    _delay_us(15);
    DIO_voidSetPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, DIO_LOW);
}

void ULTRASONIC_TravelTimeCB (void)
{
    static u16 start_time = 0;
    static u8 capture_count = 0;

    if (capture_count == 0) {
        // Capture rising edge, store the timer value
        start_time = ICU_u16ReadValue();
        ICU_voidChangeTrigger(ICU_FALLING_EDGE); // Switch to capture on falling edge
        capture_count++;
    }
    else if (capture_count == 1) {
        // Capture falling edge
        u16 end_time = ICU_u16ReadValue();
        TravelTime = end_time - start_time;
        ICU_voidChangeTrigger(ICU_RISING_EDGE); // Switch back to capture on rising edge
        capture_count = 0;
        _delay_ms(10);
    }


}



u32 ULTRASONIC_voidReturnDistanceCm(void)
{
	u32 Local_ULTRASONIC_Distance_Cm =0;
	if(TravelTime>36000)
	{
		Local_ULTRASONIC_Distance_Cm ='O'; // Indicate error in echo
	}
	else
	{
		Local_ULTRASONIC_Distance_Cm = (u32)(( TravelTime/29)/2);
	}

	return Local_ULTRASONIC_Distance_Cm;
}
