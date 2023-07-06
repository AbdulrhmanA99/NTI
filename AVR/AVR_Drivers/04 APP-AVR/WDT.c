/*
 * WDT.c
 *
 * Created: 7/5/2023 11:49:23 PM
 * Author : Abdul
 */

#if 0
 
#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../01 MCAL/WDT_Driver/WDT_interface.h"

int main(void)
{ 
	while(1)
	{
		// Set LED1  pin as output
		DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_OUTPUT);

		// Turn on LED 1
		DIO_voidSetPinValue(PORTA_ID, PIN0, PIN_HIGH);
	
		_delay_ms(1000);
	
		// Turn off LED 1
		DIO_voidSetPinValue(PORTA_ID, PIN0, PIN_LOW);

		// Enable Watch Dog Timer
		WDT_voidEnable();

		// Reset MCU after 1 second (Pre-scaler = 6, maps to timeout = 1 second)
		WDT_voidSleep(6);
	
		//Disable WDT
		WDT_voidDisable();
		_delay_ms(2000);
	
		//LED2

		DIO_voidSetPinDirection(PORTA_ID, PIN1, PIN_OUTPUT);
		DIO_voidSetPinValue(PORTA_ID, PIN1, PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA_ID, PIN1, PIN_LOW);
		WDT_voidEnable();
		WDT_voidSleep(2);
		WDT_voidDisable();
		_delay_ms(2000);
	
		while(1)
		{
	
			//stuck loop led
		
			DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_OUTPUT);

			DIO_voidSetPinValue(PORTA_ID, PIN2, PIN_HIGH);
		
			_delay_ms(2000);
		
			DIO_voidSetPinValue(PORTA_ID, PIN2, PIN_LOW);
		
			/* if we don't enable the WDT here our MC will stay stuck in this loop 
		       that's showing the importance of WDT */
		
			//WDT_voidEnable();
		    //WDT_voidSleep(1);
		
		}
	}
	return 0;
}

#endif 
