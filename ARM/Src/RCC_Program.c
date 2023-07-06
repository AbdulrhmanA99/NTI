/*
 * RCC_Program.c
 *
 *  Created on: Jun 23, 2023
 *      Author: Abdul
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"


void RCC_voidSysClkInit(void)
{
	/*RCC_CR*/
	#if RCC_CLOCK_SOURCE == RCC_HSI
	SET_BIT(RCC_CR , 0);
	CLR_BIT(RCC_CFGR , 0);
	CLR_BIT(RCC_CFGR , 1);

	#elif RCC_CLOCK_SOURCE == RCC_HSE
	SET_BIT(RCC_CR , 16);
	SET_BIT(RCC_CFGR , 0);
	CLR_BIT(RCC_CFGR , 1);


	#elif RCC_CLOCK_SOURCE == RCC_PLL
	/*Set div factor*/
	RCC_PLLCFGR &= PLLM_MASK ;
	RCC_PLLCFGR |= PLLM  ;

	/*set mul factor*/
	RCC_PLLCFGR &= PLLN_MASK ;
	RCC_PLLCFGR |= (PLLN <<6) ;

	/*Set div factor*/
	RCC_PLLCFGR &= PLLP_MASK ;
	RCC_PLLCFGR |= PLLP<16  ;

	/*Enable PLL*/
	SET_BIT(RCC_CR , 24);
	CLR_BIT(RCC_CFGR , 0);
	SET_BIT(RCC_CFGR , 1);
	#endif

	/*AHB1 Bus Speed*/
	RCC_CFGR &= AHB1_MASK ;
	RCC_CFGR |= (AHB1_PRESCALER<<4);

	/*APB1 Bus Speed*/
	RCC_CFGR &= APB1_MASK ;
	RCC_CFGR |= (APB1_PRESCALER<<10);

	/*APB2 Bus Speed*/
	RCC_CFGR &= APB2_MASK ;
	RCC_CFGR |= (APB2_PRESCALER<<13);
}

void RCC_voidEnablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8BusId < 3 && Copy_u8PerId < 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 :	SET_BIT(RCC_AHB1ENR , Copy_u8PerId); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_u8PerId); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_u8PerId); break;
			default : break;
		}
	}
	else
	{
		/*Report Error*/
	}
}

void RCC_voidDisablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	/*Range Check*/
	if (Copy_u8BusId < 3 && Copy_u8PerId < 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 :	CLR_BIT(RCC_AHB1ENR , Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8PerId); break;
			default : break;
		}
	}
	else
	{
		/*Report Error*/
	}
}
