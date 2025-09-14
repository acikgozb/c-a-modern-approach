// Calculates a broker's commission.

#include <stdio.h>

int main(void) {
  float commission, value;

  printf("enter value of the trade: ");
  scanf("%f", &value);

  if (value < 2500.00f) {
    commission = 30.00f + value * .017f;
  } else if (value < 6250.00f) {
    commission = 56.00f + value * .0066f;
  } else if (value < 20000.00f) {
    commission = 76.00f + value * .0034f;
  } else if (value < 50000.00f) {
    commission = 100.00f + value * .0022f;
  } else if (value < 500000.00f) {
    commission = 155.00f + value * .0011f;
  } else {
    commission = 255.00f + value * .0009f;
  }

  if (commission < 39.00f) {
    commission = 39.00f;
  }

  printf("commission: $%.2f", commission);

  return 0;
}
