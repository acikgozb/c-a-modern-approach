// (a) Write a program that counts the number of characters in a text file.
//
// (b) Write a program that counts the number of words in a text file. A "word"
// is any sequence of non-white-space characters.
//
// (c) Write a program that
// counts the number of lines in a text file.

#define _POSIX_C_SOURCE 1

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void count_chars(char *filename);
void count_words(char *filename);
void count_lines(char *filename);

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: 04 <a | b | c> <filename>");
    exit(EXIT_FAILURE);
  }

  char operation = *argv[1];
  switch (operation) {
  case 'a':
    count_chars(argv[2]);
    break;
  case 'b':
    count_words(argv[2]);
    break;
  case 'c':
    count_lines(argv[2]);
    break;
  default:
    fprintf(stderr, "usage: 04 <a | b | c> <filename>");
    exit(EXIT_FAILURE);
  }

  return 0;
}

// NOTE: We know that in C, each character
// occupies a single byte.
// Therefore, in order to determine the number
// of characters, we can simply check the file's size.
//
// This solution satisfies the project because:
//
// - The requirements do not specify which type of characters to count.
// So we can assume that all characters can be counted.
// - The requirements do not specify the encoding of characters.
// So we can safely assume each character takes a single byte, aka. `char` type.
void count_chars(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr,
            "error: failed to count chars in file: could not open file %s",
            filename);
    exit(EXIT_FAILURE);
  }

  struct stat fs;
  fstat(fileno(fp), &fs);

  fclose(fp);
  printf("the number of chars in %s is %ld\n", filename, fs.st_size);
}

// NOTE: A "word" is a sequence of non-white-space characters.
// Therefore we can count the words by counting the white-space chars in a file.
void count_words(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr,
            "error: failed to count words in file: could not open file %s",
            filename);
    exit(EXIT_FAILURE);
  }

  int count = 0;
  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    if (!isspace(ch)) {
      continue;
    }

    count++;

    while (isspace((ch = fgetc(fp))))
      ;
    ungetc(ch, fp);
  }

  fclose(fp);
  printf("the number of words in file %s is %d\n", filename, count);
}

// NOTE: This is similar to `count_words`, only different
// in the fact that it checks the line feed `\n` character
// to determine the lines.
// Carriage return `\r` is not taken into account.
void count_lines(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr,
            "error: failed to count words in file: could not open file %s",
            filename);
    exit(EXIT_FAILURE);
  }

  int count = 0;
  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      count++;
    }
  }

  fclose(fp);
  printf("the number of lines in file %s is %d\n", filename, count);
}
