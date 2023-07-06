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

	DIO_voidSetPinDirection(PORTC_ID, PIN7, PIN_OUTPUT); /* led */
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_INPUT);  /* mosi */
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT); /* miso */
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_INPUT);  /* ss (active low) */
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_INPUT);  /* clk */			
	SPI_Init_Slave();   
    while (1) 
    {
		if(SPI_SendData('1') == '1')
		{
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_HIGH);
		}
		else if(SPI_SendData('0') == '0')
		{
			DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_LOW);
		}
    }
	return 0;
}

