// Sorts an array of integers using Quicksort algorithm.

#include <stdio.h>

#define N 10

// Function declarations to prevent the compiler from implicitly assume a given
// function declaration (in C99, implicit declaration causes an error by
// default).
void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void) {
  int a[N], i;

  printf("enter %d numbers to be sorted: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  quicksort(a, 0, N - 1);

  printf("in sorted order: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");

  return 0;
}

void quicksort(int a[], int low, int high) {
  int middle;

  if (low >= high) {
    return;
  }

  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high) {
  int partition = a[low];
  for (;;) {
    while (low < high && partition <= a[high]) {
      high--;
    }
    if (low >= high) {
      break;
    }

    a[low++] = a[high];

    while (low < high && a[low] <= partition) {
      low++;
    }

    if (low >= high) {
      break;
    }

    a[high--] = a[low];
  }

  a[high] = partition;
  return high;
}
