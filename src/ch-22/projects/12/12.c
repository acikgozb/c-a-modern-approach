// Modify Project 2 from Chapter 3 so that the program reads a series of items
// from a file and displays the data in columns. Each line of the file will have
// the following form: item, price, mm/dd/yyyy
//
// Have the program obtain the file name from the command line.

#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 40

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: phistory <pfilename>");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "error: could not open purchase file %s", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
  char line[LINE_SIZE];
  int number, p_month, p_day, p_year;
  float price;
  while (fgets(line, LINE_SIZE, fp)) {
    sscanf(line, "%d, %f, %02d/%02d/%4d", &number, &price, &p_month, &p_day,
           &p_year);
    printf("%-8d\t$%8.2f\t%.2d/%.2d/%d\n", number, price, p_day, p_month,
           p_year);
  }

  fclose(fp);
}
