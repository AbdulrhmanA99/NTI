/*
 * NVIC_App.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Abdul
 */

#if 0
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"


//static void (*pf) (void) = NULL;

int main()
{
	RCC_voidSysClkInit();
	/*
		A5 	(LED)		RCC GPIOA + Direction Output Push Pull
		C13	(Switch)	RCC GPIOC + Direction Input Pull Up
	*/
	NVIC_voidInit();
	/*	NVIC EXTI Enable Interrupt peripheral 	*/
	NVIC_voidSetInterruptEnable(6);
	/*	EXTI 0 	GRP 2 , SUB 2		*/
	NVIC_voidSetintPriority(6, 0b1010);
	/*	Set pending of EXTI 0		*/
	NVIC_voidSetPendingFlag(6);


	while(1)
	{

	}


return 0 ;
}


void	EXTI0_IRQHandler ()
{
	/*	Toggle led A5			*/
	/*	Clear the Flag			*/
}

#endif
