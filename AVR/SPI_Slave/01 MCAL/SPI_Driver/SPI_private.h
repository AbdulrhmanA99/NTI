/*
 * SPI_private.h
 *
 * Created: 7/3/2023 10:42:54 AM
 *  Author: Abdul
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPDR	*((volatile u8*)0x2F)
#define SPSR	*((volatile u8*)0x2E)
#define SPCR	*((volatile u8*)0x2D)


#endif /* SPI_PRIVATE_H_ */