#include "word.h"
#include <stdio.h>

int read_char(FILE *src) {
  int ch = getc(src);
  if (ch == '\n' || ch == '\t') {
    return ' ';
  }

  return ch;
}

void read_word(char *word, int len, FILE *src) {
  int ch, pos = 0;

  // Skip leading whitespaces.
  while ((ch = read_char(src)) == ' ')
    ;

  while (ch != ' ' && ch != EOF) {
    if (pos < len) {
      word[pos++] = ch;
    }
    ch = read_char(src);
  }

  word[pos] = '\0';
}
