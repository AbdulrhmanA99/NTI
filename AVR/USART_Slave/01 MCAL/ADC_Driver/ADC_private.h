/*
 * ADC_private.h
 *
 * Created: 6/17/2023 10:14:35 AM
 *  Author: Abdul
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX	*((volatile u8* )0x27)
							    
#define ADCSRA	*((volatile u8* )0x26)
							    
#define ADCH	*((volatile u8* )0x25)
							    
#define ADCL	*((volatile u8* )0x24)
							    
#define SFIOR	*((volatile u8* )0x50)

#define ADC		*((volatile u16*)0x24)


#endif /* ADC_PRIVATE_H_ */