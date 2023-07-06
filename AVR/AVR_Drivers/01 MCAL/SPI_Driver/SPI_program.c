/*
 * SPI_program.c
 *
 * Created: 7/3/2023 10:40:49 AM
 *  Author: Abdul
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_Init_Master()
{
	SET_BIT(SPCR, 4); /* select master */
	CLR_BIT(SPCR, 0); /* pre-64 */
	SET_BIT(SPCR, 1); /* pre-64 */
	CLR_BIT(SPSR, 0); /* pre-64 */
	CLR_BIT(SPCR, 2); /* Clock phase */
	CLR_BIT(SPCR, 3); /* Clock polarity */
	SET_BIT(SPCR, 5); /* msb */
	SET_BIT(SPCR, 6); /* enable */
	
}

void SPI_Init_Slave()
{
	CLR_BIT(SPCR, 4); /* select slave */
	CLR_BIT(SPCR, 2); /* Clock phase */
	CLR_BIT(SPCR, 3); /* Clock polarity */
	SET_BIT(SPCR, 5); /* msb */
	SET_BIT(SPCR, 6); /* enable */	
}

u8   SPI_SendData(u8 data) /* transceiver = transmitter/receiver */
{
	SPDR=data;
	while(GET_BIT(SPSR, 7) == 0);
	return SPDR;
}
