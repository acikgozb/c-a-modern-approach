#include "stackADT.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct stack_type {
  Item *contents;
  int top;
  int size;
};

// NOTE: The size of the underlying array is retrieved
// from the client, making our stack impl use a dynamic-sized
// array.
Stack create(int size) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    return NULL;
  }

  s->contents = malloc(sizeof(Item) * size);
  if (s->contents == NULL) {
    return NULL;
  }

  s->top = 0;
  s->size = size;

  return s;
}

void clear(Stack s) { s->top = 0; }

bool is_empty(const Stack s) { return s->top == 0; }

bool is_full(const Stack s) { return s->top == s->size; }

// TODO: These two functions below does not allow clients
// to handle errors gracefully for push and pop operations.
// If the error handling is explained in detail in next chapters
// of the book, these functions will be changed appropriately later on.
void stack_overflow(void) {
  printf("expression is too complex");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression");
  exit(EXIT_FAILURE);
}

void push(Stack s, int ch) {
  if (is_full(s)) {
    stack_overflow();
  }

  s->contents[s->top++] = ch;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    stack_underflow();
  }

  return s->contents[--s->top];
}

void destroy(Stack s) {
  free(s->contents);
  free(s);
}
