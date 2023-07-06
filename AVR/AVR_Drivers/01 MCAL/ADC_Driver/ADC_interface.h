/*
 * ADC_interface.h
 *
 * Created: 6/17/2023 10:14:00 AM
 *  Author: Abdul
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*        ADC channels         */

#define ADC_u8_CHANNEL_0		0
#define ADC_u8_CHANNEL_1		1
#define ADC_u8_CHANNEL_2		2
#define ADC_u8_CHANNEL_3		3
#define ADC_u8_CHANNEL_4		4
#define ADC_u8_CHANNEL_5		5
#define ADC_u8_CHANNEL_6		6
#define ADC_u8_CHANNEL_7		7
#define ADC_CHANNEL_MSK			0b11100000


/* Choosing voltage Reference */

#define AVREF_AVCC_5V			1
#define AVREF_Custom			2
#define AVREF_INTERNAL			3


/*    Selecting adjustment    */

#define RIGHT_Adjustment		1
#define LEFT_Adjustment			2


/*       ADMUX  registers      */

#define ADC_MUX_0				0
#define ADC_MUX_1				1
#define ADC_MUX_2				2
#define ADC_MUX_3				3
#define ADC_MUX_4				4
#define ADC_MUX_ADLAR			5
#define ADC_MUX_REFS0			6
#define ADC_MUX_REFS1			7


/*           ADCSRA            */

#define ADCSRA_ADPS0			0
#define ADCSRA_ADPS1			1
#define ADCSRA_ADPS2			2
#define ADCSRA_ADIE				3
#define ADCSRA_ADIF				4
#define ADCSRA_ADATE			5
#define ADCSRA_ADSC				6
#define ADCSRA_ADEN				7


/* SFPOIR register (auto trigger/free running) */

#define SFIOR_ADTS0				0
#define SFIOR_ADTS1				1
#define SFIOR_ADTS2				2


/* Prototypes */

void  ADC_voidInit(void);
void  ADC_voidEnable(void);
void  ADC_voidDisable(void);

void  ADC_voidInterruptEnable(void);
void  ADC_voidInterruptDisable(void);

u16	  ADC_u16GetDigitalValue(u8 Copy_uint8ChannelNum);

void  ADC_CallBack(void (*Copy_ptr)(void));
void  ADC_u16StartConversion(u8 Copy_uint8ChannelNum);

void  ADC_voidInitSourceTrigger(void);

u8    EXTI_u8SetCallBack(u8 Copy_u8Interrupt, void (*Copy_pfPtr)(void));


#endif /* ADC_INTERFACE_H_ */