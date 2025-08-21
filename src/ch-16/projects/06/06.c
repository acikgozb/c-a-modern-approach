// Modify Project 9 from Chapter 5 so that each date netered by the user is
// stored in a `date` structure. Incorporate the `compare_dates` function of
// Exercise 5 into your program.

#include <stdio.h>

struct date {
  int year;
  int month;
  int day;
};

void compare_dates(const struct date *d1, const struct date *d2);

int main(void) {
  struct date d1, d2;

  printf("enter first date (mm/dd/yy): ");
  scanf("%2d/%2d/%4d", &d1.month, &d1.day, &d1.year);

  printf("enter second date (mm/dd/yy): ");
  scanf("%2d/%2d/%4d", &d2.month, &d2.day, &d2.year);

  compare_dates(&d1, &d2);

  return 0;
}

void compare_dates(const struct date *d1, const struct date *d2) {
  int days1 = d1->year * 365 + d1->month * 30 + d1->day;
  int days2 = d2->year * 365 + d2->month * 30 + d2->day;

  if (days1 < days2) {
    printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d", d1->month, d1->day,
           d1->year, d2->month, d2->day, d2->year);
  } else {
    printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d", d2->month, d2->day,
           d2->year, d1->month, d1->day, d1->year);
  }
}
