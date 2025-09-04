// Write a program that converts all letters in a file to upper case.
// (Characters other than letters shouldn't be changed.)
// The program should obtain the file name from the command line and write it's
// output to `stdout`.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: 02 <filename>");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  if ((fp = fopen(*(++argv), "r")) == NULL) {
    fprintf(stderr, "error: cannot open file %s", *argv);
    exit(EXIT_FAILURE);
  }

  // NOTE: At first glance, this solution may look inefficient because we are
  // not reading in a buffered way here.
  //
  // However, `getc` uses a 8KB buffer internally, atleast on Linux.
  // Therefore we do not do OS read calls here on every single loop.
  //
  // Writing to stdout uses a similar internal buffer as well.
  int ch;
  while ((ch = getc(fp)) != EOF) {
    putc(isalpha(ch) ? toupper(ch) : ch, stdout);
  }

  fclose(fp);

  return 0;
}
