/*
 * GIE_interface.h
 *
 * Created: 6/16/2023 11:10:31 AM
 *  Author: Abdul
 */ 


#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_


/*
This function is used to Enable The Global Interrupt (GIE)			 
use this function after any Interrupt initialization
*/

void GIE_voidEnable();

/*
This function is used to Disable The Global Interrupt (GIE)
*/

void GIE_voidDisable();


#endif /* GIE_INTERFACE_H_ */