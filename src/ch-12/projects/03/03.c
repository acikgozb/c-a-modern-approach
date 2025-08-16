// Simplify Chapter 12 Project 1b by taking advantage of the fact that an array
// name can be used as a pointer.

#include <stdio.h>

#define MSG_SIZE 80

int main(void) {
  printf("enter a message: ");

  char msg[MSG_SIZE], *p;
  for (p = msg; p < msg + MSG_SIZE; p++) {
    *p = ' ';
  }

  char ch;
  for (p = msg; (ch = getchar()) != '\n' && p < msg + MSG_SIZE; p++) {
    *p = ch;
  }

  printf("reversal is: ");
  for (; p >= msg; p--) {
    printf("%c", *p);
  }

  return 0;
}
