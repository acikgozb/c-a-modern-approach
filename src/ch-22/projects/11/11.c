// Write a program that reads a date from command line and displays it in the
// following form: September 13, 2010
//
// Allow the user to enter the date as either `9-13-2010` or `9/13/2010`; you
// may assume that there are no spaces in the date. Print an error message if
// the date doesn't have one of the specified forms.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: date <mm-dd-yyyy | mm/dd/yyyy>");
    exit(EXIT_FAILURE);
  }

  int month = 0, day = 0, year = 0;
  if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) != 3 &&
      sscanf(argv[1], "%d/%d/%d", &month, &day, &year) != 3) {
    fprintf(stderr, "error: invalid date format");
    exit(EXIT_FAILURE);
  }

  char *months[] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

  printf("%s %d, %d", months[month - 1], day, year);
  return 0;
}
