/*
 * EXTI1_interface.h
 *
 * Created: 6/16/2023 7:45:16 PM
 *  Author: Abdul
 */ 


#ifndef EXTI1_INTERFACE_H_
#define EXTI1_INTERFACE_H_


/* Sense Modes Defines */	
#define LOW_LEVEL	0
#define ALC			1
#define FALLING		2
#define RISING		3


void EXTI1_voidInit(void);

void EXTI1_voidEnable(void);

void EXTI1_voidDisable(void);

void EXTI1_voidCallBack(void (*FuncAdd) (void));

void EXTI1_voidSetSignaLatch(u8 SenseMode);


#endif /* EXTI1_INTERFACE_H_ */