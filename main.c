/********************************************************************************/
/*                  LED Blink By MSP432 Launch Pad                              */
/*   Copyright (C) 2018 by Ashraf Abubaker Mohammed - SEDC                      */
/*                                                                              */
/*   Redistribution, modification or use of this software in source or binary   */
/*   forms is permitted as long as the files maintain this copyright. Users are */
/*   permitted to modify this and use it to learn about the field of embedded   */
/*   software. Ashraf is not liable for any                                     */
/*   misuse of this material.                                                   */
/********************************************************************************/
#include "msp.h"
#include "stdint.h"
#include "memory.h"


/* Constants */
#define DELAY1        (100000)
#define DELAY2        (20000)
#define MAX_SIZE      (25)


/* Function Declaration */
void blink_forever();
/**
 * main.c
 */
void main(void)
{
	uint8_t array1[MAX_SIZE];
	uint8_t array2[MAX_SIZE];
	P1DIR |=BIT0;                                 // Set P1.0 as output pin
	P2DIR |=BIT1;                                 // Set P2.1 as output pin
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	/* Set array 1 to AF */
	my_memset(array1,MAX_SIZE,0xAF);
	/* Make no operation for debuging */
	__NOP();
	/* Move array 1 to array 2 */
	my_memmove(array1,array2,MAX_SIZE-1);
	__NOP();
	/* Move array 1 to array 2 */
    blink_forever();
}

void blink_forever()
{
    uint32_t i=0;
    while(1){
        for(i=0;i<DELAY1;i++);
        P1OUT ^=BIT0;
        P2OUT ^=BIT1;
    }
}
