// Modify Project 5 from Chapter 7 so that it includes the following function:
//
// int compute_scrabble_value(const char *word);

#include <ctype.h>
#include <stdio.h>

#define WRD_LEN 21
#define ALPHABET_SIZE 26

int compute_scrabble_value(const char *wrd);

int main(void) {
  printf("enter a word: ");

  char wrd[WRD_LEN];
  int i = 0;
  for (; i < WRD_LEN; i++) {
    int ch = getchar();
    if (ch == '\n') {
      break;
    }
    *(wrd + i) = tolower(ch);
  }
  *(wrd + i) = '\0';

  int val = compute_scrabble_value(wrd);
  printf("scrabble value: %d", val);

  return 0;
}

int compute_scrabble_value(const char *wrd) {
  int values[ALPHABET_SIZE] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  int val = 0;

  while (*wrd) {
    val += values[(*wrd++ - 'a')];
  }

  return val;
}
