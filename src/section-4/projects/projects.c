// Contains solutions for the programming projects
// written in Section 4.

#include <stdio.h>

void proj1(void) {
  int num;
  printf("enter a two-digit number: ");
  scanf("%d", &num);

  int first_digit = num / 10;
  int last_digit = num % 10;

  printf("the reversal is: %d%d", last_digit, first_digit);
}

void proj2(void) {
  int num;
  printf("enter a three-digit number: ");
  scanf("%d", &num);

  int first_digit = num / 100;
  int second_digit = (num % 100) / 10;
  int last_digit = num % 10;

  printf("the reversal is: %d%d%d", last_digit, second_digit, first_digit);
}

void proj3(void) {
  int d1, d2, d3;
  printf("enter a three-digit number: ");
  scanf("%1d%1d%1d", &d1, &d2, &d3);

  printf("the reversal is: %d%d%d", d3, d2, d1);
}

void proj4(void) {
  int num, d1, d2, d3, d4, d5;
  printf("enter a number between 0 and 32767: ");
  scanf("%d", &num);

  d1 = d2 = d3 = d4 = d5 = 0;

  d1 = num % 8;
  num = num / 8;

  d2 = num % 8;
  num = num / 8;

  d3 = num % 8;
  num = num / 8;

  d4 = num % 8;
  num = num / 8;

  d5 = num % 8;
  num = num / 8;

  printf("in octal, your number is: %d%d%d%d%d", d5, d4, d3, d2, d1);
}

void proj5(void) {
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;
  printf("enter the first 11 digits of a UPC: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1,
        &j2, &j3, &j4, &j5);

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  printf("check digit: %d\n", 9 - ((total - 1) % 10));
}

void proj6(void) {
  int d, i1, i2, i3, i4, i5, i6, j1, j2, j3, j4, j5, first_sum, second_sum,
      total;
  printf("enter the first 12 digits of a EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5,
        &i6, &j1, &j2, &j3, &j4, &j5);

  first_sum = i1 + i3 + i5 + j1 + j3 + j5;
  second_sum = d + i2 + i4 + i6 + j2 + j4;
  total = 3 * first_sum + second_sum;

  printf("check digit: %d\n", 9 - ((total - 1) % 10));
}

int main(void) {
  proj1();
  proj2();
  proj3();
  proj4();
  proj5();
  proj6();
  return 0;
}
