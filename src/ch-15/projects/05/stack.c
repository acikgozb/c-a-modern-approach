#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int stack[STACK_SIZE];
int top = 0;

void clear(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("expression is too complex");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression");
  exit(EXIT_FAILURE);
}

void push(int ch) {
  if (is_full()) {
    stack_overflow();
  }

  stack[top++] = ch;
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
  }

  return stack[--top];
}
