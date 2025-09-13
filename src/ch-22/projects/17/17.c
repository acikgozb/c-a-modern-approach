// Write a program that reads a series of phone numbers from a file and displays
// them in a standard format. Each line of the file will contain a single phone
// number, but the numbers may be in a variety of formats. You may assume that
// each line contains 10 digits, possibly mixed with other characters (which
// should be ignored). Have the program obtain the file name from the command
// line.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define FIRST_DIGIT_GROUP_SIZE 4
#define SECOND_DIGIT_GROUP_SIZE 4
#define THIRD_DIGIT_GROUP_SIZE 5

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: phone <list-file>");
    exit(EXIT_FAILURE);
  }

  FILE *src = fopen(argv[1], "rb");
  if (src == NULL) {
    fprintf(stderr, "error: could not read the list file\n");
    exit(EXIT_FAILURE);
  }

  // NOTE: Since there are no restrictions given
  // from the requirements about the non digit chars,
  // we need to write a solution based on the digits themselves.
  // e.g: a phone number in the list may contain subsequent
  // spaces, so we cannot know the size of a line in the list
  // and allocate a buffer for it in advance.
  char dg1[FIRST_DIGIT_GROUP_SIZE] = {'\0'},
       dg2[SECOND_DIGIT_GROUP_SIZE] = {'\0'},
       dg3[THIRD_DIGIT_GROUP_SIZE] = {'\0'};
  int ch;
  while ((ch = getc(src)) != EOF) {
    if (ch == '\n') {
      printf("(%s) %s-%s\n", dg1, dg2, dg3);
      dg1[0] = '\0';
      dg2[0] = '\0';
      dg3[0] = '\0';
      continue;
    }

    if (!isdigit(ch)) {
      continue;
    }

    // NOTE: For the first empty buf we encounter,
    // read a set of chars of size `group_size - 1 (curr ch)` from the stream.
    // NOTE: We assume that the format of a phone number is meaningful by
    // itself. For instance, it is OK to not handle a number like "(21)5 6 8
    // 6-177 6".
    if (dg1[0] == '\0') {
      dg1[0] = ch;
      fgets(&dg1[1], FIRST_DIGIT_GROUP_SIZE - 1, src);
    } else if (dg2[0] == '\0') {
      dg2[0] = ch;
      fgets(&dg2[1], SECOND_DIGIT_GROUP_SIZE - 1, src);
    } else if (dg3[0] == '\0') {
      dg3[0] = ch;
      fgets(&dg3[1], THIRD_DIGIT_GROUP_SIZE - 1, src);
    }
  }

  fclose(src);
  return 0;
}
