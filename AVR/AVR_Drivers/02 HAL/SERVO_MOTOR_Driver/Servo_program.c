/*
 * Servo_program.c
 *
 * Created: 7/6/2023 5:31:09 PM
 * Author: Abdul
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "Servo_interface.h"
#include "Servo_private.h"
#include "Servo_config.h"


void Timer1_init()
{
	CLR_BIT(TCCR1A, 0);
	SET_BIT(TCCR1A, 1);
	SET_BIT(TCCR1B, 3);
	SET_BIT(TCCR1B, 4);
	SET_BIT(TCCR1A, 7);
	CLR_BIT(TCCR1A, 6);
	CLR_BIT(TCCR1B, 0);
	CLR_BIT(TCCR1B, 2);
	SET_BIT(TCCR1B, 1);
}

void SET_TOP_Value(u16 Top_value)
{
	ICR1=Top_value;
}

void SET_OCR_Value(u16 OCR_value)
{
	OCR1=OCR_value;
}

