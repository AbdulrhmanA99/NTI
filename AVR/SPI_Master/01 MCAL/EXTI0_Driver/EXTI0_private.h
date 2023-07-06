/*
 * EXTI0_private.h
 *
 * Created: 6/16/2023 7:45:43 PM
 *  Author: Abdul
 */ 


#ifndef EXTI0_PRIVATE_H_
#define EXTI0_PRIVATE_H_


#define MCUCR_REG   *((volatile u8 *)0x55)

#define GICR_REG    *((volatile u8 *)0x5B)

#define GIFR_REG    *((volatile u8 *)0x5A)


#endif /* EXTI0_PRIVATE_H_ */