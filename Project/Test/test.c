/* mipslabmain.c

   This file written 2015 by Axel Isaksson,
   modified 2015, 2017 by F Lundevall

	 modified 2021 by Philip Salqvist

   Latest update 2017-04-21 by F Lundevall

   For copyright and licensing, see file COPYING */

#include "structs.h"
#include "func.h"
#include <stdlib.h>
#include <stdio.h>

Player player1 = {0, 12, 8, 0};

void init_player(Player *p) {
	(*p).x = 0;
	(*p).y = 12;
	(*p).height = 20;
	(*p).points = 0;
}

void test_print(Player p) {
  printf("height: %hi\n", p.height);
}

int main(void) {

	init_player(&player1);
  test_print(player1);

	return 0;
}
