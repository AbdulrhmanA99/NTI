/*
 * WDT_program.c
 *
 * Created: 7/5/2023 11:52:03 PM
 * Author: Abdul
 */ 

// Libraries
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// MCAL
#include "WDT_interface.h"
#include "WDT_config.h"
#include "WDT_private.h"


// Enable Watch Dog Timer: Start counting till timeout (reset MCU)
void WDT_voidEnable(void)
{
	SET_BIT(WDTCR, WDTCR_WDE);	
}

// Disable Watch Dog Timer: Stop counting time.
void WDT_voidDisable(void)
{
	
	/* WDT Disable Sequence (See data sheet):
	 * 1. Set the WDE and WDTOE to 1 at the same operation.
	 * 2. Write 0 on the WDE bit in the next 4 clock cycles.
	 */
	
	WDTCR = 0b00011000;
	WDTCR = 0;
	
}

// WDT Pre-scaler Select: Each pre-scaler maps to a specific timeout value (sleep time).
// Input argument from 1 : 7 (in binary -> 000,001,010,011,100,101,110,111)
//(each value maps to a specific timeout value (sleep time).
void WDT_voidSleep(u8 copy_u8SleepTime)
{
	
	if(copy_u8SleepTime < 8)
	{
		// Bit masking Sequence:
		// 1. clear the desired bits
		// 2. Put the required value in it
		WDTCR &= 0b01111000;
		WDTCR |= copy_u8SleepTime;
		
	}
}

