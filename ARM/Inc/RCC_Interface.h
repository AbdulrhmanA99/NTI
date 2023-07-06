/*
 * RCC_Interface.h
 *
 *  Created on: Jun 23, 2023
 *      Author: Abdul
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB1			0
#define RCC_APB1			1
#define RCC_APB2			2


void RCC_voidSysClkInit(void);

void RCC_voidEnablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId);

void RCC_voidDisablePerClk(u8 Copy_u8BusId , u8 Copy_u8PerId);


#endif /* RCC_INTERFACE_H_ */
