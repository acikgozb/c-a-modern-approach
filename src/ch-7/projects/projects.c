// Contains solutions for the programming projects
// written in Section 7.

#include <ctype.h>
#include <math.h>
#include <stdio.h>

// When i is an int, the max value that does not cause
// an overflow is 46.343.
//
// When i is converted to short, the overflow causes i
// to reset and turns the loop into an infinite loop!
//
// When i is converted to long, the overflow limit
// significantly increases compared to the int version.
//
// Based on these results, it's apparent that the amount of bits
// can be written as short < int < long.
void proj1(void) {
  int num;
  printf("enter a number: ");
  scanf("%d", &num);

  int square;
  for (int i = 1; i < num; i++) {
    square = i * i;
    if (square <= num && square % 2 == 0) {
      printf("%u\n", square);
    }
  }
}

void proj2(void) {
  int num;
  printf("enter a number: ");
  scanf("%d", &num);
  getchar(); // read the remaning \n char on the stdin.

  int square;
  for (int i = 1; i < num; i++) {
    square = i * i;
    if (square <= num && square % 2 == 0) {
      printf("%d\n", square);
    }

    if ((i % 24) == 0) {
      printf("press enter to continue...");
      while (getchar() != '\n')
        ;
    }
  }
}

void proj3(void) {
  double n, sum = 0;
  printf("enter integers (0 to terminate): ");

  scanf("%lf",
        &n); // read input as double (notice the "l" conversion specifier).

  while (n != 0) {
    sum += n;
    scanf("%lf", &n);
  }

  printf("The sum is: %f\n", sum);
}

void proj4(void) {
  printf("enter phone number: ");
  char ch;
  while ((ch = getchar()) != '\n') {
    switch (ch) {
    case 'A':
    case 'B':
    case 'C':
      printf("2");
      break;

    case 'D':
    case 'E':
    case 'F':
      printf("3");
      break;

    case 'G':
    case 'H':
    case 'I':
      printf("4");
      break;

    case 'J':
    case 'K':
    case 'L':
      printf("5");
      break;

    case 'M':
    case 'N':
    case 'O':
      printf("6");
      break;

    case 'P':
    case 'R':
    case 'S':
      printf("7");
      break;

    case 'T':
    case 'U':
    case 'V':
      printf("8");
      break;

    case 'W':
    case 'X':
    case 'Y':
      printf("9");
      break;

    default:
      printf("%c", ch);
      break;
    }
  }
}

void proj5(void) {
  printf("enter a word: ");
  int val = 0;

  char i;
  while ((i = getchar()) != '\n') {
    int letter = toupper(i);
    switch (letter) {
    case 'Q':
    case 'Z':
      val += 10;
      break;
    case 'J':
    case 'X':
      val += 8;
      break;
    case 'K':
      val += 5;
      break;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      val += 4;
      break;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
      val += 3;
      break;
    case 'D':
    case 'G':
      val += 2;
      break;
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      val += 1;
      break;
    default:
      break;
    }
  }

  printf("scrabble value: %d", 12);
}

void proj6(void) {
  printf("size of short (bytes): %zu\n", sizeof(short));
  printf("size of int (bytes): %zu\n", sizeof(int));
  printf("size of long (bytes): %zu\n", sizeof(long));
  printf("size of float (bytes): %zu\n", sizeof(float));
  printf("size of double (bytes): %zu\n", sizeof(double));
  printf("size of long double (bytes): %zu\n", sizeof(long double));
}

void proj7(void) {
  int num1, denom1, num2, denom2;
  printf("enter two fractions: ");
  scanf("%d/%d", &num1, &denom1);
  int op = getchar();
  scanf("%d/%d", &num2, &denom2);

  int result_num, result_denom;

  switch (op) {
  case '+':
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    break;
  case '-':
    result_num = num1 * denom2 - num2 * denom1;
    result_denom = denom1 * denom2;
    break;
  case '*':
    result_num = num1 * num2;
    result_denom = denom1 * denom2;
    break;
  case '/':
    result_num = num1 * denom2;
    result_denom = denom1 * num2;
    break;
  }

  printf("the result is %d/%d", result_num, result_denom);
}

void proj8(void) {
  int hour, minute;
  char time_format;
  printf("enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute, &time_format);

  if (toupper(time_format) == 'P') {
    hour += 12;
  }

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

  if (dm_user <= dm1 + (dm2 - dm1) / 2) {
    printf("8:00 a.m., arriving at 10:16 a.m.\n");
  } else if (dm_user <= dm2 + (dm3 - dm2) / 2) {
    printf("9:43 a.m., arriving at 11:52 a.m.\n");
  } else if (dm_user <= dm3 + (dm4 - dm3) / 2) {
    printf("11:19 a.m., arriving at 1:31 p.m.\n");
  } else if (dm_user <= dm4 + (dm5 - dm4) / 2) {
    printf("12:47 p.m., arriving at 3:00 p.m.\n");
  } else if (dm_user <= dm5 + (dm6 - dm5) / 2) {
    printf("2:00 p.m., arriving at 4:08 p.m.\n");
  } else if (dm_user <= dm6 + (dm7 - dm6) / 2) {
    printf("3:45 p.m., arriving at 5:55 p.m.\n");
  } else if (dm_user <= dm7 + (dm8 - dm7) / 2) {
    printf("7:00 p.m., arriving at 9:20 p.m.\n");
  } else {
    printf("9:45 p.m., arriving at 11:58 p.m.\n");
  }
}

void proj9(void) {
  int hour, minute;
  char time_format;
  printf("enter a 12-hour time: ");
  scanf("%d:%d %c", &hour, &minute, &time_format);

  if (toupper(time_format) == 'P') {
    hour += 12;
  }

  printf("equivalent 24-hour time: %d:%d", hour, minute);
}

void proj10(void) {
  printf("Enter a sentence: ");

  int c_vowel = 0;
  char ch;
  while ((ch = getchar()) != '\n') {
    switch (toupper(ch)) {
    case 'A':
    case 'E':
    case 'O':
    case 'U':
    case 'I':
      c_vowel++;
      break;
    default:
      break;
    }
  }

  printf("your sentence contains %d vowels", c_vowel);
}

void proj11(void) {
  char f_letter;
  printf("enter a first and last name: ");
  scanf("%c ", &f_letter);

  char ch;
  // The remaining letters of the first name
  // are meaningless, so remove them from the
  // buffer.
  while ((ch = getchar()) != ' ')
    ;

  while ((ch = getchar()) != '\n') {
    if (ch == ' ') {
      continue;
    }

    printf("%c", ch);
  }

  printf(", %c.", f_letter);
}

void proj12(void) {
  printf("enter an expression: ");
  float result;
  scanf("%f", &result);

  float operand;
  char ch;
  while ((ch = getchar()) != '\n') {
    scanf("%f", &operand);
    switch (ch) {
    case '+':
      result += operand;
      break;
    case '-':
      result -= operand;
      break;
    case '*':
      result *= operand;
      break;
    case '/':
      result += operand;
      break;
    }
  }

  printf("value of expression: %.1f", result);
}

void proj13(void) {
  printf("enter a sentence: ");

  int w_count = 0;
  int ch_count;

  char ch;
  while ((ch = getchar()) != '\n') {
    if (ch == ' ' || ch == '.') {
      w_count++;
    } else {
      ch_count++;
    }
  }

  printf("average word length: %.1f", (float)ch_count / w_count);
}

void proj14(void) {
  int num;
  printf("enter a positive number: ");
  scanf("%d", &num);

  double sqrt = 1;

  double diff;
  while (1) {
    double division = num / sqrt;
    double avg = (sqrt + division) / 2;
    diff = fabs(sqrt - avg);
    if (diff < (sqrt * .00001)) {
      break;
    }

    sqrt = avg;
  }

  printf("square root: %.5f", sqrt);
}

// (a): When fact is a short, we can compute up to the factorial of 15.
// (b): When fact is an int, we can compute up to the factorial of 16.
// (c): When fact is a long, we can compute up to the factorial of 20.
// (d): When fact is a long long, we can compute up to the factorial of 20.
// (e): When fact is a float, we can compute up to the factorial of 34.
// (f): When fact is a double, we can compute up to the factorial of 170. (WHAT)
// (g): When fact is a double, we can compute up to the factorial of 1754.
// (WHAT)
void proj15(void) {
  int num;
  printf("enter a positive integer: ");
  scanf("%d", &num);

  int fact = 1;
  for (int i = 1; i <= num; i++) {
    fact *= i;
  }

  printf("factorial of %d: %d", num, fact);
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
  proj13();
  proj14();
  proj15();
  return 0;
}
