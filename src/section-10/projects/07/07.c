// Write a program that displays the user-given number with seven-segment
// numbers.

#include <ctype.h>
#include <stdio.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 4
#define DIGIT_WIDTH 4
#define SEGMENT_COUNT 7

// Each digit is represented with seven different segments.
// If a segment is used for a digit, it is represented as 1.
// Otherwise, it's turned off (0).
//
// As an example, here is the seven-segment representation of the digit "8":
//  _
// |_|
// |_|
//
// Since all of the segments are used for the digit "8", they are all turned on.
int segments[MAX_DIGITS][SEGMENT_COUNT] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

char digits[DIGIT_HEIGHT][MAX_DIGITS * DIGIT_WIDTH];

void clear_digits_array(void);
void process_digit(int digit, int pos);
void print_digits_array(void);

int main(void) {
  clear_digits_array();

  printf("enter a number: ");
  char ch;
  int pos = 0;
  while ((ch = getchar()) != '\n') {
    if (pos == MAX_DIGITS) {
      break;
    }

    if (!isdigit(ch)) {
      continue;
    }

    process_digit(ch - '0', pos);
    pos++;
  }

  print_digits_array();

  return 0;
}

void clear_digits_array(void) {
  for (int i = 0; i < DIGIT_HEIGHT; i++) {
    for (int j = 0; j < MAX_DIGITS * 4; j++) {
      digits[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int pos) {
  for (int i = 0; i < SEGMENT_COUNT; i++) {
    if (segments[digit][i] == 0) {
      continue;
    }

    switch (i) {
    case 0:
      digits[0][1 + pos * DIGIT_WIDTH] = '_';
      break;
    case 1:
      digits[1][2 + pos * DIGIT_WIDTH] = '|';
      break;
    case 2:
      digits[2][2 + pos * DIGIT_WIDTH] = '|';
      break;
    case 3:
      digits[2][1 + pos * DIGIT_WIDTH] = '_';
      break;
    case 4:
      digits[2][0 + pos * DIGIT_WIDTH] = '|';
      break;
    case 5:
      digits[1][0 + pos * DIGIT_WIDTH] = '|';
      break;
    case 6:
      digits[1][1 + pos * DIGIT_WIDTH] = '_';
    default:
      break;
    }
  }
}

void print_digits_array(void) {
  for (int i = 0; i < DIGIT_HEIGHT; i++) {
    for (int j = 0; j < DIGIT_WIDTH * MAX_DIGITS; j++) {
      printf("%c", digits[i][j]);
    }
    printf("\n");
  }
}
