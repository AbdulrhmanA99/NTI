/*
 * Password.c
 *
 * Created: 6/22/2023 4:51:31 PM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"


#include "../02 HAL/LCD_Driver/LCD_interface.h"
#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"


int main(void)
{
	LCD_voidInit();
	KPD_voidInit();

	LCD_voidWriteString("Password: ");
	_delay_ms(2000);

	LCD_voidGoToXY(1, 0);

	u8 x[4] = {'1', '9', '9', '9'}; /* Desired password */
	u8 password[4];
	u8 i = 0, j = 0;
	u8 flag = 0;


	while (1)
	{

		if ((flag == 0) && (j < 4))
		{
			for (i = 0; i < 4; i++)
			{
				do
				{
					password[i] = KPD_voidGetPressedKey();
				} while (password[i] == 0xFF);
				LCD_voidWriteData('*');
			}

			if ((password[0] == x[0]) && (password[1] == x[1]) && (password[2] == x[2]) && (password[3] == x[3]))
			{
				flag = 1;
				LCD_voidClear();
				LCD_voidWriteString("WelcomeUser");
				_delay_ms(2000);

			}
			else
			{
				LCD_voidClear();
				LCD_voidWriteString("WrongPassword");
				_delay_ms(2000);
				LCD_voidClear();

				if(j < 3)
				{

					LCD_voidWriteString("Password: ");
					LCD_voidGoToXY(1, 0);
				}
				else
				{
					LCD_voidWriteString("LOCKED!");
				}

			}
			j++;

		}
	}
}

#endif