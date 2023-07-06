/*
 * Password_App.c
 *
 * Created: 6/22/2023 7:31:05 PM
 *  Author: Abdul
 */ 
	
#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../02 HAL/KEYPAD_Driver/HKEYPAD_int.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"


void BUZZ_Toggle(void);
void LED_Toggle(void);

void HKEYPAD_voidcheckPassword2(void)
{
	HKEYPAD_enInit();

	u8 password[4]={'1','2','3','4'};
	u8 check[4]={0};
	u8 i,j;
	u8 counter=0;

	for(i=0;i<3;i++)	//number of password trials
	{
		for(j=0;j<4;j++)	//filling the checking array
		{

			if (check[j] != HKEYPAD_NO_PRESSED_KEY)
			{
				LCD_voidWriteCommand(0xc0);		//setting DDRAM position
				check[j]= HKEYPAD_enGetPressedKey(check[j]);
				HKEYPAD_enGetPressedKey(check[j]);
				LCD_voidWriteData('*');
			}
		}
		if(password[0]==check[0] && password[1]==check[1] && password[2]==check[2] && password[3]==check[3])
		{
			LED_Toggle();
			break;
		}
		else
		{
			counter++;
		}
	}
	if (counter==3)
	{
		BUZZ_Toggle();
	}
	counter =	0 ;
}



void BUZZ_Toggle(void)
{
	DIO_voidToggelPin(PORTC_ID, PIN6);
}

void LED_Toggle(void)
{
	DIO_voidToggelPin(PORTB_ID, PIN7);
}

#endif
