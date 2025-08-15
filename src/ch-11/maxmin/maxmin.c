// Finds the largest and smallest elements in an array.

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
  int i;

  *max = *min = a[0];

  for (i = 1; i < n; i++) {
    if (*max < a[i]) {
      *max = a[i];
    }

    if (*min > a[i]) {
      *min = a[i];
    }
  }
}
