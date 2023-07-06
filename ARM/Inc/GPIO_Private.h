/*
 * DIO_private.h
 *
 * Created: 6/11/2023 1:46:28 PM
 *  Author: Abdul
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/***********GPIO ADDRESSES*************/
/**********GPIOA************/
#define GPIOA_BASE_ADD		((u32)0x40020000)

#define GPIOA_MODER		*((volatile u32*)(0x00+GPIOA_BASE_ADD))
#define GPIOA_OTYPER    *((volatile u32*)(0x04+GPIOA_BASE_ADD))
#define GPIOA_OSPEEDR   *((volatile u32*)(0x08+GPIOA_BASE_ADD))
#define GPIOA_PUPDR	    *((volatile u32*)(0x0C+GPIOA_BASE_ADD))
#define GPIOA_IDR		*((volatile u32*)(0x10+GPIOA_BASE_ADD))
#define GPIOA_ODR		*((volatile u32*)(0x14+GPIOA_BASE_ADD))
#define GPIOA_BSRR		*((volatile u32*)(GPIOA_BASE_ADD+0x18))
#define GPIOA_AFRL 		*((volatile u32*)(GPIOA_BASE_ADD+0x20))
#define GPIOA_AFRH		*((volatile u32*)(GPIOA_BASE_ADD+0x24))

/**********************/
/**********GPIOB************/
#define GPIOB_BASE			((u32)0x40020400)


#define GPIOB_MODER			*((volatile u32*)(GPIOB_BASE+0x00))
#define GPIOB_OTYPER		*((volatile u32*)(GPIOB_BASE+0x04))
#define GPIOB_OSPEEDR		*((volatile u32*)(GPIOB_BASE+0x08))
#define GPIOB_PUPDR			*((volatile u32*)(GPIOB_BASE+0x0c))
#define GPIOB_IDR			*((volatile u32*)(GPIOB_BASE+0x10))
#define GPIOB_ODR			*((volatile u32*)(GPIOB_BASE+0x14))
#define GPIOB_BSRR			*((volatile u32*)(GPIOB_BASE+0x18))
#define GPIOB_AFRL 			*((volatile u32*)(GPIOB_BASE+0x20))
#define GPIOB_AFRH 			*((volatile u32*)(GPIOB_BASE+0x24))

/**********************/
/**********GPIOC************/
#define GPIOC_BASE			((u32)0x40020800)

#define GPIOC_MODER			*((volatile u32*)(GPIOC_BASE+0x00))
#define GPIOC_OTYPER		*((volatile u32*)(GPIOC_BASE+0x04))
#define GPIOC_OSPEEDR		*((volatile u32*)(GPIOC_BASE+0x08))
#define GPIOC_PUPDR			*((volatile u32*)(GPIOC_BASE+0x0c))
#define GPIOC_IDR			*((volatile u32*)(GPIOC_BASE+0x10))
#define GPIOC_ODR			*((volatile u32*)(GPIOC_BASE+0x14))
#define GPIOC_BSRR			*((volatile u32*)(GPIOC_BASE+0x18))
#define GPIOC_AFRL 			*((volatile u32*)(GPIOC_BASE+0x20))
#define GPIOC_AFRH 			*((volatile u32*)(GPIOC_BASE+0x24))

/**********************/
/**********GPIOD************/
#define GPIOD_BASE			((u32)0x40021200)

#define GPIOD_MODER			*((volatile u32*)(GPIOD_BASE+0x00))
#define GPIOD_OTYPER		*((volatile u32*)(GPIOD_BASE+0x04))
#define GPIOD_OSPEEDR		*((volatile u32*)(GPIOD_BASE+0x08))
#define GPIOD_PUPDR			*((volatile u32*)(GPIOD_BASE+0x0c))
#define GPIOD_IDR			*((volatile u32*)(GPIOD_BASE+0x10))
#define GPIOD_ODR			*((volatile u32*)(GPIOD_BASE+0x14))
#define GPIOD_BSRR			*((volatile u3ِ2*)(GPIOD_BASE+0x18))
#define GPIOD_AFRL 			*((volatile u32*)(GPIOD_BASE+0x20))
#define GPIOD_AFRH 			*((volatile u32*)(GPIOD_BASE+0x24))

#endif /* GPIO_PRIVATE_H_ */
