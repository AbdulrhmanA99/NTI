/*
 * Seb7a.c
 *
 * Created: 7/5/2023 3:22:57 PM
 *  Author: Abdul
 */ 

/* Electronic SEB7A Application */

#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"

#include "../01 MCAL/EXTI0_Driver/EXTI0_interface.h"
#include "../01 MCAL/GIE_Driver/GIE_interface.h"

#include "../02 HAL/SEVEN_SEGMENT_Driver/SEV_interface.h"


void DigitalRosary(void);

u8 counter = 0;

int main(void)
{

    SEV_Initialization();
    SEV_Enable1();

    /* Push button Initialization */
	DIO_voidSetPinDirection(PORTD_ID, PIN3, PIN_INPUT);
	DIO_voidSetPinValue(PORTD_ID, PIN3, PIN_HIGH);

	EXTI0_voidInit();
	EXTI0_voidCallBack(&DigitalRosary);
	GIE_voidEnable();

	while(1)
	{

	}
	return 0;
}


void DigitalRosary(void)
{
    SEV_Write_One_Number(counter);  // Display the current value of the counter
    if (counter == 9) 
	{
		counter = 0;				// Reset counter value to 0 when it reaches 9
    }
	else 
	{
        counter++;
    }
}

#endif