/*
 * GIE_program.c
 *
 * Created: 6/16/2023 11:10:04 AM
 *  Author: Abdul
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO_Driver/DIO_interface.h"

#include "GIE_interface.h"
#include "GIE_config.h"
#include "GIE_private.h"

/*
This function is used to Enable The Global Interrupt (GIE)
use this function after any Interrupt initialization
*/

void GIE_voidEnable()
{
	
/*
To Enable The Global Interrupt (GIE)
You must set Bit Number 7 in Status Register - SREG by 1 (I - bit) --> Data Sheet
*/

	SET_BIT(SREG, 7);
	
}

/*
This function is used to Disable The Global Interrupt (GIE)
*/

void GIE_voidDisable()
{
	
/*
To Disable The Global Interrupt (GIE)
You must clear Bit Number 7 in Status Register - SREG by 0 (I - bit) --> Data Sheet
*/	
	CLR_BIT(SREG, 7);
	
}
