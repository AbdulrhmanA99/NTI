/*
 * STK_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Abdul
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"

#ifndef		NULL
#define		NULL		((void *)0)
#endif

static u8	Mode ;
static void	(* STK_CallBack ) (void) = NULL;

void	STK_voidInit()
{
	/*	Systick Enable & clock source (AHB / 8)	(HSI = 8MHz ==> 1usec)*/
	STK -> CTRL = 0x00000001;
}


void	STK_voidBusyWait(u32 Ticks)
{
	/*	Disable Timer 		*/
	CLR_BIT(STK -> CTRL , 0);
	/*	Load Ticks 			*/
	STK -> LOAD = Ticks;
	/*	Enable Timer		*/
	SET_BIT(STK -> CTRL , 0);
	/*	wait on the flag	*/
	while(GET_BIT(STK -> CTRL , 16) == 0)
	{
		asm("NOP");
	}
	/*	Disable timer		*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD = 0;
	STK -> VAL = 0;
}

void	STK_voidSingleInterval(u32 Ticks , void (*Pf)(void))
{
	/*	Disable Timer 				*/
	CLR_BIT(STK -> CTRL , 0);
	/*	Load Ticks 					*/
	STK -> LOAD = Ticks;
	/*	Set the mode of interrupt	*/
	Mode = SINGLE_INTERVALE;
	/*	Assign Call Back			*/
	STK_CallBack = Pf;
	/*	Enable Interrupt PIE		*/
	SET_BIT(STK -> CTRL , 1);
	/*	Enable Timer				*/
	SET_BIT(STK -> CTRL , 0);
}

void	STK_voidPeriodicInterval(u32 Ticks , void (*Pf)(void))
{
	/*	Disable Timer 			*/
	CLR_BIT(STK -> CTRL , 0);
	/*	Load Ticks 				*/
	STK -> LOAD = Ticks;
	/*	Set the mode of interrupt	*/
	Mode = PERIOD_INTERVALE;
	/*	Assign Call Back			*/
	STK_CallBack = Pf;
	/*	Enable Interrupt PIE	*/
	SET_BIT(STK -> CTRL , 1);
	/*	Enable Timer				*/
	SET_BIT(STK -> CTRL , 0);
}

void	STK_voidStopInterval()
{
	/*	Disable timer		*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD = 0;
	STK -> VAL = 0;
}

void	Systick_Handler(void)
{
	u8 u8Temp = 0;
	if(Mode == SINGLE_INTERVALE)
	{
		/*	Disable Interrupt	*/
			CLR_BIT(STK -> CTRL , 1);
		/*	Disable Timer		*/
			CLR_BIT(STK -> CTRL , 0);
			STK -> LOAD = 0;
			STK -> VAL = 0;
	}
	STK_CallBack();
	/*	Clear Interrupt Flag		*/
	 u8Temp = GET_BIT(STK -> CTRL , 16);
	//return u8Temp;
}

u32  STK_u32GetElapsedTime (void)
{
	return (STK -> LOAD - STK -> VAL);
}
u32  STK_u32GetRemainingTime (void)
{
	return (STK -> VAL);
}
