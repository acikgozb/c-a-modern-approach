// Modify Project 1 from Chapter 12 so that it includes the following function:
//
// void reverse (char *message);
//
// The function reverses the string pointed to by `message`.

#include <stdio.h>
#include <string.h>

#define MSG_SIZE 81

void reverse(char *message);

int main(void) {
  printf("enter a message: ");

  char msg[MSG_SIZE], *p = msg;
  int ch;
  while (p < msg + MSG_SIZE) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    *p++ = ch;
  }
  *p = '\0';

  reverse(msg);
  printf("reversal is: %s\n", msg);

  return 0;
}

void reverse(char *message) {
  char *start = message;
  char *end = start + strlen(message) - 1;
  char tmp;
  while (start < end) {
    tmp = *end;
    *end = *start;
    *start = tmp;

    start++;
    end--;
  }
}
