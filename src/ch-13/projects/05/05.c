// Write a program named `sum.c` that adds up its command-line arguments, which
// are assumed to be integers.
//
// Example:
// ```bash
// $ > sum 8 24 62
// # Total: 94
// ```

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int sum = 0;

  for (int i = 1; i < argc; i++) {
    sum += strtol(*(argv + i), NULL, 0);
  }

  printf("total: %d", sum);
  return 0;
}
