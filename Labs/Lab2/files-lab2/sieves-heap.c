#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNS 6
int *arr;
int count = 0;

void print_number(int n) {
  printf("%10d    ", n);
  count++;
  if(count == COLUMNS) {
    printf("\n");
    count = 0;
  }
}

void print_sieves(int n) {

  for (int i = 0; i <= n; i++) {
    arr[i] = 1;
  }

  for (int p = 2; p*p <= n; p++) {
    if(arr[p] == 1) {
      for(int i = p*p; i <= n; i += p) {
        arr[i] = 0;
      }
    }
  }

  for(int i = 2; i <= n; i++) {
    if(arr[i] == 1) {
      print_number(i);
    }
  }
}

int main(int argc, char *argv[]){

  struct timespec t_start, t_stop;

  clock_gettime(CLOCK_MONOTONIC_RAW, &t_start);

  if(argc == 2) {
    arr = (int *)malloc(atoi(argv[1])*sizeof(int));
    print_sieves(atoi(argv[1]));
  }
  else
    printf("Please state an interger number.\n");

  free(arr);

  clock_gettime(CLOCK_MONOTONIC_RAW, &t_stop);

  long wall_sec = t_stop.tv_sec - t_start.tv_sec;
  long wall_nsec = t_stop.tv_nsec - t_start.tv_nsec;
  long wall_msec = (wall_sec *1000) + (wall_nsec / 1000000);

  printf("done in %ld ms\n", wall_msec);

  return 0;
}
