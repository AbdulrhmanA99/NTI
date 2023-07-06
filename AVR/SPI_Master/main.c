/*
 * SPI_Master.c
 *
 * Created: 7/3/2023 10:39:41 AM
 * Author : Abdul
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "01 MCAL/DIO_Driver/DIO_interface.h"

#include "01 MCAL/SPI_Driver/SPI_interface.h"

int main(void)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_INPUT);  /* push button */
	DIO_voidSetPinValue(PORTB_ID, PIN0, PIN_HIGH);		 /* led */
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT); /* mosi */
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_INPUT);  /* miso */
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_OUTPUT); /* ss */
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT); /* clk */			
	DIO_voidSetPinValue(PORTB_ID, PIN4, PIN_LOW);		 /* ss (active low) */
	SPI_Init_Master();   
    while (1) 
    {
		if(!DIO_voidGetBitValue(PORTB_ID, PIN0))
		{
			SPI_SendData('1');
		}
		else if(DIO_voidGetBitValue(PORTB_ID, PIN0))
		{
			SPI_SendData('0');
		}
    }
	return 0;
}

