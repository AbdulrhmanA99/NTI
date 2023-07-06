/*
 * TIMER1_private.h
 *
 * Created: 6/18/2023 11:01:40 AM
 *  Author: Abdul
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_


#define ICU_FALLING_EDGE  0
#define ICU_RISING_EDGE   1


#define TCCR1A (*(volatile u8  *)0x4F)
#define TCCR1B (*(volatile u8  *)0x4E)
#define TCNT1H (*(volatile u8  *)0x4D)
#define TCNT1L (*(volatile u8  *)0x4C)
#define TCNT1  (*(volatile u16 *)0x4C)
#define OCR1A  (*(volatile u16 *)0x4A)
#define OCR1B  (*(volatile u8  *)0x48)
#define ICR1H  (*(volatile u8  *)0x47)
#define ICR1L  (*(volatile u8  *)0x46)
#define ICR1   (*(volatile u16 *)0x46)
#define TIMSK  (*(volatile u8  *)0x59)
#define TIFR   (*(volatile u8  *)0x58)


#endif /* TIMER1_PRIVATE_H_ */