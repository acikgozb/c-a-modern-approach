// Sums a series of integers (using long variables).

#include <stdio.h>

int main(void) {
  long n, sum = 0;
  printf("enter integers (0 to terminate): ");

  scanf("%ld", &n); // read input as long (notice the "l" conversion specifier).

  while (n != 0) {
    sum += n;
    scanf("%ld", &n);
  }

  printf("The sum is: %ld\n", sum);

  return 0;
}
