// Modify the `maxmin.c` program of Section 11.4 so that the `max_min` function
// uses a pointer instead of an integer to keep track of the current position in
// the array.

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void) {
  int b[N], big, small;

  printf("enter %d numbers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  max_min(b, N, &big, &small);

  printf("largest: %d\n", big);
  printf("smallest: %d\n", small);

  return 0;
}

void max_min(int a[], int n, int *max, int *min) {
  int *i;

  *max = *min = a[0];

  for (i = a + 1; i < a + n; i++) {
    if (*max < *i) {
      *max = *i;
    }

    if (*min > *i) {
      *min = *i;
    }
  }
}
