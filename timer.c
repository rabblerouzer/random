/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
this .c file is the timer. it includes timer.h and state_machine.h
*/
#include <msp430.h>
#include "timer.h"
#include "state_machine.h"

//initial is 0
static unsigned int randSeed = 0;

//initial at 0
static unsigned short startTime = 0;
static unsigned short currentTime = 0;

//initial at 0
static unsigned short stateTime = 0;
static unsigned short stateTransition = 0;

void timer_start(){
  startTime = currentTime; //start time gets set to current time
}

unsigned short timer_elapsed(){
  randSeed += currentTime % 5;
  return currentTime - startTime;
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  stateTime++; //increasing state time
  currentTime++; //increasing the current time
  randSeed++; //increasing the randSeed
   
  //if statement when the state time is >= state transition
  if(stateTime >= stateTransition){
    stateTime = 0; //then state time is set to 0
    randSeed += 5; //adding to randSeed
    state_update(); //the state updates
  }
}
//sets the state transition
void timer_set_state_transition(unsigned short delay){
  stateTransition = delay; //the transition delays
}


unsigned int prand() {
  return M * randSeed + I;                     // Generate the next state of the LCG
} 
