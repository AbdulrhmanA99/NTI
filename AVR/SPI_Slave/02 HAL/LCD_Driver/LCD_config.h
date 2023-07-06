/*
 * LCD_config.h
 *
 * Created: 6/11/2023 2:02:03 PM
 *  Author: Abdul
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define LCD_MODE  FOUR_BIT

/*
 * choose control pins
 */

#define RS_PIN   PIN3
#define RS_PORT  PORTA_ID


#define EN_PIN   PIN2
#define EN_PORT  PORTA_ID

/*
 * data pins
 */

#define D7_PIN    PIN4
#define D7_PORT   PORTB_ID

#define D6_PIN    PIN2
#define D6_PORT   PORTB_ID

#define D5_PIN    PIN1
#define D5_PORT   PORTB_ID

#define D4_PIN    PIN0
#define D4_PORT   PORTB_ID


#endif /* LCD_CONFIG_H_ */