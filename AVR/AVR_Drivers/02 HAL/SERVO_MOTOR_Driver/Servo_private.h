/*
 * Servo_private.h
 *
 * Created: 7/6/2023 5:31:09 PM
 * Author: Abdul
 */ 


#ifndef SERVO_PRIVATE_H_
#define SERVO_PRIVATE_H_

#define TCCR1A *((volatile u8* )0x4F)
#define TCCR1B *((volatile u8* )0x4E)
#define ICR1   *((volatile u16*)0x46)
#define OCR1   *((volatile u16*)0x4A)


#endif /* SERVO_PRIVATE_H_ */