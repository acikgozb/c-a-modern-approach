// Contains solutions for the programming projects
// written in Section 5.

#include <stdio.h>

void proj1(void) {
  int num;
  printf("enter a number: ");
  scanf("%d", &num);

  int digit = 1;
  if (num <= 99) {
    digit = 2;
  } else if (num <= 999) {
    digit = 3;
  } else if (num <= 9999) {
    digit = 4;
  }

  printf("the number %d has %d digits\n", num, digit);
}

void proj2(void) {
  int hour, minute;
  printf("enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);

  printf("equivalent 12-hour time: ");
  if (hour < 12) {
    printf("%d:%.2d AM\n", hour, minute);
  } else if (hour == 12) {
    printf("%d:%.2d PM\n", hour, minute);
  } else if (hour < 24) {
    printf("%d:%.2d PM\n", (hour - 12), minute);
  } else {
    printf("%d:%.2d AM\n", (hour - 24), minute);
  }
}

int proj3(void) {
  int share_count;
  float commission, price_per_share;

  printf("enter the number of shares: ");
  scanf("%d", &share_count);

  printf("enter the price per share: ");
  scanf("%f", &price_per_share);

  float rival_commission = 33.00f;
  if (share_count < 2000) {
    rival_commission += 0.03 * share_count;
  } else {
    rival_commission += 0.02 * share_count;
  }

  int trade_value = share_count * price_per_share;
  if (trade_value < 2500.00f) {
    commission = 30.00f + trade_value * .017f;
  } else if (trade_value < 6250.00f) {
    commission = 56.00f + trade_value * .0066f;
  } else if (trade_value < 20000.00f) {
    commission = 76.00f + trade_value * .0034f;
  } else if (trade_value < 50000.00f) {
    commission = 100.00f + trade_value * .0022f;
  } else if (trade_value < 500000.00f) {
    commission = 155.00f + trade_value * .0011f;
  } else {
    commission = 255.00f + trade_value * .0009f;
  }

  if (commission < 39.00f) {
    commission = 39.00f;
  }

  printf("commission: $%.2f\n", commission);
  printf("rival's commission: $%.2f\n", rival_commission);

  return 0;
}

void proj4(void) {
  int w_spd;
  printf("enter a wind speed (in knots): ");
  scanf("%d", &w_spd);

  printf("estimated wind force for %d knots is ", w_spd);
  if (w_spd < 1) {
    printf("calm\n");
  } else if (w_spd < 4) {
    printf("light air\n");
  } else if (w_spd < 28) {
    printf("breeze\n");
  } else if (w_spd < 48) {
    printf("gale\n");
  } else if (w_spd < 64) {
    printf("storm\n");
  } else {
    printf("hurricane\n");
  }
}

void proj5(void) {
  float income;
  printf("enter the amount of taxable income: ");
  scanf("%f", &income);

  float tax;
  if (income < 750.00f) {
    tax = income * .01f;
  } else if (income < 2250.00f) {
    tax = 7.50f + (income - 750.00f) * .02f;
  } else if (income < 3750.00f) {
    tax = 37.50f + (income - 2250.00f) * .03f;
  } else if (income < 5250.00f) {
    tax = 82.50f + (income - 3750.00f) * .04f;
  } else if (income < 7000.00f) {
    tax = 142.50f + (income - 5250.00f) * .05f;
  } else {
    tax = 230.00f + (income - 7000.00f) * .06f;
  }

  printf("tax due: $%.2f\n", tax);
}

void proj6(void) {
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, j6, first_sum, second_sum,
      total;

  printf("enter the first (single) digit: ");
  scanf("%1d", &d);

  printf("enter the first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

  printf("enter the second group of 6 digits: ");
  scanf("%1d%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5, &j6);

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  int check_digit = 9 - ((total - 1) % 10);
  if (check_digit == j6) {
    printf("VALID\n");
  } else {
    printf("NOT VALID\n");
  }
}

// NOTE: Divide and conquer can be used to satisfy the requirement:
// max 4 if statements.
//
// NOTE: To be fair, the best I could come up with before was 5 if
// statements.
//
// It's lovely to see that even though I've known about if statements
// from other languages,
// there is still a lot of value in doing practices about known topics
// instead of skipping them altogether, to improve our problem
// solving skills.
void proj7(void) {
  int i, j, k, l;
  printf("enter four integers: ");
  scanf("%d%d%d%d", &i, &j, &k, &l);

  int small1, large1, small2, large2, smallest, largest;

  // Find the small/large pair by checking the first two integers.
  if (i < j) {
    small1 = i;
    large1 = j;
  } else {
    small1 = j;
    large1 = k;
  }

  // Find the small/large pair by checking the last two integers.
  if (k < l) {
    small2 = k;
    large2 = l;
  } else {
    small2 = l;
    large2 = k;
  }

  // Compare the small/large pairs to find the final small/large pair.
  if (small1 < small2) {
    smallest = small1;
  } else {
    smallest = small2;
  }

  if (large1 < large2) {
    largest = large2;
  } else {
    largest = large1;
  }

  printf("largest: %d\n", largest);
  printf("smallest: %d\n", smallest);
}

void proj8(void) {
  int hour, minute;
  printf("enter a 24-hour time: ");
  scanf("%d:%d", &hour, &minute);

  int dm_user = hour * 60 + minute;
  int dm1 = 8 * 60;
  int dm2 = 9 * 60 + 43;
  int dm3 = 11 * 60 + 19;
  int dm4 = 12 * 60 + 47;
  int dm5 = 14 * 60;
  int dm6 = 15 * 60 + 45;
  int dm7 = 19 * 60;
  int dm8 = 21 * 60 + 45;

  printf("closest departure time is: ");

  if (dm_user <= dm1 + (dm1 + dm2) / 2) {
    printf("8:00 a.m., arriving at 10:16 a.m.\n");
  } else if (dm_user <= dm2 + (dm2 + dm3) / 2) {
    printf("9:43 a.m., arriving at 11:52 a.m.\n");
  } else if (dm_user <= dm3 + (dm3 + dm4) / 2) {
    printf("11:19 a.m., arriving at 1:31 p.m.\n");
  } else if (dm_user <= dm4 + (dm4 + dm5) / 2) {
    printf("12:47 p.m., arriving at 3:00 p.m.\n");
  } else if (dm_user <= dm5 + (dm5 + dm6) / 2) {
    printf("2:00 p.m., arriving at 4:08 p.m.\n");
  } else if (dm_user <= dm6 + (dm6 + dm7) / 2) {
    printf("3:45 p.m., arriving at 5:55 p.m.\n");
  } else if (dm_user <= dm7 + (dm7 + dm8) / 2) {
    printf("7:00 p.m., arriving at 9:20 p.m.\n");
  } else {
    printf("9:45 p.m., arriving at 11:58 p.m.\n");
  }
}

void proj9(void) {
  int m1, d1, y1, m2, d2, y2;
  printf("enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m1, &d1, &y1);

  printf("enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &m2, &d2, &y2);

  int days1 = d1 + m1 * 60 + y1 * 365;
  int days2 = d2 + m2 * 60 + y2 * 365;

  if (days1 < days2) {
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m1, d1, y1, m2, d2, y2);
  } else {
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m2, d2, y2, m1, d1, y1);
  }
}

void proj10(void) {
  int grade;
  printf("enter numerical grade: ");
  scanf("%d", &grade);

  if (grade < 0 || grade > 100) {
    printf("invalid grade %d", grade);
    return;
  }

  int significant_digit = grade / 10;
  switch (significant_digit) {
  case 10:
  case 9:
    printf("letter grade: A\n");
    break;
  case 8:
    printf("letter grade: B\n");
    break;
  case 7:
    printf("letter grade: C\n");
    break;
  case 6:
    printf("letter grade: D\n");
    break;
  case 5:
  case 4:
  case 3:
  case 2:
  case 1:
  case 0:
    printf("letter grade: F\n");
    break;
  default:
    break;
  }
}

void proj11(void) {
  int d1, d2, num;
  printf("enter a two-digit number: ");
  scanf("%d", &num);

  printf("you entered the number ");
  if (10 <= num && num <= 19) {
    switch (num) {
    case 10:
      printf("ten.");
      break;
    case 11:
      printf("eleven.");
      break;
    case 12:
      printf("twelve.");
      break;
    case 13:
      printf("thirteen.");
      break;
    case 14:
      printf("fourteen.");
      break;
    case 15:
      printf("fifteen.");
      break;
    case 16:
      printf("sixteen.");
      break;
    case 17:
      printf("seventeen.");
      break;
    case 18:
      printf("eightteen.");
      break;
    case 19:
      printf("nineteen.");
      break;
    default:
      break;
    }
    return;
  }

  d1 = num / 10;
  d2 = num % 10;

  switch (d1) {
  case 2:
    printf("twenty");
    break;
  case 3:
    printf("thirty");
    break;
  case 4:
    printf("forty");
    break;
  case 5:
    printf("fifty");
    break;
  case 6:
    printf("sixty");
    break;
  case 7:
    printf("seventy");
    break;
  case 8:
    printf("eighty");
    break;
  case 9:
    printf("ninety");
    break;
  }

  switch (d2) {
  case 0:
    printf(".");
    break;
  case 1:
    printf("-one.");
    break;
  case 2:
    printf("-two.");
    break;
  case 3:
    printf("-three.");
    break;
  case 4:
    printf("-four.");
    break;
  case 5:
    printf("-five.");
    break;
  case 6:
    printf("-six.");
    break;
  case 7:
    printf("-seven.");
    break;
  case 8:
    printf("-eight.");
    break;
  case 9:
    printf("-nine.");
    break;
  }
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
  return 0;
}
