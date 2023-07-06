/*
 * DIO_interface.h
 *
 * Created: 6/11/2023 1:46:47 PM
 *  Author: Abdul
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_



/*PORTS*/
#define GPIO_A		0
#define GPIO_B		1
#define GPIO_C		2
#define GPIO_D		3
#define GPIO_E		4
#define GPIO_H		7

/*PINS*/
#define GPIO_PIN0		0
#define GPIO_PIN1		1
#define GPIO_PIN2		2
#define GPIO_PIN3		3
#define GPIO_PIN4		4
#define GPIO_PIN5		5
#define GPIO_PIN6		6
#define GPIO_PIN7		7
#define GPIO_PIN8		8
#define GPIO_PIN9		9
#define GPIO_PIN10		10
#define GPIO_PIN11		11
#define GPIO_PIN12		12
#define GPIO_PIN13		13
#define GPIO_PIN14		14
#define GPIO_PIN15		15




/*DIRECTIONS*/
#define GPIO_AF0				0
#define GPIO_AF1				1
#define GPIO_AF2				2
#define GPIO_AF3				3
#define GPIO_AF4				4
#define GPIO_AF5				5
#define GPIO_AF6				6
#define GPIO_AF7				7
#define GPIO_AF8				8
#define GPIO_AF9				9
#define GPIO_AF10				10
#define GPIO_AF11				11
#define GPIO_AF12				12
#define GPIO_AF13				13
#define GPIO_AF14				14
#define GPIO_AF15				15

#define GPIO_INPUT_PU			16
#define GPIO_INPUT_PD			17
#define GPIO_INPUT_F			18
#define GPIO_OUTPUT_PP			19
#define GPIO_OUTPUT_OD			20
#define GPIO_ANALOG				21


/*LEVELS*/
#define GPIO_HIGH				1
#define GPIO_LOW				0



u8 GPIO_u8SetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction) ;

u8 GPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value) ;

u8 GPIO_u8SetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction) ;

u8 GPIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value) ;

u8 GPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_u8Result);

u8 GPIO_u8GetPortValue(u8 Copy_u8Port , u8* Copy_u8Result);

u8 GPIO_u8TogPinValue(u8 Copy_u8Port , u8 Copy_u8Pin) ;


#endif /* GPIO_INTERFACE_H_ */
