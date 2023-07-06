/*
 * USART_interface.h
 *
 * Created: 7/2/2023 12:03:45 PM
 *  Author: Abdul
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


void USART_Init();
void USART_Send(u8 data);
u8   USART_Receive();
void USART_Send_Str(u8* str);
void USART_Receive_Str(u8* str);


#endif /* USART_INTERFACE_H_ */