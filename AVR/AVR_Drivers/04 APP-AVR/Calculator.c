/*
 * Calculator.c
 *
 * Created: 7/5/2023 1:41:14 PM
 *  Author: Abdul
 */ 

	
#if 0

#define F_CPU 16000000UL
//#define F_CPU 8000000UL

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../02 HAL/KEYPAD_Driver/KEYPAD_interface.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"

int main(void)
{
	/* Initializations */
	LCD_voidInit();
	KPD_voidInit();
    /* Signed variables declarations */
	s16 Num1 = 0;
	s16 Num2 = 0;
	s16 result = 0;
	s16 calculation = 0;
	s16 temp;

	while (1) 
	{
		s16 key = KPD_voidGetPressedKey();
		switch (key) 
		{
			case 48: //Ascii for number 0
			case 49: //Number 1
			case 50: //Number 2
			case 51: //Number 3
			case 52: //Number 4
			case 53: //Number 5
			case 54: //Number 6
			case 55: //Number 7
			case 56: //Number 8
			case 57: //Number 9
			
			temp = 48;
			key -= temp;
			
			if (calculation == 0) 
			{  
				/* if no operation(calculation) has been selected
				   then numbers from 0 to 9 is assigned to Num1 */
			
				Num1 = key;
				LCD_voidWriteNumber(Num1);
			} 
				
			else 
			{
			Num2 =  key;
			LCD_voidWriteNumber(Num2);
			}
			break;
			
			case 43: /*Ascii representation for '+' */
			calculation = '+';
			LCD_voidWriteData(calculation);
			break;
			case 45: /*Ascii for '-' */
			calculation = '-';
			LCD_voidWriteData(calculation);
			break;
			case 42: /*Ascii for '*' */
			calculation = '*';
			LCD_voidWriteData(calculation);
			break;
			case 47: /*Ascii for '/' */
			calculation = '/';
			LCD_voidWriteData(calculation);
			break;
			case 67:
			LCD_voidClear();
			break;
			//symbol '=' is represented by ascii value 61
			case 61:
			if (calculation == '+') 
			{
				result = Num1 + Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);
			} 
			else if (calculation == '-') 
			{
				result = Num1 - Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);			
			} 
			else if (calculation == '*') 
			{
				result = Num1 * Num2;
				LCD_voidWriteData('=');
				LCD_voidWriteNumber(result);
			} 
			
			if (calculation == '/') 
			{			
				if (Num2 != 0) 
				{
					result = Num1 / Num2;
					LCD_voidWriteData('=');
					LCD_voidWriteNumber(result);
				
				}
				else if (Num2 == 0) 
				{
					LCD_voidWriteData('=');
					LCD_voidWriteString("MATH ERROR");	
				}
			}
			
			//Reset calculation(operation), Num1, and Num2 variable to their initial values
			calculation = 0;
			Num1 = 0;
			Num2 = 0;
			break;
			default:
			break;
		}
	}
}

#endif
