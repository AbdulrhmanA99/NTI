/*
 * Calculator.c
 *
 * Created: 6/22/2023 10:16:17 PM
 *  Author: Abdul
 */ 

#if 0

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../02 HAL/KEYPAD_Driver/HKEYPAD_int.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"

#include "Calculator.h"


//Keypad keys chars
u8 keys[] = {	'7', '8', '9', '/',
	'4', '5', '6', '*',
	'1', '2', '3', '-',
'C', '0', '%', '+'};

u16 num1 = 0; //first number
u16 num2 = 0; //second number
u8 operator = 0; //operator
u8 result[16]; //result string
u8 state = equation; //equation state
u8 input = 0; //input char


u16 add(u16 a, u16 b){
	return (a + b);
}

u16 subtract(u16 a, u16 b){
	return ((s16)(a - b));
}

u16 multiply(u16 a, u16 b){
	return (a * b);
}

u16 divide(u16 a, u16 b){
	return (a / b);
}

u16 modulus(u16 a, u16 b){
	return (a % b);
}

u8 is_digit(u8 input){
	if(input >= '0' && input <='9') return 1;
	else return 0;
}

u8 is_operator(u8 input){
	if(input == '+' || input =='-' || input =='*' || input =='/' || input =='%') return 1;
	else return 0;
}

u8 is_equal_key(u8 input){
	if(input == '=') return 1;
	else return 0;
}

u8 is_clear_key(u8 input){
	if(input == 'C') return 1;
	else return 0;
}

void equal_routine(void){
	LCD_voidWriteData('=');
	state = ready;
}

void calculate_result(void){
	switch(operator){
		case '+':
		sprintf(result, "%d", add(num1, num2));
		break;
		
		case '-':
		sprintf(result, "%d", subtract(num1, num2));
		break;
		
		case '*':
		sprintf(result, "%d", multiply(num1, num2));
		break;
		
		case '/':
		sprintf(result, "%d", divide(num1, num2));
		break;
		
		case '%':
		sprintf(result, "%d", modulus(num1, num2));
		break;
		
		default:
		sprintf(result, "%d", num1);
		break;
	}
}

void calculator_init(void){
	
	DIO_voidSetPinValue(PORTD_ID,PIN2 ,PIN_HIGH);
	HKEYPAD_enInit(void);  //keypad initialization
	LCD_voidInit(void); //LCD initialization in 4-bit mode
	EXT1_voidInit(void); //external interrupt initialization
	EXT1_voidEnable(void);  //external interrupt enable
	EXT1_voidCallBack(); //setting ISR
	EXT1_voidSetSignalch();
}

void calculator_start(void){
	input = HKEYPAD_enGetPressedKey2(void);
	
	//clearing the screen and reseting numbers to 0
	if(is_clear_key(keys[input])){
		LCD_voidClear();
		num1 = 0;
		num2 = 0;
		operator = 0;
		state = equation;
	}
	
	else if(is_digit(keys[input]) && (state == equation)){
		LCD_voidWriteData(keys[input]);
		
		if(operator==0){
			num1*=10;
			num1+=keys[input];
			num1-='0';
		}
		
		else if(operator!=0){
			num2*=10;
			num2+=keys[input];
			num2-='0';
		}
	}
	
	else if(is_operator(keys[input]) && (state == equation)){
		LCD_voidWriteData(keys[input]);
		operator = keys[input];
	}
	
	if(state == ready){
		calculate_result();
		LCD_voidWriteString(result);
		state = done;
	}
}
#endif
