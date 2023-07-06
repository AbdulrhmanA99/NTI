/*
 * USART.c
 *
 * Created: 7/2/2023 12:01:11 PM
 * Author : Abdul
 */ 

//#if 0

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "01 MCAL/DIO_Driver/DIO_interface.h"
#include "01 MCAL/USART_Driver/USART_interface.h"


int main()
{
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_INPUT); 
	DIO_voidSetPinValue(PORTB_ID, PIN0, PIN_HIGH);		// Button pull up
	
	DIO_voidSetPinDirection(PORTD_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinDirection(PORTD_ID, PIN1, PIN_OUTPUT);
	
	USART_Init();
	
	while (1)
	{
		if(!DIO_voidGetBitValue(PORTB_ID,PIN0))
		{
			USART_Send('1');	
		}
		
		else if(DIO_voidGetBitValue(PORTB_ID,PIN0)) 
		{	
			USART_Send('0');
		}
		
	}
	return 0;
}
//#endif
