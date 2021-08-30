#include <stdio.h>
#include <stdlib.h>

void foo(int *a, int b) {
  //int i;
  while(*a != 0) {
    *a += b;
    a++;
  }
}


int main(void) {
  int a[] = {4, 10, 100, 23, 99, 0};
  foo(a, 10);
  int i;
  int length = sizeof(a)/sizeof(a[0]);
  for(i = 0; i < length; i++) {
    printf("%d\n", a[i]);
  }
}
