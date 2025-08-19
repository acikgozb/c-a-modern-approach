// Write a program that accepts a date form the user in the form `mm/dd/yyyy`
// and then displays it in the form `month dd, yyyy`, where `month` is the name
// of the month.
//
// Example:
// 2/17/2011 -> February 17, 2011

#include <stdio.h>

int main(void) {
  char *months[] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

  printf("enter a date (mm/dd/yyyy): ");
  int month, day, year;
  scanf("%2d/%2d/%4d", &month, &day, &year);

  // NOTE: The inputs are intentionally not validated.
  printf("you entered the date %s %2d, %4d.", months[month - 1], day, year);

  return 0;
}
