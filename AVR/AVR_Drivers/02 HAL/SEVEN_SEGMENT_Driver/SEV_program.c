/*
 * SEV_program.c
 *
 * Created: 6/10/2023 9:10:55 PM
 *  Author: Abdul
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../01 MCAL/DIO_Driver/DIO_interface.h"

#include "SEV_interface.h"
#include "SEV_private.h"
#include "SEV_config.h"


void SEV_Initialization()
{	
	DIO_voidSetPinDirection(PORTB_ID, PIN0, PIN_OUTPUT); // A 
	DIO_voidSetPinDirection(PORTB_ID, PIN1, PIN_OUTPUT); // B
	DIO_voidSetPinDirection(PORTB_ID, PIN2, PIN_OUTPUT); // C
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_OUTPUT); // D
	/*
	DIO_voidSetPinDirection(PORTA_ID, PIN3, PIN_OUTPUT); //COM1
	DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_OUTPUT); //COM2
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT); //COM3
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT); //COM4
	*/
}

void SEV_Enable1()
{
	//COM1
	DIO_voidSetPinDirection(PORTA_ID, PIN3, PIN_OUTPUT);
}
void SEV_Enable2()
{
	//COM2
	DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_OUTPUT);
}
void SEV_Enable3()
{
	//COM3
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT);
}
void SEV_Enable4()
{
	//COM4
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT);
}



void SEV_Disable1()
{
	//COM1
	DIO_voidSetPinDirection(PORTA_ID, PIN3, PIN_INPUT);
}
void SEV_Disable2()
{
	//COM2
	DIO_voidSetPinDirection(PORTA_ID, PIN2, PIN_INPUT);
}
void SEV_Disable3()
{
	//COM3
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_INPUT);
}
void SEV_Disable4()
{
	//COM4
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_INPUT);
}

			
void SEV_Write_One_Number(u8 number)
{
	if (number < 10)
	{

		//	3 0b0000 0011
		//			 DCBA
		DIO_voidSetPinValue(PORTB_ID, PIN0, GET_BIT(number, 0)); //A
		DIO_voidSetPinValue(PORTB_ID, PIN1, GET_BIT(number, 1)); //B
		DIO_voidSetPinValue(PORTB_ID, PIN2, GET_BIT(number, 2)); //C
		DIO_voidSetPinValue(PORTB_ID, PIN4, GET_BIT(number, 3)); //D
	}
}

void SEV_Write_Numbers(u16 number)
{
	
	while (1)
	{
		if (number <9999)
		{
			u8  firstNum= number % 10;
			u8  number1= number / 10;
			
			u8  secondNum= number1 % 10;
			u8  number2= number1 /10;
			
			u8  thirdNum= number2 % 10;
			u8  fourthNum= number2 / 10;
			
			SEV_Enable4();			
			SEV_Write_One_Number(firstNum);
			//SEV_Disable4();
			
			SEV_Enable3();
			SEV_Write_One_Number(secondNum);
			//SEV_Disable3();
			
			SEV_Enable2();
			SEV_Write_One_Number(thirdNum);
			//SEV_Disable2();
			
			SEV_Enable1();
			SEV_Write_One_Number(fourthNum);
			//SEV_Disable1();
		}
	}
}