// Piano.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano
// December 29, 2014


// Port A bits 5-2 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"



// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void){ unsigned long volatile delay;
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;
	delay = SYSCTL_RCGC2_R;
	GPIO_PORTE_PCTL_R &= ~0x0F;
	GPIO_PORTE_DIR_R &= ~0x0F;
	GPIO_PORTE_AFSEL_R &= ~0x0F;
	GPIO_PORTE_PUR_R &=~0x0F;
	GPIO_PORTE_DEN_R |= 0x0F;
 	GPIO_PORTE_AMSEL_R &= ~0x20;
}
// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void){
  return (GPIO_PORTE_DATA_R&0x0F);
 // return 0; // remove this, replace with input
}
