#include <stdio.h>
#include <stdlib.h>
void something(int* foo, int l, int v) {
  int i;
  for(i = 0; i < l; i++) {
    *foo *= v;
    foo++;
  }
}

int main(void) {
  int k1[] = {2, 2, 3, 3, 10};
  something(k1, 5, 4);
  int i;
  for(i = 0; i < 5; i++) {
    printf("%d\n", k1[i]);
  }
}
