/*
 * SPI_interface.h
 *
 * Created: 7/3/2023 10:41:32 AM
 *  Author: Abdul
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_Init_Master();
void SPI_Init_Slave();
u8	 SPI_SendData(u8 data);



#endif /* SPI_INTERFACE_H_ */