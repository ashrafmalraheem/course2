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
#define MAX_SIZE      (24)


/* Function Declaration */
void blink_forever();
// ** Global Vars **//
uint8_t array1[MAX_SIZE];
uint8_t array2[MAX_SIZE];
/**
 * main.c
 */
void main(void)
{
	uint32_t difference = array2-array1;
	P1DIR |=BIT0;                                 // Set P1.0 as output pin
	P2DIR |=BIT1;                                 // Set P2.1 as output pin
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watch dog timer
	/* Set array 1 to AF */
	my_memset(array1,MAX_SIZE,0xFF);
	/* Make no operation for debugging */
	__NOP();
	/* Move array 1 to array 2 */
	my_memmove(array1,array2,MAX_SIZE-1);
	__NOP();
	difference = 100;
	/* Move array 1 to array 2 */
    blink_forever();
}

void blink_forever()
{
    uint32_t i=0;
    while(1){
        for(i=0;i<DELAY1;i++);
        P1OUT ^=BIT0;
        //P2OUT ^=BIT1;
    }
}
