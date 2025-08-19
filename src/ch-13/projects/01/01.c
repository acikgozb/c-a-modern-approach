// Write a program that finds the "smallest" and "largest"
// in a series of words.
// Assume that no word is more than 20 letters long.
// The program stops when user enters a four-letter word.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define WRD_LEN 21  // wrd + null char
#define BREAK_LEN 5 // wrd + newline

int main(void) {
  char smallest[WRD_LEN] = "";
  char largest[WRD_LEN] = "";
  char wrd[WRD_LEN];

  printf("enter word: ");
  fgets(wrd, WRD_LEN, stdin);
  strcpy(smallest, wrd);
  strcpy(largest, wrd);

  while (strlen(wrd) != BREAK_LEN) {
    printf("enter word: ");
    fgets(wrd, WRD_LEN, stdin);

    if (strcmp(smallest, wrd) > 0) {
      strcpy(smallest, wrd);

    } else if (strcmp(largest, wrd) < 0) {
      strcpy(largest, wrd);
    }
  }

  printf("\n");
  printf("smallest word: %s", smallest);
  printf("largest word: %s", largest);

  return 0;
}
