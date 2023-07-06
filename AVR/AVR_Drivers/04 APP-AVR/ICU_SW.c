/*
 * ICU_SW.c
 *
 * Created: 7/1/2023 2:07:33 AM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../01 MCAL/GIE_Driver/GIE_interface.h"
#include "../01 MCAL/EXTI0_Driver/EXTI0_interface.h"
#include "../01 MCAL/TIMER0_Driver/TIMER0_interface.h"
#include "../01 MCAL/TIMER1_Driver/TIMER1_interface.h"
		  
#include "../02 HAL/LCD_Driver/LCD_interface.h"


static u16 global_u16PeriodTicks=0;
static u16 global_u16OnTicks=0;
void ICU_SW (void);

/*Connect PD2 and PB3 via a Jumper*/

int main(void)
{
	LCD_voidInit();
	EXTI0_voidCallBack(ICU_SW);
	EXTI0_voidInit();
	EXTI0_voidSetSignaLatch(RISING);
	EXTI0_voidEnable();
	GIE_voidEnable();
	TIMER1_voidInit();
	TIMER0_voidInit();
	while (1)
	{
		while (global_u16PeriodTicks==0 || global_u16OnTicks==0)
		{
		LCD_voidGoToXY(1, 1);
		LCD_voidWriteString("->");
		LCD_voidWriteNumber(global_u16PeriodTicks);
		LCD_voidGoToXY(2, 1);
		LCD_voidWriteString("->");
		LCD_voidWriteNumber(global_u16OnTicks);
		}
	}
}

void ICU_SW (void)
{
	static u8 local_u8Counter=0;
	local_u8Counter++;
	if (local_u8Counter==1)
	{
		// First Rising edge
		TIMER1_voidSetTimer1Value(0);
	}
	else if (local_u8Counter==2)
	{
		// Second Rising edge
		global_u16PeriodTicks= TIMER1_u16ReadTimer1Value();
		EXTI0_voidSetSignaLatch(FALLING);
	}
	else if (local_u8Counter==3)
	{
		// First Falling edge
		global_u16OnTicks= TIMER1_u16ReadTimer1Value();
		global_u16OnTicks-=global_u16PeriodTicks;
		EXTI0_voidDisable();
		local_u8Counter=0;
	}
}
#endif