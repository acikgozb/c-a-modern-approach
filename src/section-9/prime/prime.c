// Tests whether a number is prime.

#include <stdbool.h>
#include <stdio.h>

bool is_prime(int num) {
  int divisor;

  if (num <= 1) {
    return false;
  }

  for (divisor = 2; divisor * divisor <= num; divisor++) {
    if (num % divisor == 0) {
      return false;
    }
  }

  return true;
}

int main(void) {
  printf("enter a number: ");
  int num;
  scanf("%d", &num);

  if (is_prime(num)) {
    printf("prime\n");
  } else {
    printf("not prime\n");
  }

  return 0;
}
