/*
 * STK_interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Abdul
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_


void	STK_voidInit();

void	STK_voidBusyWait(u32 Ticks);

void	STK_voidSingleInterval(u32 Ticks , void (*Pf)(void));

void	STK_voidPeriodicInterval(u32 Ticks , void (*Pf)(void));

void	STK_voidStopInterval();

void	Systick_Handler(void);

u32  STK_u32GetElapsedTime (void);

u32  STK_u32GetRemainingTime (void);



#endif /* STK_INTERFACE_H_ */
