/*
 * SEV_interface.h
 *
 * Created: 6/10/2023 9:02:53 PM
 *  Author: Abdul
 */ 


#ifndef SEV_INTERFACE_H_
#define SEV_INTERFACE_H_
/*
#define SEV_START  0
#define SEV_END    7

#define SEV_LEFT   0
#define SEV_RIGHT  1

void SEV_voidSet7SegmentValue(u8 SevenSegmentNumber, u8 SevenSegmentValue);
*/

void SEV_Initialization();
//extern u8 number;
void SEV_Write_One_Number(u8 number);
void SEV_Write_Numbers(u16 number);

void SEV_Enable1();
void SEV_Enable2();
void SEV_Enable3();
void SEV_Enable4();

void SEV_Disable1();
void SEV_Disable2();
void SEV_Disable3();
void SEV_Disable4();


#endif /* SEV_INTERFACE_H_ */