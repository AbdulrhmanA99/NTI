/*
 * USART_program.c
 *
 * Created: 7/2/2023 12:04:01 PM
 *  Author: Abdul
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_Init()
{
	SET_BIT(UCSRC, 7); /* write on the UCSRC */
	CLR_BIT(UCSRC, 6); /* Asynchronous */
	CLR_BIT(UCSRC, 5); /* Parity Mode Disabled */
	CLR_BIT(UCSRC, 4); /* Parity Mode Disabled */
	CLR_BIT(UCSRC, 3); /* Stop Bit Select (1-bit) */
	SET_BIT(UCSRC, 1); /* Character Size (8-bit) */
	SET_BIT(UCSRC, 2); /* Character Size (8-bit) */
	UBRRL=51;		   /* Baud rate for 8MHZ */
	SET_BIT(UCSRB, 3); /* Transmitter Enable */
	SET_BIT(UCSRB, 4); /* Receiver Enable */
	CLR_BIT(UCSRB, 2); /* Character Size (8-bit) disable for 9-bit */
}

void USART_Send(u8 data)
{
	while(GET_BIT(UCSRA, 5) == 0);
	UDR=data;
}

u8	 USART_Receive()
{
	while(GET_BIT(UCSRA, 7) == 0);
	return UDR;
}

void USART_Send_Str(u8* str)
{
	while (*str != '\0')
	{
		USART_Send(*str);
		str++;
	}
}

void USART_Receive_Str(u8* str)
{
	u8 receive = 0;
	*str = "";
	while (receive != '\0')
	{
		USART_Receive(&receive);
		//_delay_ms(1);
		*str += receive;
	}
}
