/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 6

int count = 0;

int is_prime(int n){
  for(int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void print_number(int n) {
  printf("%10d    ", n);
  count++;
  if(count == COLUMNS) {
    printf("\n");
    count = 0;
  }
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  int count = 0;

  for (int i = 2; i<n; i++) {
    if(is_prime(i) == 1) {
      print_number(i);
    }
  }


  // printf("%10d ", 2);
  // printf("%10d ", 3);
  // printf("%10d ", 5);
  // printf("%10d ", 7);
  // printf("%10d ", 11);
  // printf("%10d ", 13);
  // printf("\n");
  // printf("%10d ", 17);
  // printf("%10d ", 19);
  //
  // printf("\n");
}



// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  struct timespec t_start, t_stop;

  clock_gettime(CLOCK_MONOTONIC_RAW, &t_start);

  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");

  clock_gettime(CLOCK_MONOTONIC_RAW, &t_stop);

  long wall_sec = t_stop.tv_sec - t_start.tv_sec;
  long wall_nsec = t_stop.tv_nsec - t_start.tv_nsec;
  long wall_msec = (wall_sec *1000) + (wall_nsec / 1000000);

  printf("done in %ld ms\n", wall_msec);

  return 0;
}
