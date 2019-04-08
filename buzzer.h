/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
buzzer.h defines states and methods and variables used in buzzer.c, project_main.c, state_machine.c, and switches.c
*/

#ifndef buzzer_included
#define buzzer_included

//defining the buzzer states read and play for when the buzzer is ready and when it plays
#define STATE_BUZZER_READY 0
#define STATE_BUZZER_PLAYING 1

//methods
void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_play();

//char variable
extern char buzzer_state;

#endif //part of include guard
 
