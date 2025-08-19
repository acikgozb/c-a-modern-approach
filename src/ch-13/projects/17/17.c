// Modify Project 2 from Chapter 12 so that it includes the following function:
//
// bool is_palindrome(const char *message);
//
// The function returns `true` if the string pointed to by `message` is a
// palindrome.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MSG_SIZE 81

bool is_palindrome(const char *message);

int main(void) {
  printf("enter a message: ");
  char msg[MSG_SIZE], *p = msg;

  char ch;
  while (p < msg + MSG_SIZE) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    if (!isalpha(ch)) {
      continue;
    }

    *p++ = tolower(ch);
  }

  if (is_palindrome(msg)) {
    printf("palindrome");
  } else {
    printf("not a palindrome");
  }

  return 0;
}

bool is_palindrome(const char *message) {
  bool is_palindrome = true;

  const char *start = message;
  const char *end = start + strlen(message) - 1;
  while (start < end) {
    if (*start != *end) {
      is_palindrome = false;
      break;
    }

    start++;
    end--;
  }

  return is_palindrome;
}
