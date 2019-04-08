/*Dima AbdelJaber
Arch1 Project 2
October 27, 2018
beepy blinky toy
Buzzer.c which contains the melody of the song, the cycles of the period, the buzzer_init, buzzer_play, buzzer_set_period, the songTempo and etc...
*/
//.h files included in the buzzer.c
#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "pitches.h"

//song is a static method containing all the notes
//tried implementing sounds R2D2 sounds
static int song[] = {
  NOTE_C4, NOTE_AS3, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, -1
};

//songTempo deals with more notes and keys
static int songTempo[] = {
  12, 3, 6, 12, 12, 3, 6, 12, 12, 3, 6, 12, 12, 6, 3, 12, 12, 12, 12,  12, 12, 12, 12, 6, 6, 6, 6,12, 12, 12, 12, 12,12, 12,
  12, 12, 12, 6, 6, 18, 18, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18,10, 10, 10, 10, 10, 10, 3, 3, 3, 3, 3, 3, 3, 
  };


// Default: 650
//1/4 duration
static unsigned short quarterDuration = 250;
//present note refers to the note currently on which starts at 0
static unsigned short present_note = 0;
//duration starts at 0
static unsigned short periodDuration = 0;

//the state of the buzzer
char buzzer_state = 0;
//code used from demos
void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR |= BIT6;		/* enable output to speaker (P2.6) */
    periodDuration = (int)(quarterDuration / songTempo[0]);
    buzzer_state = STATE_BUZZER_READY;
    present_note = 0;
}
//buzzer_play plays buzzer
void buzzer_play(){
  // Sets the state to playing from not playing
  buzzer_state = STATE_BUZZER_PLAYING;
  // Gets the present note from the song
  int note = song[present_note];
  // Check if the song has ended
  if(note < 0){
    //sets the state to ready
    buzzer_state = STATE_BUZZER_READY;
    present_note = 0;
    return;
  }
  // Turn on the red led when not playing
  //the 1 would turn on the red led when the note is 0 because the note is not playing
  //This if and else statement would make the led switch off from red to green as the notes are changing
  if(note == 0){
    setLed(1, 0);
  }
  // Turn on the green led when playing
  //the 1 would turn on the green light because the noe is playing and it is anything other than 0
  else{
    setLed(0, 1);
  }
  // Play the present note
  buzzer_set_period(note);
  // Update the note periodDuration
  periodDuration--;
  // We finished playing the note
  if(periodDuration <= 1){
    // Go to the next note
    present_note++;
    // Update the note periodDuration
    periodDuration = (int)(quarterDuration / songTempo[present_note]);
  } 
}

//buzzer_set_period is used to buzz 
void buzzer_set_period(short cycles)
{ 
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}
