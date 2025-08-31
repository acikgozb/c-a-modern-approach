#include "stackADT.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

struct stack_type {
  Item contents[STACK_SIZE];
  int top;
};

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    return s;
  }

  s->top = 0;
  return s;
}

bool is_empty(const Stack s) { return s->top == 0; }

bool is_full(const Stack s) { return s->top == STACK_SIZE; }

void stack_underflow(void) { printf("stack underflow\n"); }

void stack_overflow(void) {
  printf("stack overflow\n");
  exit(EXIT_FAILURE);
}

Item pop(Stack s) {
  if (is_empty(s)) {
    stack_underflow();
    return -1;
  }

  return s->contents[--s->top];
}

void push(Stack s, Item ch) {
  if (is_full(s)) {
    stack_overflow();
    return;
  }

  s->contents[s->top++] = ch;
}

void destroy(Stack s) { free(s); }
