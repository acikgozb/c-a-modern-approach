// The implentation of `stack.h` by using an array.

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// NOTE:
// Using `static` keyword prevents these
// variables to be used by other modules.
static int contents[STACK_SIZE];
static int top = 0;

// NOTE:
// Similar to `private` functions in other languages,
// using `static` on a function limits its usage to the
// functions defined on the same file only.
// Simply put, this function is not part of the interface.
static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

void push(int i) {
  if (is_full()) {
    terminate("error in push: stack is full");
  }

  contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    terminate("error in pop: stack is empty");
  }

  return contents[--top];
}
