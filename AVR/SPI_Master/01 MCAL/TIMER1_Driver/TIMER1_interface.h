/*
 * TIMER1_interface.h
 *
 * Created: 6/18/2023 10:59:07 AM
 *  Author: Abdul
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


void TIMER1_voidInit(void);

void TIMER1_voidSetTimer1Value(u16 A_u16Value);

u16  TIMER1_u16ReadTimer1Value(void);

void TIMER1_voidSetCR1AValue(u8 A_u8Value);

void TIMER1_voidICUInit(void);

void TIMER1_voidICUSetCallBack(void (*ptrToFunc) (void));

void TIMER1_voidICUSetTrigger(u8 u8Trigger);

u16  TIMER1_u16ReadICU(void);

void TIMER1_voidICUDisableINT(void);


#endif /* TIMER1_INTERFACE_H_ */