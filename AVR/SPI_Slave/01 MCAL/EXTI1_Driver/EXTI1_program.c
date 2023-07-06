/*
 * EXTI1_program.c
 *
 * Created: 6/16/2023 7:44:49 PM
 *  Author: Abdul
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO_Driver/DIO_interface.h"

#include "EXTI1_interface.h"
#include "EXTI1_private.h"
#include "EXTI1_config.h"


void (*pf) (void);

void EXTI1_voidInit(void)
{	
	#if EXTI1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR_REG, 2);
	CLR_BIT(MCUCR_REG, 3);
	
	#elif EXTI1_SENSE_MODE == ALC
	SET_BIT(MCUCR_REG, 2);
	CLR_BIT(MCUCR_REG, 3);

	#elif EXTI1_SENSE_MODE == FALLING
	CLR_BIT(MCUCR_REG, 2);
	SET_BIT(MCUCR_REG, 3);
	
	#elif EXTI1_SENSE_MODE == RISING
	SET_BIT(MCUCR_REG, 2);
	SET_BIT(MCUCR_REG, 3);

	#endif
	
	CLR_BIT(GICR_REG, 7);
	SET_BIT(GIFR_REG, 7);	
}

void EXTI1_voidEnable()
{
	
	SET_BIT(GICR_REG, 7);
	
}

void EXTI1_voidDisable()
{
	
	CLR_BIT(GICR_REG, 7);
	
}

void EXTI1_voidCallBack(void (*FuncAdd) (void)) 
{
	if(FuncAdd != NULL)
	{
		pf = FuncAdd;
	}
}

void EXTI1_voidSetSignaLatch(u8 SenseMode) /* To change sense mode while in run-time */
{
	if (SenseMode == LOW_LEVEL)
	{
		CLR_BIT(MCUCR_REG, 2);
		CLR_BIT(MCUCR_REG, 3);
	}

	else if (SenseMode == ALC)
	{
		SET_BIT(MCUCR_REG, 2);
		CLR_BIT(MCUCR_REG, 3);
	}

	else if (SenseMode == FALLING)
	{
		CLR_BIT(MCUCR_REG, 2);
		SET_BIT(MCUCR_REG, 3);
	}

	else if (SenseMode == RISING)
	{
		SET_BIT(MCUCR_REG, 2);
		SET_BIT(MCUCR_REG, 3);
	}
}

void __vector_2(void) __attribute__((signal, used));

void __vector_2(void)
{
	pf();
}
