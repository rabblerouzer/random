/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
This is the project main method. It outputs everything that is being done in state_machine.c, led.c, switches.c, and buzzer.c
*/ 
#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

//main method
void main(void) 
{
  switch_init();
  
  configureClocks();
  buzzer_init();
  
  led_init();
  setLed(1, 1);
  
  enableWDTInterrupts();
  
  or_sr(0x18);  // CPU off, GIE on
} 
