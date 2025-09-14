// Prints a countdown.

#include <stdio.h>

void print_count(int i) { printf("T minus %d and counting\n", i); }

int main(void) {
  int i;
  for (i = 10; i > 0; i--) {
    print_count(i);
  }
  return 0;
}
