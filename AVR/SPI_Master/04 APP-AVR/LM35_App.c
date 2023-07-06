/*
 * LM35_App.c
 *
 * Created: 6/22/2023 8:58:22 PM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../01 MCAL/ADC_Driver/ADC_interface.h"

#include "../02 HAL/LCD_Driver/LCD_interface.h"


u16 DigitalValue = 0;
u16 AnaloglValueMV = 0;
u16 Temperature = 0;


int main(void)
{

	DIO_voidSetPinDirection(PORTA_ID, PIN1, PIN_INPUT);
	
	LCD_voidInit();
	LCD_voidGoToXY(0, 0);
	LCD_voidWriteString("Temperature is: ");

	ADC_voidInit();
	ADC_voidEnable();

	while(1)
	{
		DigitalValue = ADC_u16GetDigitalValue(ADC_u8_CHANNEL_0);

		AnaloglValueMV = (DigitalValue * 5000UL) / 1024;
		
		Temperature = AnaloglValueMV /10;
		

		LCD_voidGoToXY(0, 15);
		LCD_voidWriteNumber(Temperature);


	}
	return 0;
}

#endif
