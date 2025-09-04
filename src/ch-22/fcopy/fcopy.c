// Copies a file.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE *src, *dest;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy <src> <dest>");
    exit(EXIT_FAILURE);
  }

  // NOTE: "b" flag is used to support binary files along with text files.
  if ((src = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  int ch;
  while ((ch = getc(src)) != EOF) {
    putc(ch, dest);
  }

  fclose(src);
  fclose(dest);

  return 0;
}
