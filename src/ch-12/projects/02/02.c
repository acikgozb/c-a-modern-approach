// Write a program that reads a message, then checks whether it's a palindrome
// using pointers.
//
// palindrome: the letters in a message being the same from left
// to right as right to left.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MSG_SIZE 80

// (a) Using an integer to track the msg array position.
void with_int_pos(void) {
  printf("enter a message: ");

  char msg[MSG_SIZE];
  for (int i = 0; i < MSG_SIZE; i++) {
    msg[i] = ' ';
  }

  char ch;
  int pos = 0;
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      msg[pos] = tolower(ch);
      pos++;
    }
  }

  int start = 0;
  int end = pos - 1;
  bool palindrome = true;
  while (start != end) {
    if (msg[end] != msg[start]) {
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
}

// (b) Using a pointer to track the msg array position.
void with_ptr_pos(void) {
  printf("enter a message: ");
  char msg[MSG_SIZE], *p;
  for (p = &msg[0]; p < &msg[0] + MSG_SIZE; p++) {
    *p = ' ';
  }

  char ch;
  for (p = &msg[0]; (ch = getchar()) != '\n' && p < &msg[0] + MSG_SIZE;) {
    if (isalpha(ch)) {
      *p++ = tolower(ch);
    }
  }

  char *start = &msg[0];
  char *end = &msg[0] + (p - &msg[0] - 1);
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
}

int main(void) {
  // with_int_pos();
  with_ptr_pos();
  return 0;
}
