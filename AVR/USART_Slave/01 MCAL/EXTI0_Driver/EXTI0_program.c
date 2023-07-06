/*
 * EXTI0_program.c
 *
 * Created: 6/16/2023 7:44:49 PM
 *  Author: Abdul
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO_Driver/DIO_interface.h"

#include "EXTI0_interface.h"
#include "EXTI0_private.h"
#include "EXTI0_config.h"


void (*pf) (void);

void EXTI0_voidInit(void)
{	
	#if EXTI0_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR_REG, 0);
	CLR_BIT(MCUCR_REG, 1);
	
	#elif EXTI0_SENSE_MODE == ALC
	SET_BIT(MCUCR_REG, 0);
	CLR_BIT(MCUCR_REG, 1);

	#elif EXTI0_SENSE_MODE == FALLING
	CLR_BIT(MCUCR_REG, 0);
	SET_BIT(MCUCR_REG, 1);
	
	#elif EXTI0_SENSE_MODE == RISING
	SET_BIT(MCUCR_REG, 0);
	SET_BIT(MCUCR_REG, 1);

	#endif
	
	CLR_BIT(GICR_REG, 6);
	SET_BIT(GIFR_REG, 6);	
}

void EXTI0_voidEnable()
{
	
	SET_BIT(GICR_REG, 6);
	
}

void EXTI0_voidDisable()
{
	
	CLR_BIT(GICR_REG, 6);
	
}

void EXTI0_voidCallBack(void (*FuncAdd) (void))
{
	if(FuncAdd != NULL)
	{
		pf = FuncAdd;
	}
}

void EXTI0_voidSetSignaLatch(u8 SenseMode) /* To change sense mode while in run-time */
{
	if (SenseMode == LOW_LEVEL)
	{
		CLR_BIT(MCUCR_REG, 0);
		CLR_BIT(MCUCR_REG, 1);
	}

	else if (SenseMode == ALC)
	{
		SET_BIT(MCUCR_REG, 0);
		CLR_BIT(MCUCR_REG, 1);
	}

	else if (SenseMode == FALLING)
	{
		CLR_BIT(MCUCR_REG, 0);
		SET_BIT(MCUCR_REG, 1);
	}

	else if (SenseMode == RISING)
	{
		SET_BIT(MCUCR_REG, 0);
		SET_BIT(MCUCR_REG, 1);
	}
}

void __vector_1(void) __attribute__((signal, used));

void __vector_1(void)
{
	pf();
}
