// Write a basic program that determines whether the user-provided braces are
// nested properly or not.
//
// Examples:
// ((){}{()}) -> nested properly.
// (() -> not nested properly.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

char stack[STACK_SIZE];
int top = 0;

bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
char pop(void);
void push(char ch);

int main(void) {
  printf("enter parantheses and/or braces: ");

  bool is_nested = true;
  char ch;
  while ((ch = getchar()) != '\n') {
    if (ch == '{' || ch == '(') {
      push(ch);
      continue;
    }

    if (ch == '}') {
      char prev = pop();
      if (prev != '{') {
        is_nested = false;
      }
    }

    if (ch == ')') {
      char prev = pop();
      if (prev != '(') {
        is_nested = false;
      }
    }
  }

  if (!is_empty() || !is_nested) {
    printf("parantheses/braces are not nested properly\n");
  } else {
    printf("parantheses/braces are nested properly\n");
  }

  return 0;
}

bool is_empty(void) { return top == 0; }

bool is_full(void) { return top == STACK_SIZE; }

void stack_underflow(void) { printf("stack underflow\n"); }

void stack_overflow(void) {
  printf("stack overflow\n");
  exit(EXIT_FAILURE);
}

char pop(void) {
  if (is_empty()) {
    stack_underflow();
    return -1;
  }

  return stack[--top];
}

void push(char ch) {
  if (is_full()) {
    stack_overflow();
    return;
  }

  stack[top++] = ch;
}
