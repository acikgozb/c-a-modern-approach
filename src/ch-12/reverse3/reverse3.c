// Reverses a series of numbers (pointer version).

#include <stdio.h>

#define N 10

int main(void) {
  int a[N], *p;
  printf("enter %d numbers: ", N);
  for (p = a; p < a + N; p++) {
    scanf("%d", p);
  }

  printf("in reverse: ");
  for (p = a + N - 1; p >= a; p--) {
    printf("%d ", *p);
  }

  printf("\n");

  return 0;
}
