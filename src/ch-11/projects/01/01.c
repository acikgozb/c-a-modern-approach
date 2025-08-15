// Modify Project 7 from Chapter 2 so that it includes the following function:
//
// void pay_amount(int dollars, int *twenties, int *tens, int *fives, int
// *ones);

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
  int amount;
  printf("enter a dollar amount: ");
  scanf("%d", &amount);

  int twenties, tens, fives, ones;
  pay_amount(amount, &twenties, &tens, &fives, &ones);

  printf("$20 bills: %d\n", twenties);
  printf("$10 bills: %d\n", tens);
  printf(" $5 bills: %d\n", fives);
  printf(" $1 bills: %d\n", ones);

  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / 20;
  dollars -= (20 * *twenties);

  *tens = dollars / 10;
  dollars -= (10 * *tens);

  *fives = dollars / 5;
  dollars -= (5 * *fives);

  *ones = dollars / 1;
}
