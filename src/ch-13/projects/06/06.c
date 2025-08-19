// Improve the `planet.c` program of Section 13.7 by having it ignore case when
// comparing command-line arguments with strings in the `planets` array.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

void into_lower(char *dest, const char *src);

int main(int argc, char *argv[]) {
  char *planets[] = {"mercury", "venus",  "earth",   "mars", "jupiter",
                     "saturn",  "uranus", "neptune", "pluto"};

  int i, j;

  for (i = 1; i < argc; i++) {
    // NOTE: My solution here allocates a new buffer
    // to store the arg as lowercase, and then does
    // the comparison.
    //
    // K.N King's solution does the comparison
    // without allocating anything, so it's a lot
    // better.
    char buf[sizeof(argv[i])];
    into_lower(buf, argv[i]);

    for (j = 0; j < NUM_PLANETS; j++) {
      if (strcmp(buf, planets[j]) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }

    if (j == NUM_PLANETS) {
      printf("%s is not a planet\n", argv[i]);
    }
  }

  return 0;
}

void into_lower(char *dest, const char *src) {
  while (*src) {
    *dest++ = tolower(*src++);
  }

  *dest = '\0';
}
