/*
 * RTC_control.c
 *
 * Created: 12/05/2023 22:45:39
 *  Author: danie
 */ 

#include "RTC_control.h"

// This will start a 1kHz clock, which will raise an interrupt every millisecond.
void RTC_init(){
    cli();
    
    // Set the RTC clock to 1kHz
    RTC.CLKSEL = RTC_CLKSEL_INT1K_gc;
    
    // Enable the RTC
    RTC.CTRLA = RTC_RTCEN_bm;
    
    // Enable the overflow interrupt
    RTC.INTCTRL = RTC_OVF_bm;
    
    // Enable interrupts
    sei();
}