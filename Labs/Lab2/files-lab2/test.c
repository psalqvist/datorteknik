#include <stdio.h>

int main(void) {
  int* p;
  int a = 10;
  p = &a;
  printf("adress that p points to: %p\n", p);
  printf("adress of a: %p\n", &a);
  printf("value that p points to: %d\n", *p);
  printf("value of a: %d\n", a);

  //printf("value of the variable that p points to: %d\n", *p);
}
