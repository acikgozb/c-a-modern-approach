// Sums a series of numbers.

#include <stdio.h>

int main(void) {
  printf("this program sums a series of integers\n");
  printf("enter integers (0 to terminate): ");

  int sum;
  int num = -1;
  while (num != 0) {
    scanf("%d", &num);
    sum += num;
  }

  printf("the sum is %d\n", sum);
}
