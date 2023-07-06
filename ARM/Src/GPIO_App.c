/*
 * GPIO_App.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Abdul
 */


//#if 0
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_Interface.h"

//#include "STK_Interface.h"


void myDelay(u8 delayTime);


int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_AHB1, 0);

	GPIO_u8SetPinDirection(GPIO_A, GPIO_PIN5, GPIO_OUTPUT_PP);
	GPIO_u8SetPinValue(GPIO_A, GPIO_PIN5, GPIO_HIGH);

	//STK_voidInit();


	while(1)
	{
		//GPIO_u8SetPinValue(GPIO_A, GPIO_PIN5, GPIO_HIGH);
		//myDelay(100);
		//STK_voidBusyWait(1000000);

		//GPIO_u8SetPinValue(GPIO_A, GPIO_PIN5, GPIO_LOW);
		//myDelay(100);
		//STK_voidBusyWait(1000000);
	}
}

void myDelay(u8 delayTime)
{
	u8 i, j;
		for (i=0; i<delayTime; i++)
			for (j=0; i<1000; j++);
}
//#endif
