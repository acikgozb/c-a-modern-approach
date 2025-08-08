// Contains solutions for the programming projects
// written in Section 2.

#include <stdio.h>

void proj1(void) {
  printf("        * \n\
       *  \n\
      *   \n\
     *    \n\
*   *     \n\
 * *      \n\
  *       \n");
}

void proj2(void) {
  double pi = 22.0f / 7.0f;
  int radius = 10;
  float volume = (4.0f / 3.0f) * pi * radius * radius * radius;

  printf("sphere volume: %.2f\n", volume);
}

void proj3(void) {
  double pi = 22.0f / 7.0f;

  int radius;
  printf("enter radius: ");
  scanf("%d", &radius);

  float volume = (4.0f / 3.0f) * pi * radius * radius * radius;
  printf("sphere volume: %.2f\n", volume);
}

void proj4(void) {
  float amount;

  printf("enter an amount: ");
  scanf("%f", &amount);

  float tax = amount * 0.05;
  printf("With tax added: %.2f\n", amount + tax);
}

void proj5(void) {
  int x;
  printf("enter a value: ");
  scanf("%d", &x);

  int x_squared = x * x;
  int x_cubed = x_squared * x;
  int x_root_four = x_cubed * x;
  int x_root_five = x_root_four * x;

  int result =
      3 * x_root_five + 2 * x_root_four - 5 * x_cubed - x_squared + 7 * x - 6;
  printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %d\n", result);
}

void proj6(void) {
  int x;
  printf("enter a value: ");
  scanf("%d", &x);

  int result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
  printf("((((3x + 2)x - 5)x - 1)x + 7)x - 6) = %d\n", result);
}

void proj7(void) {
  int amount;
  printf("enter a dollar amount: ");
  scanf("%d", &amount);

  int twenties = amount / 20;
  printf("$20 bills: %d\n", twenties);
  amount = amount - (twenties * 20);

  int tens = amount / 10;
  printf("$10 bills: %d\n", tens);
  amount = amount - (tens * 10);

  int fives = amount / 5;
  printf(" $5 bills: %d\n", fives);
  amount = amount - (fives * 5);

  int ones = amount / 1;
  printf(" $1 bills: %d\n", ones);
}

void proj8(void) {
  float loan, rate, payment;

  printf("enter amount of loan: ");
  scanf("%f", &loan);

  printf("enter interest rate: ");
  scanf("%f", &rate);

  printf("enter monthly payment: ");
  scanf("%f", &payment);

  printf("\n");

  float monthly_rate = (rate / 100) / 12;

  loan = (loan - payment) + (loan * monthly_rate);
  printf("balance remaining after first payment: $%.2f\n", loan);

  loan = (loan - payment) + (loan * monthly_rate);
  printf("balance remaining after second payment: $%.2f\n", loan);

  loan = (loan - payment) + (loan * monthly_rate);
  printf("balance remaining after third payment: $%.2f\n", loan);
}

int main(void) {
  proj1();
  proj2();
  proj3();
  proj4();
  proj5();
  proj6();
  proj7();
  proj8();
  return 0;
}
