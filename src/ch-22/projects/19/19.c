// (a) Write a program that converts a Windows text file to a UNIX text file.
// (b) Write a program that converts a UNIX text file to a Windows text file.
// In each case, have the program obtain the names of both files from the
// command line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write_as_unix(FILE *src, FILE *dest);
int write_as_win(FILE *src, FILE *dest);

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: fconv <unix|win> <src> <dest>");
    exit(EXIT_FAILURE);
  }

  FILE *src = fopen(argv[2], "rb");
  if (src == NULL) {
    fprintf(stderr, "error: could not open src file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  FILE *dest = fopen(argv[3], "wb");
  if (dest == NULL) {
    fprintf(stderr, "error: could not open dest file %s\n", argv[3]);
    fclose(src);
    exit(EXIT_FAILURE);
  }

  if (strcmp(argv[1], "unix") == 0) {
    if (write_as_unix(src, dest) != 0) {
      fprintf(stderr, "error: could not convert file %s to UNIX\n", argv[2]);
      fclose(src);
      fclose(dest);
      remove(argv[3]);
      exit(EXIT_FAILURE);
    }
  } else if (strcmp(argv[1], "win") == 0) {
    if (write_as_win(src, dest) != 0) {
      fprintf(stderr, "error: could not convert file %s to Windows\n", argv[2]);
      fclose(src);
      fclose(dest);
      remove(argv[3]);
      exit(EXIT_FAILURE);
    }
  }

  fclose(src);
  fclose(dest);
  return 0;
}

// NOTE: To convert a Windows file to a UNIX file,
// simply do not add the carriage return byte.
int write_as_unix(FILE *src, FILE *dest) {
  int ch;
  while ((ch = getc(src)) != EOF) {
    if (ch == '\r') {
      continue;
    }

    if (putc(ch, dest) == EOF) {
      return -2;
    }
  }

  if (ferror(src)) {
    // NOTE: reset the file position.
    rewind(src);
    return -1;
  }

  return 0;
}

// NOTE: To convert a UNIX file to Windows, add a preceding
// carriage return byte whenever a line feed byte is encountered.
int write_as_win(FILE *src, FILE *dest) {
  int ch;
  while ((ch = getc(src)) != EOF) {
    if (ch == '\n') {
      putc('\r', dest);
    }

    if (putc(ch, dest) == EOF) {
      return -2;
    }
  }

  if (ferror(src)) {
    // NOTE: reset the file position.
    rewind(src);
    return -1;
  }

  return 0;
}
