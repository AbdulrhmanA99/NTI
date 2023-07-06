/*
 * KEYPAD_interface.h
 *
 * Created: 6/12/2023 9:43:26 AM
 *  Author: Abdul
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


/*
 * 
 *  	-> initialize the Keypad & sets all Rows as i/P
 *  	   and all Columns as Pulled-up I/P.
 */
void KPD_voidInit(void);

/*
 *  	-> returns the value of the pressed key
 *  	   or KPD_NOT_PRESSED otherwise.
 */
u8 KPD_voidGetPressedKey(void);


#endif /* KEYPAD_INTERFACE_H_ */