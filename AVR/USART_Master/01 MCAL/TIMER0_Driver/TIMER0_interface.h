/*
 * TIMER0_interface.h
 *
 * Created: 6/18/2023 10:59:07 AM
 *  Author: Abdul
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void TIMER0_voidInit(void);

void TIMER0_voidStopTimer(void);

void TIMER0_voidsetCallBackOVF(void (*ptrToFunc) (void));

void TIMER0_voidSetPreloadValue(u8 A_u8PreloadValue);

void TIMER0_voidsetCallBackCTC(void (*ptrToFunc) (void));

void TIMER0_voidSetOCR0Value(u8 A_u8Value);

void SetDutyCycle(u8 Copy_DutyCycleValue);


#endif /* TIMER0_INTERFACE_H_ */