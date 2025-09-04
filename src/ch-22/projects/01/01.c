// Extend the `canopen.c` program of Section 22.2 so that the user may put any
// number of files names on the command line:
//
// e.g: canopen foo bar baz ...
//
// The program should print a separate `can be opened` or `can't be opened`
// message for each file. Have the program terminate with status `EXIT_FAILURE`
// if one or more of the files can't be opened.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc == 1) {
    printf("usage: canopen <filename...>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  bool failure = false;
  while (argc-- > 1) {
    if ((fp = fopen(argv[argc], "r")) == NULL) {
      printf("%s can't be opened\n", argv[argc]);
    } else {
      printf("%s can be opened\n", argv[argc]);
      fclose(fp);
      failure = true;
    }
  }

  return failure ? EXIT_FAILURE : EXIT_SUCCESS;
}
