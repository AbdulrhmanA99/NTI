/*
 * TIMER0_private.h
 *
 * Created: 6/18/2023 11:01:40 AM
 *  Author: Abdul
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define TCCR0					(*(volatile u8 *)0x53)
#define TCNT0					(*(volatile u8 *)0x52)
#define OCR0					(*(volatile u8 *)0x5C)
#define TIMSK					(*(volatile u8 *)0x59)
#define TIFR					(*(volatile u8 *)0x58)

#define NORMAL_MODE				0
#define PHASE_CORRECT_MODE		1
#define CTC_MODE				2
#define FAST_PWM_MODE			3

#define NORMAL_DIO				0b00
#define TOGGLE_CTC				0b01
#define CLEAR_CTC				0b10
#define SET_CTC					0b11

#define DIO_NORMAL				0
#define NON_INVERTING			2
#define INVERTING				3


#endif /* TIMER0_PRIVATE_H_ */