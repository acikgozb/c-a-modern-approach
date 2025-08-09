// Prints a date in legal form.
// e.g 7/19/14 -> Dated this 19th day of July, 2014.

#include <stdio.h>
int main(void) {
  int month, day, year;
  printf("enter date (mm/dd/yy): ");
  scanf("%2d/%2d/%2d", &month, &day, &year);

  printf("Dated this %d", day);
  switch (day % 10) {
  case 1:
    printf("st day of ");
    break;
  case 2:
    printf("nd day of ");
    break;
  case 3:
    printf("rd day of ");
    break;
  default:
    printf("th day of ");
    break;
  }

  switch (month) {
  case 1:
    printf("January");
    break;
  case 2:
    printf("February");
    break;
  case 3:
    printf("March");
    break;
  case 4:
    printf("April");
    break;
  case 5:
    printf("May");
    break;
  case 6:
    printf("June");
    break;
  case 7:
    printf("July");
    break;
  case 8:
    printf("August");
    break;
  case 9:
    printf("Septempber");
    break;
  case 10:
    printf("October");
    break;
  case 11:
    printf("November");
    break;
  case 12:
    printf("December");
    break;
  }

  printf(", 20%.2d.\n", year);

  return 0;
}
