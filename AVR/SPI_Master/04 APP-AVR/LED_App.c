/*
 * LED_App.c
 *
 * Created: 6/22/2023 4:51:31 PM
 *  Author: Abdul
 */ 

/*APP TO TOGGLE LED USING DIO DRIVER*/

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"


int main(void)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT); /*SET RED LED AS AN OUTPUT*/
	while(1)
	{
		DIO_voidSetPinValue(PORTB_ID, PIN7, PIN_HIGH); /*TURN THE LED ON*/
		_delay_ms(1000);
		DIO_voidToggelPin(PORTB_ID, PIN7); /*TOGGLE LED ON*/
		_delay_ms(1000);
		/*DELAY TO NOTICE THE CHANGE*/
	}
}

#endif