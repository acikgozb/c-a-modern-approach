// Write a program that reads a message, and then prints the reversal of the
// message using pointers.

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
    msg[pos] = ch;
    pos++;
  }

  printf("reversal is: ");
  for (int i = pos; i >= 0; i--) {
    printf("%c", msg[i]);
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
  for (p = &msg[0]; (ch = getchar()) != '\n' && p < &msg[0] + MSG_SIZE; p++) {
    *p = ch;
  }

  printf("reversal is: ");
  for (; p >= &msg[0]; p--) {
    printf("%c", *p);
  }
}

int main(void) {
  // with_int_pos();
  with_ptr_pos();
  return 0;
}
