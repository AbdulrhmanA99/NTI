/*
 * DIO_program.c
 *
 * Created: 6/11/2023 1:45:56 PM
 *  Author: Abdul
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"


u8 GPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorStatus = 0 ;

	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=15)
	{
		/*if the pin is selected as output push pull*/
		if (Copy_u8Direction == GPIO_OUTPUT_PP)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOA_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOA_OTYPER &= ~( 1 << Copy_u8Pin) ;
			break;

			case GPIO_B : GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOB_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOB_OTYPER &= ~( 1 << Copy_u8Pin) ;break;

			case GPIO_C : GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOC_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOC_OTYPER &= ~( 1 << Copy_u8Pin) ;
			break;

			case GPIO_D : GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOD_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOD_OTYPER &= ~( 1 << Copy_u8Pin) ;
			break;
			default 	: Local_u8ErrorStatus = 1 ;		break;
			}
		}

		/*if the pin is selected as output open drain*/
		else if (Copy_u8Direction == GPIO_OUTPUT_OD)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOA_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOA_OTYPER |= ( 1 << Copy_u8Pin) ;
			break;

			case GPIO_B : GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOB_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOB_OTYPER |= ( 1 << Copy_u8Pin) ;break;

			case GPIO_C : GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOC_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOC_OTYPER |= ( 1 << Copy_u8Pin) ;
			break;

			case GPIO_D : GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
			GPIOD_MODER |= ( 0b01 << (Copy_u8Pin*2) );
			GPIOD_OTYPER |= ( 1 << Copy_u8Pin) ;
			break;
			default 	: Local_u8ErrorStatus = 1 ;		break;
			}
		}

		/*if the pin is selected as input pull up*/
		else if (Copy_u8Direction == GPIO_INPUT_PU)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR |= (0b01 << (Copy_u8Pin*2));
			break;

			case GPIO_B : GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR |= (0b01 << (Copy_u8Pin*2));
			break;

			case GPIO_C : GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR |= (0b01 << (Copy_u8Pin*2));
			break;

			case GPIO_D : GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR |= (0b01 << (Copy_u8Pin*2));
			break;

			default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}

		/*if the pin selected is input pull down*/
		else if (Copy_u8Direction == GPIO_INPUT_PD)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR |= (0b10 << (Copy_u8Pin*2));
			break;

			case GPIO_B : GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR |= (0b10 << (Copy_u8Pin*2));
			break;

			case GPIO_C : GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR |= (0b10 << (Copy_u8Pin*2));
			break;

			case GPIO_D : GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR |= (0b10 << (Copy_u8Pin*2));
			break;

			default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}
		/*if the pin selected is input floating*/
		else if (Copy_u8Direction == GPIO_INPUT_F)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOA_PUPDR |= (0b00 << (Copy_u8Pin*2));
			break;

			case GPIO_B : GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOB_PUPDR |= (0b00 << (Copy_u8Pin*2));
			break;

			case GPIO_C : GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOC_PUPDR |= (0b00 << (Copy_u8Pin*2));
			break;

			case GPIO_D : GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
			GPIOD_PUPDR |= (0b00 << (Copy_u8Pin*2));
			break;

			default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}

		/*if the pin selected is analog*/
		else if (Copy_u8Direction == GPIO_ANALOG)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : GPIOA_MODER |= ( 0b11 << (Copy_u8Pin*2));
			break;

			case GPIO_B : GPIOB_MODER |= ( 0b11 << (Copy_u8Pin*2));
			break;

			case GPIO_C : GPIOC_MODER |= ( 0b11 << (Copy_u8Pin*2));
			break;

			case GPIO_D : GPIOD_MODER |= ( 0b11 << (Copy_u8Pin*2));
			break;

			default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}

		/*if the pin is selected as Alternate function*/
		else if (Copy_u8Direction >= GPIO_AF0 && Copy_u8Direction <= GPIO_AF15)
		{
			if (Copy_u8Pin >= GPIO_PIN0 && Copy_u8Pin<= GPIO_PIN7)
			{
				switch(Copy_u8Port)
				{
				case GPIO_A : GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOA_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOA_AFRL &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOA_AFRL |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_B : GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOB_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOB_AFRL &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOB_AFRL |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_C : GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOC_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOC_AFRL &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOC_AFRL |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_D : GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOD_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOD_AFRL &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOD_AFRL |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				default 	: Local_u8ErrorStatus = 1 ;		break;
				}
			}
			else if (Copy_u8Pin >= GPIO_PIN8 && Copy_u8Pin<= GPIO_PIN15)
			{
				switch(Copy_u8Port)
				{
				case GPIO_A : GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOA_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOA_AFRH &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOA_AFRH |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_B : GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOB_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOB_AFRH &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOB_AFRH |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_C : GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOC_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOC_AFRH &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOC_AFRH |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				case GPIO_D : GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
				GPIOD_MODER |= ( 0b10 << (Copy_u8Pin*2) );
				GPIOD_AFRH &= ~(0b1111 << (Copy_u8Pin*4));
				GPIOD_AFRH |= (Copy_u8Direction<<(Copy_u8Pin*4));
				break;

				default 	: Local_u8ErrorStatus = 1 ;		break;
				}
			}
		}

		/*if the parameter invalid*/
		else
		{
			Local_u8ErrorStatus = 1 ;
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;

}
u8 GPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorStatus = 0 ;

	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=15)
	{
		/*if the pin is selected as high*/
		if (Copy_u8Value == GPIO_HIGH)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : SET_BIT(GPIOA_ODR , Copy_u8Pin); break;
			case GPIO_B : SET_BIT(GPIOB_ODR , Copy_u8Pin); break;
			case GPIO_C : SET_BIT(GPIOC_ODR , Copy_u8Pin); break;
			case GPIO_D : SET_BIT(GPIOD_ODR , Copy_u8Pin); break;
			default 	: Local_u8ErrorStatus = 1 ;		   break;
			}
		}
		/*if the pin is selected as low*/
		else if (Copy_u8Value == GPIO_LOW)
		{
			switch(Copy_u8Port)
			{
			case GPIO_A : CLR_BIT(GPIOA_ODR , Copy_u8Pin); break;
			case GPIO_B : CLR_BIT(GPIOB_ODR , Copy_u8Pin); break;
			case GPIO_C : CLR_BIT(GPIOC_ODR , Copy_u8Pin); break;
			case GPIO_D : CLR_BIT(GPIOD_ODR , Copy_u8Pin); break;
			default 	: Local_u8ErrorStatus = 1 ;	       break;
			}
		}
		/*if the parameter invalid*/
		else
		{
			Local_u8ErrorStatus = 1 ;
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}

	return Local_u8ErrorStatus ;
}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_u8Result)
{
	u8 Local_u8ErrorStatus;
	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=7)
	{
		switch(Copy_u8Port)
		{
		case GPIO_A : *Copy_u8Result = GET_BIT(GPIOA_IDR , Copy_u8Pin);	break;		/*read the desired pin of port A */
		case GPIO_B : *Copy_u8Result = GET_BIT(GPIOB_IDR , Copy_u8Pin);	break;		/*read the desired pin of port B */
		case GPIO_C : *Copy_u8Result = GET_BIT(GPIOC_IDR , Copy_u8Pin);	break;      /*read the desired pin of port C */
		case GPIO_D : *Copy_u8Result = GET_BIT(GPIOD_IDR , Copy_u8Pin);	break;      /*read the desired pin of port D */
		default 	: Local_u8ErrorStatus = 1 ;							break;      /*the port parameter is invalid  */
		}
	}
	/*if the parameter invalid*/
	else
	{
		Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;
}

u8 GPIO_u8TogPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	u8 Local_u8ErrorStatus =0;
	/*if the parameter passed is in the valid range*/
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=15)
	{
		switch(Copy_u8Port)
		{
		case GPIO_A : TOG_BIT(GPIOA_ODR , Copy_u8Pin);break;
		case GPIO_B : TOG_BIT(GPIOB_ODR , Copy_u8Pin);break;
		case GPIO_C : TOG_BIT(GPIOC_ODR , Copy_u8Pin);break;
		case GPIO_D : TOG_BIT(GPIOD_ODR , Copy_u8Pin);break;
		default 	: Local_u8ErrorStatus = 1 ;		  break;
		}
	}
	return Local_u8ErrorStatus;
}


	/*

u8 DIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	u8 Local_u8ErrorStatus = 0 ;

	if the parameter passed is in the valid range
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=15)
	{
		if the pin is selected as output
		if (Copy_u8Direction == GPIO_OUTPUT_PP)
		{
			switch(Copy_u8Port)
			{
				case GPIO_A : GPIOA_MODER &= 0xFF ;
				              GPIOA_OTYPER &= 0xFF ;
							  GPIOA_MODER =  0x55555555 ;
							  GPIOA_OTYPER = 0x0000FFFF ;
							  break;
				case GPIO_B : break;
				case GPIO_C : break;
				case GPIO_D : break;
				default 	: Local_u8ErrorStatus = 1 ;		break;
			}
		}
		if the pin is selected as input
		else if (Copy_u8Direction == GPIO_INPUT_PU)
		{
			switch(Copy_u8Port)
			{
				case GPIO_A : GPIOA_MODER &= 0xFF ;
							  GPIOA_PUPDR &= 0xFF ;
                     		  GPIOA_MODER &= ( 0b00 << (Copy_u8Pin*2) );
					 		  GPIOA_MODER &= ( 0b01 << (Copy_u8Pin*2) );
				     		   break;
				case GPIO_B : CLR_BIT(DDRB , Copy_u8Pin);	break;
				case GPIO_C : CLR_BIT(DDRC , Copy_u8Pin);	break;
				case GPIO_D : CLR_BIT(DDRD , Copy_u8Pin);	break;
				default 	   : Local_u8ErrorStatus = 1 ; 		break;
			}
		}
		if the parameter invalid
		else
		{
				Local_u8ErrorStatus = 1 ;
		}
	}
	if the parameter invalid
	else
	{
		Local_u8ErrorStatus = 1 ;
	}

	return Local_u8ErrorStatus ;
}

	 */


	/*

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_u8Result)
{
	u8 Local_u8ErrorStatus;
	if the parameter passed is in the valid range
	if ( Copy_u8Pin>=0 && Copy_u8Pin <=7)
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA : *Copy_u8Result = GET_BIT(PINA , Copy_u8Pin);	break;		read the disered pin of port A
			case DIO_PORTB : *Copy_u8Result = GET_BIT(PINB , Copy_u8Pin);	break;		read the disered pin of port B
			case DIO_PORTC : *Copy_u8Result = GET_BIT(PINC , Copy_u8Pin);	break;      read the disered pin of port C
			case DIO_PORTD : *Copy_u8Result = GET_BIT(PIND , Copy_u8Pin);	break;      read the disered pin of port D
			default 	   : Local_u8ErrorStatus = 1 ;						break;      the port parameter is invalid
		}
	}
	if the parameter invalid
	else
	{
		Local_u8ErrorStatus = 1 ;
	}
	return Local_u8ErrorStatus ;
}




u8 DIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_u8Result)
{

	u8 Local_u8ErrorStatus = 0 ;

	switch(Copy_u8Port)
		{
			case DIO_PORTA : *Copy_u8Result = PINA ;	break;		read the value to the port A
			case DIO_PORTB : *Copy_u8Result = PINB ;	break;		read the value to the port B
			case DIO_PORTC : *Copy_u8Result = PINC ;	break;      read the value to the port C
			case DIO_PORTD : *Copy_u8Result = PIND ;	break;      read the value to the port D
			default 	   : Local_u8ErrorStatus = 1 ;	break;      the port parameter is invalid
		}
	return Local_u8ErrorStatus ;
}

	 */
