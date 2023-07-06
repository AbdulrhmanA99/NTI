/*
 * KEYPAD_config.h
 *
 * Created: 6/12/2023 9:44:06 AM
 *  Author: Abdul
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


/*
#define KPD_PORT_COL    PORTD_ID
#define KPD_PORT_ROW    PORTB_ID

#define COL_START   PIN7    //  First Column is PIN2
#define COL_END     PIN3      //  Last  Column is PIN5

#define ROW_START   PIN5     // First Row    is PIN4
#define ROW_END     PIN2      //Last  Row    is PIN7
 */

#define COL_0            PIN7
#define KPD_PORT_COL0    PORTD_ID

#define COL_1            PIN6
#define KPD_PORT_COL1    PORTD_ID

#define COL_2            PIN5
#define KPD_PORT_COL2    PORTD_ID

#define COL_3            PIN3
#define KPD_PORT_COL3    PORTD_ID


/**********************************/

#define ROW_0           PIN5
#define KPD_PORT_ROW0   PORTC_ID

#define ROW_1           PIN4
#define KPD_PORT_ROW1   PORTC_ID

#define ROW_2           PIN3
#define KPD_PORT_ROW2   PORTC_ID

#define ROW_3           PIN2
#define KPD_PORT_ROW3   PORTC_ID

/*
#define KEYPAD_ARR {    {0x07, 0x08, 0x09, 0x0A }, \
                        {0x04, 0x05, 0x06, 0x0B }, \
                        {0x01, 0x02, 0x03, 0x0C }, \
                        {0x0E, 0x00, 0x0F, 0x0D }  }
*/

#define KEYPAD_ARR  {   {'7','8','9','/'},  \
                        {'4','5','6','*'},  \
					    {'1','2','3','-'},  \
					    {'C','0','=','+'}   }

/*
#define KEYPAD_ARR  {   {'1','2','3','4'},		\
						{'5','6','7','8'},		\
						{'9','10','11','12'},   \
						{'13','14','15','16'}   }
*/


#endif /* KEYPAD_CONFIG_H_ */