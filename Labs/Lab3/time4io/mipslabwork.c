/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include <stdio.h>


int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";
// TRISE
volatile int * trise = (volatile int *) 0xbf886100;
// PORTE
volatile int * porte = (volatile int *) 0xbf886110;
// tick counter
int count = 0;

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  // Set 7 through 0 as outputs
  *trise = *trise & 0x00ff;
  *porte = 0;
  // Har nog gjort detta fel, input bitar ska vara 0, ändra inte resten
  // möjligt att jag isåfall även gjort fel i time4io
  //TRISD = TRISD & (127 << 5);
  // set bits 5 through 11 to input -> 1
  TRISD = TRISD | 0x0fe0;
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  // every tick, increment porte to change led
  *porte = count;
  //*porte = *(getsw());
  count++;
  // if button 4 is pressed
  if(getbtns() & 4) {
    mytime = (mytime & 0x0fff) | (getsw() << 12);
  }
  // if button 3 is pressed
  if(getbtns() & 2) {
    mytime = (mytime & 0xf0ff) | (getsw() << 8);
  }
  // if button 2 is pressed
  if(getbtns() & 1) {
    mytime = (mytime & 0xff0f) | (getsw() << 4);
  }



  display_image(96, icon);
}
