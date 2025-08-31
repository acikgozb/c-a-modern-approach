// Implementing `stackADT.h` using a fixed-length array.

#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// NOTE: The incomplete type in the header file
// is fully defined in here.
struct stack_type {
  Item contents[STACK_SIZE];
  int top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    terminate("error in create: stack could not be created");
  }

  s->top = 0;
  return s;
}

void destroy(Stack s) { free(s); }

void make_empty(Stack s) { s->top = 0; }

bool is_empty(Stack s) { return s->top == 0; }

bool is_full(Stack s) { return s->top == STACK_SIZE; }

void push(Stack s, Item i) {
  if (is_full(s)) {
    terminate("error in push: stack is full");
  }

  s->contents[s->top++] = i;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    terminate("error in pop: stack is empty");
  }

  return s->contents[--s->top];
}
