// (a) Write a program named `compress_file` that uses run-length encoding to
// compress a file. `compress_file` will create a new file named `filename.rle`.
//
// (b) Write a program named `decompress_file` that reverses the compression
// performed by the `compress_file` program. `decompress_file` should use a file
// with `.rle` extension.
//
// run-length encoding: Replacing sequences of identical bytes by a pair of
// bytes: a repetition count followed by the byte to be repeated.
// e.g.: sequence: 46 6f 6f 20 62 61 72 21 21 21 20 20 20 20 20
//       compressed: 01 46 02 6f 01 20 01 62 01 61 01 72 03 21 05 20

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAIR 2

void compress_file(char *filename);
void decompress_file(char *filename);

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: 07 <compress|decompress> <filename>\n");
    exit(EXIT_FAILURE);
  }

  if (strcmp(argv[1], "compress") == 0) {
    compress_file(argv[2]);
  } else if (strcmp(argv[1], "decompress") == 0) {
    decompress_file(argv[2]);
  } else {
    fprintf(stderr,
            "error: invalid argument %s\nusage: 07 <compress|decompress> "
            "<filename>\n",
            argv[1]);
    exit(EXIT_FAILURE);
  }

  return 0;
}

void compress_file(char *filename) {
  FILE *in = fopen(filename, "rb");
  if (in == NULL) {
    fprintf(stderr, "error: could not open file %s to compress\n", filename);
    exit(EXIT_FAILURE);
  }

  char *out_name = malloc(strlen(filename) + 5);
  if (out_name == NULL) {
    fprintf(stderr, "error: could not create output file for %s\n", filename);
    exit(EXIT_FAILURE);
  }
  sprintf(out_name, "%s.rle", filename);
  FILE *out = fopen(out_name, "wb");
  if (out == NULL) {
    fprintf(stderr, "error: could not create output file for %s\n", filename);
    free(out_name);
    fclose(in);
    exit(EXIT_FAILURE);
  }

  uint8_t byte_pair[PAIR];
  char curr;
  if ((curr = getc(in)) == EOF) {
    fclose(in);
    fclose(out);
    remove(out_name);
    free(out_name);
    return;
  }

  byte_pair[0] = 1;
  byte_pair[1] = (uint8_t)curr;

  while (1) {
    curr = getc(in);
    if (curr == EOF) {
      putc(byte_pair[0], out);
      putc(byte_pair[1], out);
      break;
    }

    if ((uint8_t)curr == byte_pair[1]) {
      byte_pair[0]++;
    } else {
      putc(byte_pair[0], out);
      putc(byte_pair[1], out);
      byte_pair[0] = 1;
      byte_pair[1] = (uint8_t)curr;
    }
  }

  fclose(in);
  fclose(out);
  free(out_name);
}

void decompress_file(char *filename) {
  int in_fname_len = strlen(filename);
  if (strcmp(filename + (in_fname_len - 4), ".rle") != 0) {
    fprintf(stderr, "error: incorrect file format: only %s files are allowed\n",
            ".rle");
    exit(EXIT_FAILURE);
  }

  FILE *in = fopen(filename, "rb");
  if (in == NULL) {
    fprintf(stderr, "error: could not open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  char *out_filename = malloc(sizeof(char) * (in_fname_len - 3));
  if (out_filename == NULL) {
    fprintf(stderr, "error: could not create output file: not enough memory\n");
    fclose(in);
    exit(EXIT_FAILURE);
  }

  int out_fname_len = in_fname_len - 4;
  strncpy(out_filename, filename, out_fname_len);
  FILE *out = fopen(out_filename, "wb");
  if (out == NULL) {
    fprintf(stderr, "error: could not create output file\n");
    fclose(in);
    free(out_filename);
    exit(EXIT_FAILURE);
  }

  char count;
  char byte;
  while ((count = getc(in)) != EOF) {
    byte = getc(in);
    for (int i = 0; i < count; i++) {
      putc(byte, out);
    }
  }

  if (ferror(in)) {
    fprintf(stderr, "error: failed to decompress: partial read is occurred\n");
    fclose(in);
    fclose(out);
    remove(out_filename);
    free(out_filename);
    exit(EXIT_FAILURE);
  }

  fclose(in);
  fclose(out);
  free(out_filename);
}
