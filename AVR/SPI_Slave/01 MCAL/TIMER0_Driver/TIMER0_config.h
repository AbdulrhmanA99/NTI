/*
 * TIMER0_config.h
 *
 * Created: 6/18/2023 11:01:55 AM
 *  Author: Abdul
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/*
 * NORMAL_MODE
 * PHASE_CORRECT_MODE
 * CTC_MODE
 * FAST_PWM_MODE
 * */
#define TIMER0_MODE					FAST_PWM_MODE

//NORMAL_DIO
//TOGGLE_CTC
//CLEAR_CTC
//SET_CTC
#define CTC_OC0_PIN_ACTION			NORMAL_DIO


//DIO_NORMAL
//NON_INVERTING
//INVERTING
#define FAST_PWM_OC0_PIn_ACTION		NON_INVERTING

#define OCR0_VALUE	64

/*
 * 0b000  No clock source (Timer/Counter stopped).
 * 0b001  clkI/O /(No prescaling)
 * 0b010  clkI/O /8 (From prescaler)
 * 0b011  clkI/O /64 (From prescaler)
 * 0b100  clkI/O /256 (From prescaler)
 * 0b101  clkI/O /1024 (From prescaler)
 * 0b110  External clock source on T0 pin. Clock on falling edge.
 * 0b111  External clock source on T0 pin. Clock on rising edge.
 * */
#define CLK_CONFIGURATION  0b010 //prescaler of 8


#endif /* TIMER0_CONFIG_H_ */