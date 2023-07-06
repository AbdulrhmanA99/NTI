/*
 * TIMER1_program.h
 *
 * Created: 6/18/2023 10:47:06 AM
 *  Author: Abdul
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_config.h"
#include "TIMER1_private.h"


void (*TIMER1_ICU_CallBack)(void)= NULL;

void TIMER1_voidInit(void)
{
	/*Set prescaler of 8*/
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void TIMER1_voidSetTimer1Value(u16 A_u16Value)
{
	TCNT1 = A_u16Value;
}

u16  TIMER1_u16ReadTimer1Value(void)
{
	return TCNT1;
}

void TIMER1_voidSetCR1AValue(u8 A_u8Value)
{
	OCR1A=A_u8Value;
}

void TIMER1_voidICUInit(void)
{
	// Set Trigger to Rising Initially
	SET_BIT(TCCR1B, 6);
	// Enable ICU Interrupt
	SET_BIT(TIMSK, 5);
}

void TIMER1_voidICUSetCallBack(void (*ptrToFunc) (void))
{
	if (ptrToFunc!= NULL)
	{
		TIMER1_ICU_CallBack=ptrToFunc;
	}
}
/*
void TIMER1_voidICUSetTrigger(u8 u8Trigger)
{
	if (u8Trigger == ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B, 6);
	}

	else if (u8Trigger == ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B, 6);
	}

}
*/
void TIMER1_voidICUSetTrigger(u8 u8Trigger)
{
	switch (u8Trigger)
	{
		case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,6); break;
		case ICU_RISING_EDGE  : SET_BIT(TCCR1B,6); break;

	}
}

u16 TIMER1_u16ReadICU(void)
{
	return ICR1;
}

void TIMER1_voidICUDisableINT(void)
{
	// Disable ICU Interrupt
	CLR_BIT(TIMSK,5);
}

void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if (TIMER1_ICU_CallBack!= NULL)
	{
		TIMER1_ICU_CallBack();
	}
}
