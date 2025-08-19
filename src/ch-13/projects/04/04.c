// Write a program named `reverse.c` that echoes it's command-line arguments in
// reverse order.
//
// Example:
// ```bash
// $ > reverse void and null
// null and void
// ```

#include <stdio.h>

int main(int argc, char *argv[]) {
  do {
    printf("%s ", *(argv + argc - 1));
  } while ((--argc != 1));

  return 0;
}
