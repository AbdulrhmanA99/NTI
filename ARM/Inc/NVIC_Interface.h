/*
 * NVIC_interface.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Abdul
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


void	NVIC_voidInit();

void	NVIC_voidSetInterruptEnable(u8 Int_Num);

void	NVIC_voidSetInterruptDisable(u8 Int_Num);

void	NVIC_voidSetPendingFlag(u8 Int_Num);

void	NVIC_voidClrPendingFlag(u8 Int_Num);

u8		NVIC_u8GetActiveFlag(u8 Int_Num);

void	NVIC_voidSetintPriority(u8 Int_Num, u8 Int_Priority);


#endif /* NVIC_INTERFACE_H_ */
