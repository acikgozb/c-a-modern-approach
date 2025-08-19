// Modify Project 11 from Chapter 7 so that it includes the following function.
//
// void reverse_name(char *name);

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NAME_LEN 42 // space + null

void reverse_name(char *name);

int main(void) {
  printf("enter a first and last name: ");

  char name[NAME_LEN];
  int i;
  for (i = 0; i < NAME_LEN; i++) {
    char *p = name + i;
    int ch = getchar();
    if (ch == '\n') {
      *p = '\0';
      break;
    }

    *p = ch;
  }

  reverse_name(name);
  printf("%s", name);

  return 0;
}

void reverse_name(char *name) {
  char first_name, *tmp = name;
  while (*tmp == ' ') {
    tmp++;
  }
  first_name = *tmp;

  char last_name[NAME_LEN - 3], *start, *end;

  // Find the last name by starting from
  // first non-space char to first space char.
  int len = strlen(name);
  end = name + len - 1;
  while (*end == ' ') {
    end--;
  }

  start = end;
  while (*start != ' ') {
    start--;
  }

  int i = 0;
  while (start <= end) {
    last_name[i++] = *start++;
  }
  last_name[i] = '\0';

  sprintf(name, "%c.,%s.", first_name, last_name);
}
