/*
 * ADC_program.c
 *
 * Created: 6/17/2023 10:14:56 AM
 *  Author: Abdul
 */ 
 
 
 
 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

//#include "../EXT0/EXT0_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void (*pf)(void);

void  ADC_voidInit(void)
{
 /*  Voltage Reference */
 #if AVREF_USED == AVREF_AVCC_5V
 SET_BIT(ADMUX,ADC_MUX_REFS0);
 CLR_BIT(ADMUX,ADC_MUX_REFS1);
 
 #elif AVREF_USED ==  AVREF_Custom
 CLR_BIT(ADMUX,ADC_MUX_REFS0);
 CLR_BIT(ADMUX,ADC_MUX_REFS1);
 
 #elif AVREF_USED ==  AVREF_INTERNAL
 SET_BIT(ADMUX,ADC_MUX_REFS0);
 SET_BIT(ADMUX,ADC_MUX_REFS1);
 
 #endif
 
 /* RIGHT ADJUSTMENT */
 #if Adjustment_used == RIGHT_Adjustment
 CLR_BIT(ADMUX,ADC_MUX_ADLAR);
 
 #elif Adjustment_used == LEFT_Adjustment
 SET_BIT(ADMUX,ADC_MUX_ADLAR);
 
 #endif
 
 /*   PRESCALER 64   */
 CLR_BIT(ADCSRA,ADCSRA_ADPS0);
 SET_BIT(ADCSRA,ADCSRA_ADPS1);
 SET_BIT(ADCSRA,ADCSRA_ADPS2);
 
}

/*****   Source Trigger ******/
void  ADC_voidInitSourceTrigger(void)
{
 /* Voltage Reference */
 #if AVREF_USED == AVREF_AVCC_5V
 SET_BIT(ADMUX,ADC_MUX_REFS0);
 CLR_BIT(ADMUX,ADC_MUX_REFS1);
 
 #elif AVREF_USED ==  AVREF_Custom
 CLR_BIT(ADMUX,ADC_MUX_REFS0);
 CLR_BIT(ADMUX,ADC_MUX_REFS1);
 
 #elif AVREF_USED ==  AVREF_INTERNAL
 SET_BIT(ADMUX,ADC_MUX_REFS0);
 SET_BIT(ADMUX,ADC_MUX_REFS1);
 
 #endif
 
 /* RIGHT ADJUSTMENT */
 #if Adjustment_used == RIGHT_Adjustment
 CLR_BIT(ADMUX,ADC_MUX_ADLAR);
 
 #elif Adjustment_used == LEFT_Adjustment
 SET_BIT(ADMUX,ADC_MUX_ADLAR);
 
 #endif
 
 /* PRESCALER (64)  */
 CLR_BIT(ADCSRA,ADCSRA_ADPS0);
 SET_BIT(ADCSRA,ADCSRA_ADPS1);
 SET_BIT(ADCSRA,ADCSRA_ADPS2);
  
 /* Using External Interrupt */
 CLR_BIT(SFIOR,SFIOR_ADTS0);
 SET_BIT(SFIOR,SFIOR_ADTS1);
 CLR_BIT(SFIOR,SFIOR_ADTS2);
 
 /* Setting BIT 5 in ADCSRA (Auto Trigger enable) */
 SET_BIT(ADCSRA,ADCSRA_ADATE);
}

void ADC_voidEnable(void)
{
 /* Enabling ADC peripheral */
 SET_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidDisable(void)
{
 /* Disabling ADC peripheral */
 CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidInterruptEnable(void)
{
 /*  Enabling PIE (Peripheral interrupt enable) */
 SET_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_voidInterruptDisable(void)
{
 /* Disabling Interrupt */
 CLR_BIT(ADCSRA,ADCSRA_ADIE);
 /* Clearing Flag */
 SET_BIT(ADCSRA,ADCSRA_ADIF);
}

/* For Polling */
u16 ADC_u16GetDigitalValue(u8 Copy_u8ChannelNum)
{
 /* Clear channel number bits */
 ADMUX &= ADC_CHANNEL_MSK;
 
 /* Select channel Number */
 ADMUX |= Copy_u8ChannelNum;
 
 /* After choosing the channel start conversion */
 SET_BIT(ADCSRA,ADCSRA_ADSC);
 
 /* polling technique */
 while(GET_BIT(ADCSRA,ADCSRA_ADIF) == 0);
 
 /* Clearing the flag */
 SET_BIT(ADCSRA,ADCSRA_ADIF);
 
 /* Read the ADC Value */
 return ADC;
}

/* For Interrupt */

void ADC_u16StartConversion(u8 Copy_u8ChannelNum)
{
 ADMUX &= ADC_CHANNEL_MSK;
 ADMUX |= Copy_u8ChannelNum;
 
 /* Start Conversion */
 SET_BIT(ADCSRA,ADCSRA_ADSC);
}


void ADC_CallBack(void (*Copy_ptr)(void))
{
 pf = Copy_ptr;
}


/* ISR(ADC) */

void __vector_16 (void) __attribute((signal));
void __vector_16 (void)
{
 if(pf != NULL)
 {
  pf();
 }
}