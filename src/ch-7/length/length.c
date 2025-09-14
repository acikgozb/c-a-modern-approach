// Determine the length of a message.

#include <stdio.h>
int main(void) {
  int len = 0;

  printf("enter a message: ");
  while (getchar() != '\n') {
    len++;
  }

  printf("your message was %d characters long\n.", len);

  return 0;
}
