/*
 * EXTI2_interface.h
 *
 * Created: 6/16/2023 7:45:16 PM
 *  Author: Abdul
 */ 


#ifndef EXTI2_INTERFACE_H_
#define EXTI2_INTERFACE_H_


/* Sense Modes Defines */	
#define FALLING		0
#define RISING		1


void EXTI2_voidInit(void);

void EXTI2_voidEnable(void);

void EXTI2_voidDisable(void);

void EXTI2_voidCallBack(void (*FuncAdd) (void));

void EXTI2_voidSetSignalatch(u8 SenseMode);


#endif /* EXTI2_INTERFACE_H_ */