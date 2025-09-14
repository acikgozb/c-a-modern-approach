// Write a program that reads integers from a text file whose name is given as a
// command-line argument. Each line of the file may contain any number of
// integers (including none) separated by one or more spaces. Have the program
// display the largest number in the file, the smallest number, and the median
// (the number closes to the middle if the integers were sorted).
// If the file contains an even number of integers, there will be two numbers in
// the middle; the program should display their average (rounded down). You may
// assume that the file contains no more than 10.000 integers.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int cmp(const void *i1, const void *i2);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ints <list-file>");
    exit(EXIT_FAILURE);
  }

  FILE *src = fopen(argv[1], "rb");
  if (src == NULL) {
    fprintf(stderr, "error: could not open the list file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // NOTE: On the host that this solution is developed,
  // the allowed stack size is a lot higher than this array,
  // which is 10k * sizeof(int) -> 40k bytes.
  // Therefore, the array below can be safely allocated on the stack.
  int nums[SIZE] = {0};
  int i = 0, curr = 0;
  while (1) {
    int n = fscanf(src, "%d ", &curr);
    if (n == EOF) {
      break;
    }

    nums[i++] = curr;
  }

  int len = i + 1;
  qsort(nums, len, sizeof(int), cmp);

  printf("the largest number in %s is %d\n", argv[1], nums[i]);
  printf("the smallest number in %s is %d\n", argv[1], nums[0]);

  int median;
  if (len % 2 != 0) {
    median = nums[len / 2];
  } else {
    int mid = len / 2;

    median = (nums[mid - 1] + nums[mid + 1]) / 2;
  }
  printf("the median number in %s is %d\n", argv[1], median);

  return 0;
}

int cmp(const void *i1, const void *i2) { return *(int *)i1 - *(int *)i2; }
