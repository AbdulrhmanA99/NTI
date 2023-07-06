/*
 * TIMER0_program.h
 *
 * Created: 6/18/2023 10:47:06 AM
 *  Author: Abdul
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"


void (*TIMER0_OVF_CallBack)(void)= NULL;
void (*TIMER0_CTC_CallBack)(void)= NULL;

void TIMER0_voidInit(void)
{
	#if TIMER0_MODE == NORMAL_MODE
	// Set wave Generation Mode to Normal Mode
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	// Turn on Overflow Interrupt
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);
	// Start Timer by setting its clock
	TCCR0 &= 0b11111000;
	TCCR0 |= CLK_CONFIGURATION;
	#elif TIMER0_MODE == PHASE_CORRECT_MODE

	#elif TIMER0_MODE == CTC_MODE
	// Set wave Generation Mode to CTC Mode
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	// Turn on CTC Interrupt
	SET_BIT(TIMSK,1);
	CLR_BIT(TIMSK,0);
	// Set Compare Match Unit Value
	OCR0=OCR0_VALUE;
	// Start Timer by setting its clock and Set OC0 Pin Action
	TCCR0 &= 0b11001000;
	TCCR0 |= (CLK_CONFIGURATION|(CTC_OC0_PIN_ACTION<<4));
	#elif TIMER0_MODE == FAST_PWM_MODE
	// Set wave Generation Mode to Fast PWM Mode
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	// Set Compare Match Unit Value
	OCR0=OCR0_VALUE;
	// Start Timer by setting its clock and Set OC0 Pin Action
	TCCR0 &= 0b11001000;
	TCCR0 |= (CLK_CONFIGURATION|(FAST_PWM_OC0_PIn_ACTION<<4));

	#else
	#error  Wrong TIMER0 Mode Configuration
	#endif

}

void TIMER0_voidStopTimer(void)
{
	// Stop Clock of Timer 0
	TCCR0 &= 0b11111000;
}

void TIMER0_voidsetCallBackOVF(void (*ptrToFunc) (void))
{
	if (ptrToFunc!=NULL)
	{
		TIMER0_OVF_CallBack=ptrToFunc;
	}
}

void TIMER0_voidsetCallBackCTC(void (*ptrToFunc) (void))
{
	if (ptrToFunc!=NULL)
	{
		TIMER0_CTC_CallBack=ptrToFunc;
	}
}

void TIMER0_voidSetPreloadValue(u8 A_u8PreloadValue)
{
	TCNT0=A_u8PreloadValue;
}

void TIMER0_voidSetOCR0Value(u8 A_u8Value)
{
	OCR0=A_u8Value;
}

void SetDutyCycle(u8 Copy_DutyCycleValue) /* Used in pwm mode */
{
	OCR0 = ((float)Copy_DutyCycleValue/100)*256;
}

void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_CallBack!= NULL)
	{
		TIMER0_OVF_CallBack();
	}
}

void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_CallBack!= NULL)
	{
		TIMER0_CTC_CallBack();
	}
}
