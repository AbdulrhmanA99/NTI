/*
 * 7amoksha_SleepWakeCycle.c
 *
 * Created: 6/22/2023 9:17:11 PM
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

int main(void)
{	
	DIO_voidSetPinDirection(PORTA_ID, PIN0, PIN_INPUT);
	
	LCD_voidInit();
	LCD_voidWriteString("Play with 7amoksha");
	_delay_ms(1000);
	
	ADC_voidInit();
	ADC_voidEnable();
	
	u8 awake[] = {
		0b00100,
		0b01010,
		0b00100,
		0b00100,
		0b01110,
		0b10101,
		0b01010,
		0b10001
	};
	
	u8 asleep[] = {
		0b00000,
		0b00000,
		0b00010,
		0b11111,
		0b10110,
		0b10100,
		0b00000,
		0b00000
	};
	
	
	u16 DigitalValue, AnalogValue, Brightness;

	while (1)
	{	
		AnalogValue = ADC_u16GetDigitalValue(ADC_u8_CHANNEL_0);
		DigitalValue  = ( AnalogValue * 5000UL ) / 1024;
		Brightness   = ( DigitalValue / 50 );
		
		LCD_voidClear();
		LCD_voidGoToXY(1, 0);
		LCD_voidWriteString("Brightness is: ");
		LCD_voidWriteNumber(Brightness);
		
		if(Brightness <= 50)
		{
			LCD_voidWriteSpecialCharToCGRAM(asleep, 1, 2, 1);
			LCD_voidGoToXY(2,5);
			LCD_voidWriteString("Sleeping");
		}
		else
		{
			LCD_voidWriteSpecialCharToCGRAM(awake, 0, 2, 1);
			LCD_voidGoToXY(2,5);
			LCD_voidWriteString("Awake");
		}
		_delay_ms(1000);
	}

	return 0;
}

#endif
