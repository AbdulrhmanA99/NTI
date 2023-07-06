/*
 * ALARM_App.c
 *
 * Created: 7/2/2023 4:59:08 AM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"


int main(void)
{
	u8 Alarm = 0;
	u8 Read = 0xFF; /* key not pressed */
	
	LCD_voidInit();
	KPD_voidInit();

	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);

	while(1)
	{
		while(Read != 43) /* 43 is ascii representation for '+' */
		{
			Read = KPD_voidGetPressedKey();
			if(Read != 0xFF && Read != 43)
			{
				LCD_voidWriteNumber(Read-48); /* (-48) to convert from ascii to number */
				if(Read != 43)
				{
					Alarm = Alarm + (Read - 48);
				}
			}
		}
		_delay_ms(1000);
		LCD_voidClear();

		while(Alarm != 0)
		{
			_delay_ms(1000);
			LCD_voidClear();
			LCD_voidWriteNumber(Alarm);
			Alarm--;
		}
		_delay_ms(1000);
		LCD_voidClear();

		while(Alarm == 0)
		{
			_delay_ms(500);
			DIO_voidSetPinValue(PORTC_ID, PIN6, PIN_HIGH);
			LCD_voidGoToXY(1, 6);
			LCD_voidWriteString("Wake Up!");
		}
	}
	return 0;
}

#endif
