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

int prime = 1234567;

char textstring[] = "text, more text, and even more text!";
// TRISE
volatile int * trise = (volatile int *) 0xbf886100;
// PORTE
volatile int * porte = (volatile int *) 0xbf886110;
// tick counter
int count = 0;
int timeoutcount = 0;

/* Interrupt Service Routine */
void user_isr( void )
{
  if(IFS(0) & 0x100) {
    timeoutcount++;
    IFSCLR(0) = 0x100; // don't do it this way on surprise, use CLR
    if(timeoutcount == 10) {
      time2string( textstring, mytime );
      display_string( 3, textstring );
      display_update();
      tick( &mytime );
      timeoutcount = 0;
    }
  }
  if(IFS(0) & 0x080) {
    IFSCLR(0) = 0x080;
    count++;
    *porte = count;
  }
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  *trise = *trise & 0xff00;
  // set bits 5 through 11 to input -> 1
  TRISD = TRISD | 0x0fe0;
  // initialize porte to 0
  *porte = 0;

  /*
  Initialize timer 2.
  Sets TCKPS bits 4 through 6 to 111, thus a prescale of 1:256.
  This is because we can fit a max value in 16-bit reg of 65 536.
  Sets period to clock cyles per second devided by 10 to get 100 ms ->
  10 timeouts every second
  */
  // prescale 1:256
  T2CON = 0x70;
  PR2 = (80000000/256)/10;
  TMR2 = 0;
  T2CONSET = 0x8000; /* Start the timer */


  /* Initialize interupts */
  IEC(0) = IEC(0) | 0x100; /* Set bit 8 T2IE on timer 2 to 1 to enable interrupt */
  IPC(2) = IPC(2) | 0x1C;  /* Set priority (bits 4:2) to 7 */


  /* Initialize SW1 */
  IEC(0) = IEC(0) | 0x080; /* Set bit 7 INT1IE on SW to 1 to enable interrupt */
  IPC(1) = IPC(1) | 0x000000C1;

  enable_interrupt(); /* enable interrupts globally */



  return;
}




/* Test for a timeout event */
// int timertest(void) {
//   if(IFS(0) & 0x100) {
//     //IFS(0) = 0; // only works cause we only receive events from this timer
//     return 1;
//   }
//   return 0;
// }

/* This function is called repetitively from the main program */
void labwork( void ) {
  prime = nextprime( prime );
  display_string( 0, itoaconv( prime ) );
  display_update();
}
