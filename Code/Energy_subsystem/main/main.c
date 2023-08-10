/*
 * main.c
 *
 * Created: 12/05/2023 22:37:45
 * Author : danie
 */ 

#include <avr/io.h>

#include "SPI_control.h"
#include "UART_Control.h"
#include "RTC_control.h"


int main(void)
{
    SPI_init();
	UART_init();
    RTC_init();
    interrupt_init();

}

void uC_init(void)
{
    // Set internal clock to 24MHz
    // ? These arent entirely necessary, as the default values are all zero
    CLKCTRL.MCLKCTRLA = 0x00;
    CLKCTRL.MCLKCTRLB = 0x00;
    CLKCTRL.MCLKCTRLC = 0x00;
    

}

void interrupt_init(void)
{
    cli();
    // 1kHz clock interrupt
    RTC.INTCTRL = RTC_OVF_bm;
    sei();

}