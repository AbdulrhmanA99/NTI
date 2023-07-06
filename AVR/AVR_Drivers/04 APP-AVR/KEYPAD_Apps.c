/*
 * KEYPAD_Apps.c
 *
 * Created: 6/22/2023 5:00:47 PM
 *  Author: Abdul
 */ 

/*MULTIPLE APPS USING KEYPAD, 7SEG, LED AND BUZZER*/

#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/SEVEN_SEGMENT_Driver/SEV_interface.h"


/*FUNCTIONS PROTOTYPE ----> FOR FUNCTION IMPLEMENTATION LOOK DOWN*/
void BUZZ_Toggle(void);
void LED_Toggle(void);

int main(void)
{
	u8 key; /*TO STORE WHICH KEY IS PRESSED*/
	u8 counter=0; /*TO STORE THE 7SEG VALUE*/
	KPD_voidInit();
	
	SEV_Initialization();
	SEV_Enable1();

	while(1)
	{
		key = KPD_voidGetPressedKey();
		if(key == 7+48)			/* increment */ /* number + 48 for the ascii representation of the number */
		{
			//counter++;
			++counter;
			SEV_Write_One_Number(counter);
		}
		else if(key == 8+48)	//decrement
		{
			//counter--;
			--counter;			
			SEV_Write_One_Number(counter);
		}
		else if(key == 9+48)
		{
			LED_Toggle();
		}
		else if(key == 47) /* '/' ascii representation */
		{
			BUZZ_Toggle();
		}
	}
	return 0;
}

/*USED FUNCTIONS*/
void LED_Toggle(void)
{
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT);
	DIO_voidToggelPin(PORTB_ID, PIN7);
}

void BUZZ_Toggle(void)
{
	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
	DIO_voidToggelPin(PORTC_ID, PIN6);
}

#endif
