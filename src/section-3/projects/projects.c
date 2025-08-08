// Contains solutions for the programming projects
// written in Section 3.

#include <stdio.h>

void proj1(void) {
  int month, day, year;

  printf("enter a date (mm/dd/yyyy): ");
  scanf("%02d/%02d/%4d", &month, &day, &year);

  printf("%4d%02d%02d\n", year, month, day);
}

void proj2(void) {
  int number;
  printf("enter item number: ");
  scanf("%d", &number);

  float price;
  printf("enter unit price: ");
  scanf("%f", &price);

  int purchase_month, purchase_day, purchase_year;
  printf("enter purchase date (mm/dd/yyyy): ");
  scanf("%02d/%02d/%4d", &purchase_month, &purchase_day, &purchase_year);

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  printf("%-8d\t$%8.2f\t%.2d/%.2d/%d\n", number, price, purchase_day,
         purchase_month, purchase_year);
}

void proj3(void) {
  int gsi, gid, publisher_code, item_number, check_digit;
  printf("enter ISBN: ");
  scanf("%3d-%d-%5d-%5d-%d", &gsi, &gid, &publisher_code, &item_number,
        &check_digit);

  printf("GSI prefix: %d\n", gsi);
  printf("Group identifier: %d\n", gid);
  printf("Publisher code: %d\n", publisher_code);
  printf("Item number: %d\n", item_number);
  printf("Check digit: %d\n", check_digit);
}

void proj4(void) {
  int p1, p2, p3;
  printf("enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%3d)%3d-%d", &p1, &p2, &p3);

  printf("you entered %d.%d.%d\n", p1, p2, p3);
}

// NOTE: YES.
void proj5(void) {
  int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;

  printf("enter the numbers from 1 to 16 in any order: \n");
  scanf("%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d%2d", &n1, &n2, &n3, &n4,
        &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);

  printf("%2d %2d %2d %2d\n\
%2d %2d %2d %2d\n\
%2d %2d %2d %2d\n\
%2d %2d %2d %2d\n",
         n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);

  printf("row sums: %d %d %d %d\n", n1 + n5 + n9 + n13, n2 + n6 + n10 + n14,
         n3 + n7 + n11 + n15, n4 + n8 + n12 + n16);
  printf("column sums: %d %d %d %d\n", n1 + n2 + n3 + n4, n5 + n6 + n7 + n8,
         n9 + n10 + n11 + n12, n13 + n14 + n15 + n16);
  printf("diagonal sums: %d %d\n", n1 + n6 + n11 + n16, n4 + n7 + n10 + n13);
}

void proj6(void) {
  int num1, denom1, num2, denom2;
  printf("enter two fractions separated by a plus sign: ");
  scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

  int result_num = num1 * denom2 + num2 * denom1;
  int result_denom = denom1 * denom2;

  printf("the sum is %d/%d", result_num, result_denom);
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
