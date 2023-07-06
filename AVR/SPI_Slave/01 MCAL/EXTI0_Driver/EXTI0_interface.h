/*
 * EXTI0_interface.h
 *
 * Created: 6/16/2023 7:45:16 PM
 *  Author: Abdul
 */ 


#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_


/* Sense Modes Defines */	
#define LOW_LEVEL	0
#define ALC			1
#define FALLING		2
#define RISING		3


void EXTI0_voidInit(void);

void EXTI0_voidEnable(void);

void EXTI0_voidDisable(void);

void EXTI0_voidCallBack(void (*FuncAdd) (void));

void EXTI0_voidSetSignaLatch(u8 SenseMode);


#endif /* EXTI0_INTERFACE_H_ */