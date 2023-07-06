/*
 * EXTI2_program.c
 *
 * Created: 6/16/2023 7:44:49 PM
 *  Author: Abdul
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO_Driver/DIO_interface.h"

#include "EXTI2_interface.h"
#include "EXTI2_private.h"
#include "EXTI2_config.h"


void (*pf) (void);

void EXTI2_voidInit(void)
{	
	#if EXTI2_SENSE_MODE == FALLING
	CLR_BIT(MCUCSR_REG, 6);
	
	#elif EXTI2_SENSE_MODE == RISING
	SET_BIT(MCUCSR_REG, 6);

	#endif
	
	CLR_BIT(GICR_REG, 5);
	SET_BIT(GIFR_REG, 5);	
}

void EXTI2_voidEnable()
{
	
	SET_BIT(GICR_REG, 5);
	
}

void EXTI2_voidDisable()
{
	
	CLR_BIT(GICR_REG, 5);
	
}

void EXTI2_voidCallBack(void (*FuncAdd) (void))
{
	if(FuncAdd != NULL)
	{
		pf = FuncAdd;
	}
}

void EXTI2_voidSetSignaLatch(u8 SenseMode) /* To change sense mode while in run-time */
{
	if (SenseMode == FALLING)
	{
		CLR_BIT(MCUCSR_REG, 6);
	}

	else if (SenseMode == RISING)
	{
		SET_BIT(MCUCSR_REG, 6);
	}

}

void __vector_3(void) __attribute__((signal, used));

void __vector_3(void)
{
	pf();
}
