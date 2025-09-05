// The `xor.c` program of Section 20.1 refuses to encrypt bytes that - in
// original or encrypted form - are control characters. We can now remove this
// restriction.
//
// Modify the program so that the names of the input and output files are
// command-line arguments. Open both files in binary mode, and remove the test
// that checks whether the original and encrypted characters are printing
// characters.

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char **argv) {
  if (argc == 1 || argc > 3) {
    fprintf(stderr, "usage: xor <in> [out], out is stdout by default\n");
    exit(EXIT_FAILURE);
  }

  FILE *in = fopen(argv[1], "rb");
  if (in == NULL) {
    fprintf(stderr, "error: could not open input file %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *out;
  if (argv[2] == NULL) {
    out = stdout;
  } else {
    out = fopen(argv[2], "wb");
    if (out == NULL) {
      fprintf(stderr, "error: could not open output file %s", argv[2]);
      exit(EXIT_FAILURE);
    }
  }

  int in_char, out_char;
  while ((in_char = getc(in)) != EOF) {
    out_char = in_char ^ KEY;
    fputc(out_char, out);
  }

  fclose(in);
  fclose(out);
  return 0;
}
