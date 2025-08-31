// This solution contains both Project 3 and 4 solutions:
//
// Project 3: Modify the `stackADT3.c` file of Section 19.4 by adding an `int`
// member named `len` to the `stack_type` structure. This member will keep track
// of how many items are currently stored in the stack. Add a new function named
// `length` that has a `Stack` parameter and returns the value of the `len`
// member. Modify `stackclient.c` so that it calls the `length` function (and
// displays the value that it returns) after each operation that modifies a
// stack.
//
// Project 4: Modify the `stackADT.h` and `stackADT3.c` files of Section 19.4 so
// that a stack stores values of type `void *`, as described in Section 19.5;
// the `Item` type will no longer be used.
// Modify `stackclient.c` so that it stores pointers to strings in the `s1` and
// `s2` stacks.

#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

void terminate(char *msg, Stack s1, Stack s2);

// SOLUTION(03-06): Print lengths of stacks after each operation that modifies
// them.
int main(void) {
  Stack s1 = NULL, s2 = NULL, p = NULL;

  // SOLTUION(04-03): Store pointers to strings in `s1` and `s2` stacks.
  char *n;

  s1 = create();
  if (s1 == NULL) {
    terminate("fatal: cannot create s1: out of memory", s1, s2);
  }
  s2 = create();
  if (s2 == NULL) {
    terminate("fatal: cannot create s2: out of memory", s1, s2);
  }

  printf("current lengths of stacks: s1: %d, s2: %d\n", length(s1), length(s2));

  // SOLTUION(04-03): Static strings are used to push into s1 and s2 stacks.
  p = push(s1, "1");
  if (p == NULL) {
    terminate("fatal: cannot push onto stack: out of memory", s1, s2);
  }
  s1 = p;
  p = push(s1, "2");
  if (p == NULL) {
    terminate("fatal: cannot push onto stack: out of memory", s1, s2);
  }
  printf("length of s1: %d\n", length(s1));

  // SOLTUION(04-03): The `void *` type is converted to char * during the
  // assignment. No cast is needed here.
  n = pop(s1);
  if (n == NULL) {
    terminate("fatal: cannot pop from s1: stack is empty", s1, s2);
  }
  printf("popped %s from s1\n", n);
  printf("length of s1: %d\n", length(s1));
  p = push(s2, n);
  if (p == NULL) {
    terminate("fatal: cannot push onto s2: out of memory", s1, s2);
  }

  printf("length of s2: %d\n", length(s2));

  // SOLTUION(04-03): The `void *` type is converted to char * during the
  // assignment. No cast is needed here.
  n = pop(s1);
  if (p == NULL) {
    terminate("fatal: cannot push onto s2: out of memory", s1, s2);
  }

  printf("popped %s from s1\n", n);
  printf("length of s1: %d\n", length(s1));
  push(s2, n);
  if (p == NULL) {
    terminate("fatal: cannot push onto s2: out of memory", s1, s2);
  }

  printf("length of s2: %d\n", length(s2));

  destroy(s1);

  while (!is_empty(s2)) {
    // SOLTUION(04-03): The `void *` type needs to be converted back to string
    // to be compatible with the format specification. An explicit cast is
    // needed.
    printf("popped %s from s2\n", (char *)pop(s2));
    printf("length of s2: %d\n", length(s2));
  }

  push(s2, "3");
  if (p == NULL) {
    terminate("fatal: cannot push onto s2: out of memory", s1, s2);
  }

  printf("length of s2: %d\n", length(s2));
  make_empty(s2);
  printf("length of s2: %d\n", length(s2));

  if (is_empty(s2)) {
    printf("s2 is empty\n");
  } else {
    printf("s2 is not empty\n");
  }

  printf("length of s2: %d\n", length(s2));
  destroy(s2);

  return 0;
}

void terminate(char *msg, Stack s1, Stack s2) {
  fprintf(stderr, "%s\n", msg);
  if (s1 != NULL) {
    destroy(s1);
  }
  if (s2 != NULL) {
    destroy(s2);
  }
  exit(EXIT_FAILURE);
}
