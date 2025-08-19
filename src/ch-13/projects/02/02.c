// Improve the `remind.c` program in the following ways:
//
// (a) Have the program print an error message and ignore a reminder if the
// corresponding day is negative or larger than 31.
//
// (b) Allow the user to enter a day, a 24-hour time, and a reminder. The
// printed reminder list should be sorted first by day, then by time. (The
// original program allows the user to enter a time, but it's treater as part of
// the reminder).
//
// (c) Have the program print a one-year reminder list. Require the user to
// enter days in the form `month/day`.

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MONTHS_LEN 12

#define TIMESTAMP_SIZE 12 // "MM/dd hh:mm\0"
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void) {
  char reminders[MAX_REMIND][MSG_LEN + TIMESTAMP_SIZE];
  int i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- no space left --\n");
      break;
    }

    printf(
        "enter month/day, a 24-hour time, and the reminder (MM/dd hh:mm r): ");
    int month, day;
    scanf("%2d/%2d", &month, &day);
    if (day == 0) {
      break;
    }

    if (day < 0) {
      fprintf(stderr, "invalid day %d: reminder is ignored.", day);
      continue;
    }

    int hour, minute;
    scanf("%2d:%2d", &hour, &minute);

    char msg_str[MSG_LEN + 1];
    read_line(msg_str, MSG_LEN);

    char timestamp[TIMESTAMP_SIZE];
    sprintf(timestamp, "%.2d/%.2d %.2d:%.2d", month, day, hour, minute);
    for (i = 0; i < num_remind; i++) {
      if (strncmp(timestamp, reminders[i], TIMESTAMP_SIZE) < 0) {
        break;
      }
    }
    for (j = num_remind; j > i; j--) {
      strcpy(reminders[j], reminders[j - 1]);
    }

    strcpy(reminders[i], timestamp);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\n MM/dd hh:mm reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf(" %s\n", reminders[i]);
  }

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n') {
    if (i < n) {
      str[i++] = ch;
    }
  }

  str[i] = '\0';
  return i;
}
