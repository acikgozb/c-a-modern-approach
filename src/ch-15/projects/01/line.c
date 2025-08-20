#include "line.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;
bool alternate = false; // Start with bigger spaces at the end.

void clear_line(void) {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }

  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

int get_spaces_to_insert(int extra_spaces, int num_words, bool alternate) {
  int spaces;

  // NOTE: There is more than a single solution
  // to start with bigger spaces.
  // This solution below simply inverts the original
  // calcuation (non-alternated case) and adjust the
  // denominator to not get a zero value.
  if (alternate) {
    spaces = num_words % (extra_spaces + 1);
  } else {
    spaces = extra_spaces / (num_words - 1);
  }

  alternate = !alternate;

  return spaces;
}

void write_line(void) {
  int extra_spaces, spaces_to_insert, i, j;
  alternate = !alternate;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ') {
      putchar(line[i]);
    } else {
      spaces_to_insert =
          get_spaces_to_insert(extra_spaces, num_words, alternate);
      for (j = 1; j <= spaces_to_insert + 1; j++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }

  putchar('\n');
}

void flush_line(void) {
  if (line_len > 0) {
    puts(line);
  }
}
