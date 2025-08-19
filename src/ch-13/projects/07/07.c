// Modify Project 11 from Chapter 5 so that it uses arrays containing pointers
// to strings instead of switch statements.

#include <stdio.h>

int main(void) {
  char *specials[] = {"ten",      "eleven",  "twelve",  "thirteen",
                      "fourteen", "fifteen", "sixteen", "seventeen",
                      "eighteen", "nineteen"};

  char *first_digits[] = {"twenty", "thirty",  "forty",  "fifty",
                          "sixty",  "seventy", "eighty", "ninety"};

  char *second_digits[] = {"",     "one", "two",   "three", "four",
                           "five", "six", "seven", "eight", "nine"};

  printf("enter a two-digit number: ");
  int num;
  scanf("%d", &num);

  printf("you entered the number ");
  if (10 <= num && num <= 19) {
    printf("%s.", specials[num % 10]);
  } else {
    int d1 = num / 10;
    int d2 = num % 10;

    char *w1 = first_digits[d1 - 2];
    char *w2 = second_digits[d2];

    if (!d2) {
      printf("%s.", w1);
    } else {
      printf("%s-%s.", w1, w2);
    }
  }

  return 0;
}
