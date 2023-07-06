/*
 * STK_App.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Abdul
 */


#if 0


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "STK_Interface.h"



int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_AHB1, 0);
	STK_voidInit();

	GPIO_u8SetPinDirection(GPIO_A, GPIO_PIN5, GPIO_OUTPUT_PP);
	while(1)
	{
		GPIO_u8SetPinValue(GPIO_A, GPIO_PIN5, GPIO_HIGH);
		STK_voidBusyWait(1000000);
		GPIO_u8SetPinValue(GPIO_A, GPIO_PIN5, GPIO_LOW);
		STK_voidBusyWait(1000000);

	}
}
#endif
