/*
 * EXTI2_private.h
 *
 * Created: 6/16/2023 7:45:43 PM
 *  Author: Abdul
 */ 


#ifndef EXTI2_PRIVATE_H_
#define EXTI2_PRIVATE_H_


#define MCUCSR_REG  *((volatile u8 *)0x54)

#define GICR_REG    *((volatile u8 *)0x5B)

#define GIFR_REG    *((volatile u8 *)0x5A)


#endif /* EXTI2_PRIVATE_H_ */