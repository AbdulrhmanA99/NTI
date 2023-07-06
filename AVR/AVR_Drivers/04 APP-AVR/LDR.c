/*
 * LDR.c
 *
 * Created: 7/2/2023 2:23:47 AM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../01 MCAL/ADC_Driver/ADC_interface.h"

#include "../02 HAL/LCD_Driver/LCD_interface.h"


u16 DigitalValue = 0;
u16 AnaloglValue = 0;
u16 Brightness = 0;

int main(void)
{
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	
	LCD_voidInit();
	LCD_voidGoToXY(0, 0);
	LCD_voidWriteString("Brightness is: ");

	ADC_voidInit();
	ADC_voidEnable();
	
	while(1)
	{
		AnaloglValue = ADC_u16GetDigitalValue(ADC_u8_CHANNEL_0);

		DigitalValue = ( AnaloglValue * 5000UL ) / 1024;

		Brightness = ( DigitalValue / 50 );
		
		LCD_voidGoToXY(0, 14);
		LCD_voidWriteNumber(Brightness);
	}
	return 0;
}

#endif
