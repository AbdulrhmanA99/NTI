/*
 * Calculator.h
 *
 * Created: 6/22/2023 10:33:57 PM
 *  Author: Abdul
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "../01 MCAL/DIO_Driver/DIO_interface.h"
#include "../01 MCAL/EXT1_Driver/EXT1_interface.h"
#include "../02 HAL/KEYPAD_Driver/HKEYPAD_int.h"
#include "../02 HAL/LCD_Driver/LCD_interface.h"

//states of the calculation
#define equation 0
#define ready 1
#define done 2

//Calculator APIs
u16 add(u16 a, u16 b); //a + b
u16 subtract(u16 a, u16 b); //a - b
u16 multiply(u16 a, u16 b); //a * b
u16 divide(u16 a, u16 b); //a / b
u16 modulus(u16 a, u16 b); //a % b
u8 is_digit(u8 input);  //returns True if input is (0 to 9)
u8 is_operator(u8 input);  //returns True if input is operator (+, -, *, /, %)
u8 is_equal_key(u8 input);  //returns True if input is '='
u8 is_clear_key(u8 input);  //returns True if clear button is pressed
void equal_routine(void);  //ISR when '=' is pressed
void calculate_result(void);  //calculates the result
void calculator_init(void); //app initialization
void calculator_start(void); //app main function


#endif /* CALCULATOR_H_ */