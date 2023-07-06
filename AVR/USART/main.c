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

#include "02 HAL/LCD_Driver/LCD_interface.h"

int main()
{
	USART_Init();
	//USART_Send('A');
	USART_Send_Str("USART IS WORKING!");
	while(1)
	{

	}
	return 0;
}

//#endif
