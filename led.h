/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
the led.h file defines the cariables and methods that are used and included in led.c, buzzer.c, project_main.c, state_machine.c, and switches.c 
*/
#ifndef led_included
#define  led_included

#include <msp430.h>

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

//methods
void led_init();		/* initialize LEDs */
void led_update();		/* update leds */


#endif //included
