/*
 * WDT_private.h
 *
 * Created: 7/5/2023 11:52:37 PM
 * Author: Abdul
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_


// Watch dog Timer Control Register – WDTCR
#define WDTCR			(*((volatile u8*)0x41))

//disable 
#define WDTCR_WDTOE		4

//enable
#define WDTCR_WDE		3

// WD pre-scaling
#define WDTCR_WDP2		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0


#endif /* WDT_PRIVATE_H_ */