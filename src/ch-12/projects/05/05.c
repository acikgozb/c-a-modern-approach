// Modify Chapter 8 Project 14 so that is uses a pointer instead of an integer
// to keep track of the current position in the array that contains the
// sentence.

#include <stdio.h>

#define MSG_SIZE 80

int main(void) {
  char msg[MSG_SIZE], *p;

  printf("enter a sentence: ");

  char ch;
  for (p = msg; p < msg + MSG_SIZE; p++) {
    ch = getchar();
    if (ch == '.' || ch == '?' || ch == '!') {
      break;
    }

    *p = ch;
  }

  char last_letter = ch;

  printf("reversal of sentence: ");

  char *word_end_pos = --p;
  for (; p >= msg; p--) {
    char letter = *p;
    if (letter == ' ' || p == msg) {
      if (p == msg) {
        printf("%c", letter);
      }
      for (char *j = p + 1; j <= word_end_pos; j++) {
        printf("%c", *j);
      }

      if (p != msg) {
        printf(" ");
      }

      word_end_pos = p - 1;
    }
  }

  printf("%c\n", last_letter);

  return 0;
}
