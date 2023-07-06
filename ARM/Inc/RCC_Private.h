/*
 * RCC_Private.h
 *
 *  Created on: Jun 23, 2023
 *      Author: Abdul
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_BASE_ADDRESS			((u32)(0x40023800))

#define RCC_CR						*((volatile u32 *)(0x00 + (RCC_BASE_ADDRESS)))
#define RCC_PLLCFGR					*((volatile u32 *)(0x04 + (RCC_BASE_ADDRESS)))
#define RCC_CFGR					*((volatile u32 *)(0x08 + (RCC_BASE_ADDRESS)))
#define RCC_CIR						*((volatile u32 *)(0x0C + (RCC_BASE_ADDRESS)))

#define RCC_AHB1ENR					*((volatile u32 *)(0x30 + (RCC_BASE_ADDRESS)))
#define RCC_APB1ENR					*((volatile u32 *)(0x40 + (RCC_BASE_ADDRESS)))
#define RCC_APB2ENR					*((volatile u32 *)(0x44 + (RCC_BASE_ADDRESS)))

#define RCC_HSI					1
#define RCC_HSE					2
#define RCC_PLL					3

#define PLLM_MASK				0xFFFFFFE0

#define PLLN_MASK				0xFFFFC01F

#define PLLP_MASK				0xFFFF3FFF

#define AHB1_MASK				0xFFFFFF0F

#define APB1_MASK				0xFFFFE3FF

#define APB2_MASK				0xFFFF1FFF

/*AHB1 Bus speed*/
#define AHB_NO_DIV				0b0000
#define AHB_DIV_2				0b1000
#define AHB_DIV_4				0b1001
#define AHB_DIV_8				0b1010
#define AHB_DIV_16				0b1011
#define AHB_DIV_64				0b1100
#define AHB_DIV_128				0b1101
#define AHB_DIV_256				0b1110
#define AHB_DIV_512				0b1111

/*APB1 & APB2 Bus Speed*/
#define APB_NO_DIV				0b000
#define APB_DIV_2				0b100
#define APB_DIV_4				0b101
#define APB_DIV_8				0b110
#define APB_DIV_16				0b111


#endif /* RCC_PRIVATE_H_ */
