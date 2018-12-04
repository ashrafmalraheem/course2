/*************************************************************************/
/*                  LED Blink By MSP432 Launch Pad
/*   Copyright (C) 2018 by Ashraf Abubaker Mohammed - SEDC
/*   
/*   Redistribution, modification or use of this software in source or binary
/*   forms is permitted as long as the files maintain this copyright. Users are 
/*   permitted to modify this and use it to learn about the field of embedded
/*   software. Ashraf is not liable for any
/*   misuse of this material. 
/*************************************************************************/
#include "msp.h"
#include "stdint.h"


////
#define DELAY1        (100000)
/**
 * main.c
 */
void main(void)
{
	P1DIR |=BIT0;                                 // Set P1.0 as output pin
	P2DIR |=BIT1;                                 // Set P2.1 as output pin
	uint32_t i=0;
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    while(1){
        for(i=0;i<DELAY1;i++);
        P1OUT ^=BIT0;
        P2OUT ^=BIT1;
    }
}
