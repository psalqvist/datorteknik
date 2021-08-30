#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
int btns;
int sw;


int getsw() {

  sw = ((PORTD & 0x0f00) >> 8);       // mask bits 8 through 11, shift to LSB
  return sw;
}

int getbtns() {
  int btns_d;
  int btns_f;
  btns_d = ((PORTD & 0x00e0) >> 4);     // mask bits 5 through 7, shift to LSB
  btns_f = ((PORTF & 0x0002) >> 1);
  btns = btns_d | btns_f;
  return btns;
}
