/*
 * NVIC_program.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Abdul
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"



void	NVIC_voidInit()
{
	#ifndef		SCB_AIRCR
	#define		SCB_AIRCR		*((volatile u32 *)(0xE000ED00+0x0C))
	#endif
	SCB_AIRCR = NUM_OF_GRP_SUB;
}


void	NVIC_voidSetInterruptEnable(u8 Int_Num)
{
	/*		Range Check 			*/
	if(Int_Num<32)
	{
		NVIC_ISER0 = (1<<Int_Num);
	}
	else if(Int_Num<64)
	{
		Int_Num -= 32;
		NVIC_ISER1 = (1<<Int_Num);
	}
}

void	NVIC_voidSetInterruptDisable(u8 Int_Num)
{
	/*		Range Check 			*/
	if(Int_Num<32)
	{
		NVIC_ICER0 = (1<<Int_Num);
	}
	else if(Int_Num<64)
	{
		Int_Num -= 32;
		NVIC_ICER1 = (1<<Int_Num);
	}
}

void	NVIC_voidSetPendingFlag(u8 Int_Num)
{
	/*		Range Check 			*/
	if(Int_Num<32)
	{
		NVIC_ISPR0 = (1<<Int_Num);
	}
	else if(Int_Num<64)
	{
		Int_Num -= 32;
		NVIC_ISPR1 = (1<<Int_Num);
	}
}

void	NVIC_voidClrPendingFlag(u8 Int_Num)
{
	/*		Range Check 			*/
	if(Int_Num<32)
	{
		NVIC_ICPR0 = (1<<Int_Num);
	}
	else if(Int_Num<64)
	{
		Int_Num -= 32;
		NVIC_ICPR1 = (1<<Int_Num);
	}
}

u8		NVIC_u8GetActiveFlag(u8 Int_Num)
{
	u8 Local_u8Temp = 0xAA;
	/*		Range Check 			*/
	if(Int_Num<32)
	{
		Local_u8Temp = GET_BIT(NVIC_IABR0, Int_Num) ;
	}
	else if(Int_Num<64)
	{
		Int_Num -= 32;
		Local_u8Temp = GET_BIT(NVIC_IABR1, Int_Num) ;
	}
	return Local_u8Temp;
}


void	NVIC_voidSetintPriority(u8 Int_Num, u8 Int_Priority)
{
	NVIC_IPR0[Int_Num] = (Int_Priority << 4) ;
}
