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
	DIO_voidSetPinDirection(PORTC_ID, PIN7, PIN_OUTPUT);
	
	DIO_voidSetPinDirection(PORTD_ID, PIN0, PIN_INPUT);
	DIO_voidSetPinDirection(PORTD_ID, PIN1, PIN_OUTPUT);
	
	USART_Init();
	
	while (1)
	{
		if(USART_Receive() == '1')
		{	
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_HIGH);
		}
		
		else if(USART_Receive() == '0') 
		{	
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_LOW);	
		}
		
	}
	return 0;
}

//#endif
