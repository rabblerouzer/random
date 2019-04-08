/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
led.c handles the leds which are the green and red lights
methods included in this c file are led_init, setLed, and led_update
*/
#include <msp430.h>
#include "led.h"
#include "switches.h"

//used part of method from demos
void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  /*led_changed = 1;
  led_update();
  */
    
}

int setLed(int red_on, int green_on){
  // Only allow booleans
  if(red_on < 0 || red_on > 1 || green_on < 0 || red_on > 1)
    return 0;

  char ledFlags = 0;
  ledFlags |= red_on ? LED_RED : 0;
  ledFlags |= green_on ? LED_GREEN : 0;
  
  P1OUT &= (0xff - LEDS) | ledFlags;
  P1OUT |= ledFlags;
}

//used part of method from demos
void led_update(){
  /*if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
    */
} 
