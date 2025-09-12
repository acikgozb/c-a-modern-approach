// Modify Project 8 from Chapter 5 so that the program obtains departure and
// arrival times from a file named `flights.dat`. Each line of the file will
// contain a departure time followed by an arrival time, with one or more spaces
// separating the two. Times will be expressed using the 24-hour clock.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEP_SIZE 13

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: deps <flights-file>");
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "error: cannot open flights file\n");
    exit(EXIT_FAILURE);
  }

  int user_hour, user_min, user_total;
  printf("enter a 24-hour time: ");
  scanf("%2d:%2d", &user_hour, &user_min);
  user_total = user_hour * 60 + user_min;

  char flight[DEP_SIZE];

  fgets(flight, DEP_SIZE, fp);
  int dep_hour, dep_min;
  sscanf(flight, "%2d:%2d", &dep_hour, &dep_min);
  int total = dep_hour * 60 + dep_min;

  char next_flight[DEP_SIZE];
  while (fgets(next_flight, DEP_SIZE, fp) != NULL) {
    int next_dep_hour, next_dep_min;
    sscanf(next_flight, "%2d:%2d", &next_dep_hour, &next_dep_min);
    int next_total = next_dep_hour * 60 + next_dep_min;

    if (user_total <= total + (next_total - total) / 2) {
      break;
    }

    strcpy(flight, next_flight);
    total = next_total;
    dep_hour = next_dep_hour;
    dep_min = next_dep_min;
  }

  printf("closest departure time is: %.2d:%.2d, arriving at %s\n", dep_hour,
         dep_min, flight + (strlen(flight) - 6));

  return 0;
}
