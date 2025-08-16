// Simplify Chapter 12 Project 2b by taking advantage of the fact that an array
// name can be used as a pointer.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MSG_SIZE 80

int main(void) {
  printf("enter a message: ");
  char msg[MSG_SIZE], *p;
  for (p = msg; p < msg + MSG_SIZE; p++) {
    *p = ' ';
  }

  char ch;
  for (p = msg; (ch = getchar()) != '\n' && p < msg + MSG_SIZE;) {
    if (isalpha(ch)) {
      *p++ = tolower(ch);
    }
  }

  char *start = msg;
  char *end = msg + (p - msg - 1);
  bool palindrome = true;
  while ((end - start) != 0) {
    if (*start != *end) {
      palindrome = false;
      break;
    }

    start++;
    end--;
  }

  if (palindrome) {
    printf("palindrome");
  } else {
    printf("not a palindrome");
  }

  return 0;
}
