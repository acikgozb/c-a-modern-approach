// Modify the `justify` program of Section 15.3 so that it reads from one text
// file and writes to another. Have the program obtain the names of both files
// from the command line.

#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: justify <src-file> <dest-file>");
    exit(EXIT_FAILURE);
  }

  FILE *src = fopen(argv[1], "rb");
  if (src == NULL) {
    fprintf(stderr, "error: could not open src file\n");
    exit(EXIT_FAILURE);
  }

  FILE *dest = fopen(argv[2], "wb");
  if (dest == NULL) {
    fprintf(stderr, "error: could not create dest file\n");
    fclose(src);
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN + 1, src);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(dest);
      return 0;
    }

    if (word_len > MAX_WORD_LEN) {
      word[MAX_WORD_LEN] = '*';
    }

    if (word_len + 1 > space_remaining()) {
      write_line(dest);
      clear_line();
    }

    add_word(word);
  }

  fclose(src);
  fclose(dest);
  return 0;
}
