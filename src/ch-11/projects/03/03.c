// Modify Project 3 from Chapter 6 so that it includes the following function:
//
// void reduce(int numerator, int denominator, int *reduced_numerator, int
// *reduced_denominator);

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator);

int main(void) {
  int num, denom;
  printf("enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  int reduced_num;
  int reduced_denom;
  reduce(num, denom, &reduced_num, &reduced_denom);

  printf("in lowest terms: %d/%d", reduced_num, reduced_denom);
}

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator) {
  int gcd = numerator;
  int tmp = denominator;
  while (tmp != 0) {
    int remainder = gcd % tmp;
    gcd = tmp;
    tmp = remainder;
  }

  *reduced_numerator = numerator / gcd;
  *reduced_denominator = denominator / gcd;
}
