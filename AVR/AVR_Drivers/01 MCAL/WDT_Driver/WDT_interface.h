/*
 * WDT_interface.h
 *
 * Created: 7/5/2023 11:51:46 PM
 * Author: Abdul
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_


/* The Watchdog Timer is utilized for system reset or sleep control
to ensure system reliability and prevent lockups. */

// Enable Watch Dog Timer: Start counting till timeout (reset MCU)
void WDT_voidEnable(void);

// Disable Watch Dog Timer: Stop counting time.
void WDT_voidDisable(void);

// Sleep function (timeout)
void WDT_voidSleep(u8 copy_u8SleepTime);



#endif /* WDT_INTERFACE_H_ */