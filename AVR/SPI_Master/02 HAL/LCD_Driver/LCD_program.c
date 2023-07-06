/*
 * LCD_program.c
 *
 * Created: 6/11/2023 1:58:16 PM
 *  Author: Abdul
 */


#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../01 MCAL/DIO_Driver/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"






/***********************************************************************************/
void LCD_voidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Set Control pins as output */
	DIO_voidSetPinDirection(RS_PORT,RS_PIN,PIN_OUTPUT);
	// DIO_voidSetPinDirection(RW_PORT,RW_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(EN_PORT, EN_PIN,PIN_OUTPUT);

	/* Set Data Port Direction as output */
	DIO_voidSetPinDirection(D4_PORT,D4_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT,D5_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT,D6_PIN,PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT,D7_PIN,PIN_OUTPUT);

	/* Return Home */
	LCD_voidWriteCommand(RETURN_HOME );
	/* Configure as 4-bit data mode*/
	LCD_voidWriteCommand(FUNCTION_SET_4BIT_2LINES_5X7_DOTS);
	_delay_ms(2);
	/*Display ON OFF Control */
	LCD_voidWriteCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(2);
	/* Clear Display */
	LCD_voidWriteCommand(DISPLAY_CLEAR);
	_delay_ms(2);

}
/***********************************************************************************/
void LCD_voidWriteBitsToSend(u8 copy_u8Byte)
{
	//DIO_voidSetPinValue(RW_PORT,RW_PIN, PIN_LOW);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);

	/*prepare 4 bits MSB to send */
	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 7) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 6) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 5) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 4) & 1);

	/* open EN--> make it high --- then after 1m close EN -->make it low*/
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(30);

	/*prepare 4 bits LSB to send */
	DIO_voidSetPinValue(D7_PORT,D7_PIN, (copy_u8Byte>> 3) & 1);
	DIO_voidSetPinValue(D6_PORT,D6_PIN, (copy_u8Byte>> 2) & 1);
	DIO_voidSetPinValue(D5_PORT,D5_PIN, (copy_u8Byte>> 1) & 1);
	DIO_voidSetPinValue(D4_PORT,D4_PIN, (copy_u8Byte>> 0) & 1);

	/* open EN--> make it high --- then after 1m -- close EN -->make it low*/
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN_PORT,EN_PIN, PIN_LOW);
	_delay_ms(15);



}



/***********************************************************************************/
void LCD_voidWriteData(u8 copy_u8data)
{
	/*Set RS to HIGH */
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_HIGH);


	LCD_voidWriteBitsToSend(copy_u8data);
}


/***********************************************************************************/

void LCD_voidWriteCommand(u8 copy_u8Command)
{
	/*Set RS to low */
	DIO_voidSetPinValue(RS_PORT,RS_PIN,PIN_LOW);


	LCD_voidWriteBitsToSend(copy_u8Command);
}

/***********************************************************************************/



void LCD_voidWriteString(u8* copy_str)
{
	u32 i= 0;
	while(copy_str[i] != '\0')
	{
		LCD_voidWriteData(copy_str[i]);
		i++;
	}
}


/***********************************************************************************/
void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col)
{
	/* 0x00 --> address row 0
	 * 0x40 --> address row 1
	 * 0x14 --> address row 2
	 * 0x54 --> address row 3
	 * copy_u8col --> col num
	 * */
	u8 rows_address[4]={0x00,0x40,0x14,0x54};

	u8 local_address=rows_address[copy_u8row]+copy_u8col;

	LCD_voidWriteCommand(local_address+SET_DDRAM_ADDRESS) ;

}

/***********************************************************************************/

/*
void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col)
{

	u8 local_address ;
	switch(copy_u8row)
	{
	case 0 : local_address =0x00+copy_u8col ;
	break ;

	case 1 : local_address =copy_u8col+0x40 ;
	break ;
	case 2 : local_address =copy_u8col+0x14 ;
	break ;

	case 3 : local_address =copy_u8col+0x54 ;
	break ;


	}
	LCD_voidWriteCommand(local_address+SET_DDRAM_ADDRESS) ;

}
 */
/***********************************************************************************/

void LCD_voidClear(void)
{
	LCD_voidWriteCommand( DISPLAY_CLEAR);
}

/***********************************************************************************/

void LCD_voidWriteNumber( u32 Copy_u8num )

{
	u32 LOCAL_NUMBER=Copy_u8num ;
	u8 LOCAL_ARR[10] ,i=0 ;

	do
	{
		LOCAL_ARR[i]= ( (LOCAL_NUMBER%10)+48 );
		LOCAL_NUMBER=LOCAL_NUMBER/10 ;
		i++ ;
	}
	while(LOCAL_NUMBER!=0);


	for(;i>0;i--)
	{
		LCD_voidWriteData(LOCAL_ARR[i-1]);
	}

}


/* pass special character and block number */




void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data , u8 copy_u8ByteNum , u8 row, u8 col)
{
	u8 Local_u8PatternCounter;
	u8 max_char = 8;

	// 1- Calculate the required CGRAM_ADDRESS
	u8 Local_u8bolckAddress = copy_u8ByteNum * 8;
	// 2- Set the address to CGRAM
	LCD_voidWriteCommand(Local_u8bolckAddress + SET_CGRAM_ADDRESS);
	// 3- loop over the pattern
	for (Local_u8PatternCounter = 0; Local_u8PatternCounter < max_char; ++Local_u8PatternCounter)
	{
		LCD_voidWriteData(copy_u8data[Local_u8PatternCounter]);
	}
	//LCD_voidWriteData(copy_u8ByteNum);
	LCD_voidGoToXY(row,col);
	LCD_voidWriteData(copy_u8ByteNum);
}


/***********************************************************************************/
/*
void LCD_voidWriteSpecialCharToCGRAM(u8 * copy_u8data, u8 copy_u8ByteNum)

{
	u8 Local_u8CGramAddrss ;
	u8 counter=0 ;
	Local_u8CGramAddrss = copy_u8ByteNum * 8 ;

	LCD_voidWriteCommand(Local_u8CGramAddrss+64);


	for(counter=0;counter<8;counter++)
	{
		LCD_voidWriteData(copy_u8data[counter]);
	}

}
*/
/***********************************************************************************/
/*
void LCD_voidDisplaySpecialChar(u8 copy_u8ByteNum)
{

	LCD_voidWriteData(copy_u8ByteNum);

}
*/

