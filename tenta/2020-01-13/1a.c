#include "stdio.h"

int a[] = {7,10,3,5,12,8,17,-8,4,5};
int x[] = {8,2,0};

int sum(int* p1, int* p2, int len){
  int i = 0;
  int s = 0;
  while(i < len){
    s += *(p1+(*p2));
    p2++;
    i++;
  }
  return s;
}
int main() {
  int v = sum(a,x,3);
  printf("Sum %d\n", v);
  return 0;
}
