// Write a program that displays the contents of a file as bytes and as
// characters. Have the user specify a file name on the command line.
//
// Each line
// shows 10 bytes from the file, as hexadecimal numbers and as characters. The
// number in the `Offset` column indicates the position within the file of the
// first byte on the line. Only printing characters (as determined by the
// `isprint` function) are displayed; other characters are shown as periods.
//
// Note that the appearance of a text file may vary, depending on the character
// set and the operating system.

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define READ_BLOCK_SIZE 10

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: 06 <filename>");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    fprintf(stderr, "error: could not open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  char buf[READ_BLOCK_SIZE];
  for (int i = 0;; i++) {
    printf("%6d ", i * READ_BLOCK_SIZE);
    printf(" ");

    int nmemb = fread(buf, sizeof(buf[0]), READ_BLOCK_SIZE, fp);
    if (nmemb == 0) {
      break;
    }

    int j;
    for (j = 0; j < nmemb; j++) {
      printf("%02X ", buf[j]);
    }
    for (j = nmemb; j < READ_BLOCK_SIZE; j++) {
      printf("   ");
    }
    printf(" ");

    char ch;
    for (j = 0; j < nmemb; j++) {
      ch = buf[j];
      printf("%c", isprint(ch) ? ch : '.');
    }
    printf("\n");

    if (nmemb != READ_BLOCK_SIZE) {
      break;
    }
  }

  if (ferror(fp)) {
    fprintf(stderr, "error: partial read: failed to read next block in %s\n",
            argv[1]);
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  fclose(fp);

  return 0;
}
