// Checks numbers for repeated digits.

#include <stdbool.h>
#include <stdio.h>

#define N 10

int main(void) {
  bool digits[N] = {false};
  long n;

  int d;
  printf("enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    d = n % 10;
    if (digits[d]) {
      break;
    } else {
      digits[d] = true;
    }
    n /= 10;
  }

  if (n > 0) {
    printf("repeated digit");
  } else {
    printf("no repeated digit");
  }

  return 0;
}
