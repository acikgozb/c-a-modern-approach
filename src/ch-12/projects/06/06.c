// Modify the `qsort.c` program of Section 9.6 so that `low, high` and `middle`
// are pointers to array elements rather than integers.
//
// The split function will need to return a pointer, not an integer.

#include <stdio.h>

#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void) {
  int a[N], *i;

  printf("enter %d numbers to be sorted: ", N);
  for (i = a; i < a + N; i++) {
    scanf("%d", i);
  }

  quicksort(a, a, a + (N - 1));

  printf("in sorted order: ");
  for (i = a; i < a + N; i++) {
    printf("%d ", *i);
  }

  printf("\n");

  return 0;
}

void quicksort(int a[], int *low, int *high) {
  int *middle;

  if (low >= high) {
    return;
  }

  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high) {
  int partition = *low;
  for (;;) {
    while (low < high && partition <= *high) {
      high--;
    }
    if (low >= high) {
      break;
    }

    *(a + (low++ - a)) = *high;

    while (low < high && *low <= partition) {
      low++;
    }

    if (low >= high) {
      break;
    }

    *(a + (high-- - a)) = *low;
  }

  *high = partition;
  return high;
}
