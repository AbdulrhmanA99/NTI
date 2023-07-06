/*
 * USART_private.h
 *
 * Created: 7/2/2023 12:03:27 PM
 *  Author: Abdul
 */ 


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UDR   *((volatile u8*)0x2C)


#endif /* USART_PRIVATE_H_ */