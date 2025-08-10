// Contains solutions for the programming projects
// written in Section 6.

#include <stdio.h>

void proj1(void) {
  float num, largest = 0.00f;

  do {
    printf("enter a number: ");
    scanf("%f", &num);

    if (num > largest) {
      largest = num;
    }
  } while (num != 0.00f);

  printf("the largest number entered was %.2f", largest);
}

void proj2(void) {
  int n1, n2;
  printf("enter two integers: ");
  scanf("%d%d", &n1, &n2);

  while (n2 != 0) {
    int remainder = n1 % n2;
    n1 = n2;
    n2 = remainder;
  }

  printf("greatest common divisor: %d", n1);
}

void proj3(void) {
  int num, denom;
  printf("enter a fraction: ");
  scanf("%d/%d", &num, &denom);

  int gcd = num;
  int tmp = denom;
  while (tmp != 0) {
    int remainder = gcd % tmp;
    gcd = tmp;
    tmp = remainder;
  }

  int num_res = num / gcd;
  int denom_res = denom / gcd;

  printf("in lowest terms: %d/%d", num_res, denom_res);
}

void proj4(void) {
  float commission;
  int value;

  while (1) {
    printf("enter value of the trade: ");
    scanf("%d", &value);

    switch (value) {
    case 0:
      return;
    default:
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

      printf("commission: $%.2f\n", commission);
    }
  }
}

void proj5(void) {
  int num;
  printf("enter a number: ");
  scanf("%d", &num);

  int digit;
  do {
    digit = num % 10;
    num = num / 10;
    printf("%d", digit);
  } while (num != 0);

  printf("\n");
}

void proj6(void) {
  int num;
  printf("enter a number: ");
  scanf("%d", &num);

  int square;
  for (int i = 1; i < num; i++) {
    square = i * i;
    if (square <= num && square % 2 == 0) {
      printf("%d\n", square);
    }
  }
}

void proj7(void) {
  int n;

  printf("this program prints a table of squares.\n");
  printf("enter number of entries in the table: ");
  scanf("%d", &n);

  int odd = 1;
  int square = 1;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      square = i;
    } else {
      square += odd;
    }

    printf("%10d%10d\n", i, square);
    odd += 2;
  }
}

void proj8(void) {
  int n_days, starting_day;
  printf("enter number of days in month: ");
  scanf("%d", &n_days);
  printf("enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &starting_day);

  for (int i = 1; i <= n_days; i++) {
    if (i == 1) {
      printf("%*d ", starting_day * 2 + 2, i);
    } else {
      printf("%2d ", i);
    }

    if (i == n_days || (starting_day + i - 1) % 7 == 0) {
      printf("\n");
    }
  }
}

void proj9(void) {
  float loan, rate, payment;
  int num_payments;

  printf("enter amount of loan: ");
  scanf("%f", &loan);

  printf("enter interest rate: ");
  scanf("%f", &rate);

  printf("enter monthly payment: ");
  scanf("%f", &payment);

  printf("enter the number of payments: ");
  scanf("%d", &num_payments);

  float monthly_rate = (rate / 100) / 12;

  for (int i = 1; i <= num_payments; i++) {
    loan = (loan - payment) + (loan * monthly_rate);
    printf("balance remaining after the payment: $%.2f\n", loan);
  }
}

void proj10(void) {
  int month, day, year;
  int earliest = -1, e_month, e_day, e_year;

  while (1) {
    printf("enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    int days = year * 365 + month * 60 + day;
    if (days == 0) {
      break;
    }

    if (days < earliest || earliest == -1) {
      e_month = month;
      e_day = day;
      e_year = year;
      earliest = days;
    }
  }

  if (earliest != -1) {
    printf("%d/%d/%.2d is the earliest date", e_month, e_day, e_year);
  }
}

void proj11(void) {
  int n;
  printf("enter a number: ");
  scanf("%d", &n);

  float e = 1.00f;
  int fac = 1;
  for (int i = 2; i <= n; i++) {
    fac *= i;
    e += (1.00f / fac);
  }

  printf("%g", e);
}

void proj12(void) {
  int n;
  printf("enter a number: ");
  scanf("%d", &n);

  float target;
  printf("enter a small floating-point: ");
  scanf("%f", &target);

  float e = 1.00f;
  int fac = 1;
  for (int i = 2; target <= e; i++) {
    fac *= i;
    e += (1.00f / fac);
  }

  printf("%g", e);
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
  proj9();
  proj10();
  proj11();
  proj12();
  return 0;
}
