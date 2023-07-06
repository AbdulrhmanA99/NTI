/*
 * ICU_HW_App.c
 *
 * Created: 7/1/2023 2:11:52 AM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../01 MCAL/GIE_Driver/GIE_interface.h"
#include "../01 MCAL/TIMER0_Driver/TIMER0_interface.h"
#include "../01 MCAL/TIMER1_Driver/TIMER1_interface.h"
		  
#include "../02 HAL/LCD_Driver/LCD_interface.h"


static u16 global_u16PeriodTicks=0;
static u16 global_u16OnTicks=0;
void ICU_HW (void);

int main(void)
{
	LCD_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	TIMER1_voidICUSetTrigger(ICU_RISING_EDGE);
	TIMER1_voidICUSetCallBack(ICU_HW);
	TIMER1_voidICUInit();
	GIE_voidEnable();
	while (1)
	{

	}
}

void ICU_HW (void)
{
	static u8 local_u8Counter=0;
	static u8 local_u8Reading1=0;
	static u8 local_u8Reading2=0;
	static u8 local_u8Reading3=0;
	local_u8Counter++;
	if (local_u8Counter==1)
	{
		// First Rising edge
		local_u8Reading1 = TIMER1_u16ReadICU();

	}
	else if (local_u8Counter==2)
	{
		local_u8Reading2 = TIMER1_u16ReadICU();
		TIMER1_voidICUSetTrigger(ICU_FALLING_EDGE);
		global_u16PeriodTicks = local_u8Reading2-local_u8Reading1;

	}
	else if (local_u8Counter==3)
	{
		local_u8Reading3 = TIMER1_u16ReadICU();
		global_u16OnTicks = local_u8Reading3-local_u8Reading2;
		TIMER1_voidICUDisableINT();
		LCD_voidGoToXY(1, 1);
		LCD_voidWriteString("->");
		LCD_voidWriteNumber(global_u16PeriodTicks);
		LCD_voidGoToXY(2, 1);
		LCD_voidWriteString("->");
		LCD_voidWriteNumber(global_u16OnTicks);
	}
}

#endif