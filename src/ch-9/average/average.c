// Computes pairwise averages of three numbers.

#include <stdio.h>

double average(double x, double y) { return (x + y) / 2; }

int main(void) {
  printf("enter three numbers: ");

  double n1, n2, n3;
  scanf("%lf%lf%lf", &n1, &n2, &n3);

  printf("average of %g and %g: %g\n", n1, n2, average(n1, n2));
  printf("average of %g and %g: %g\n", n1, n3, average(n1, n3));
  printf("average of %g and %g: %g\n", n2, n3, average(n2, n3));

  return 0;
}
