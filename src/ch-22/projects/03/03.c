// Write a program named "fcat" that concatenates any number of files by writing
// them to standard output, one after the other, with no break between files.
// For example, the following command will display the files `f1.c`, `f2.c`,
// `f3.c` on the screen:
//
// fcat f1.c f2.c f3.c
//
// fcat should issue an error message if any file can't be opened.

// NOTE: Defining this macro is enough to use the `fileno` function below.
#define _POSIX_C_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "usage: fcat <filename...>");
    exit(EXIT_FAILURE);
  }

  FILE *fp = NULL;
  struct stat fs;
  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "error: could not open file %s", argv[i]);
      continue;
    }

    fstat(fileno(fp), &fs);
    int fsize = fs.st_size;

    char *buf = malloc(fsize);
    if (buf == NULL) {
      fprintf(stderr, "error: could not read file %s: not enough memory",
              argv[i]);
      fclose(fp);
      continue;
    }

    // NOTE: `fgetc` and `putc` could be used for this one as well, but since
    // a similar solution is done for Project 2, `fread` and `fwrite` are
    // used for this one instead.
    int n = fread(buf, sizeof(buf[0]), fsize, fp);
    if (n != fsize) {
      fprintf(stderr, "warn: file %s is read partially: write is skipped",
              argv[i]);
    } else {
      fwrite(buf, sizeof(buf[0]), n, stdout);
    }

    free(buf);
    fclose(fp);
  }

  return 0;
}
