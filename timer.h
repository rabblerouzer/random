/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
the time.h file defines methods used in timer.c, and state_machine.c
*/
#ifndef timer_included
#define timer_included

/* LCG constants */
#define M 49381 // Multiplier
#define I 8643 // Increment

void timer_start();
void timer_set_state_transition(unsigned short delay);
unsigned short timer_elapsed();
unsigned int prand();

#endif //included
