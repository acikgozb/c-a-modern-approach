// Modify Project 6 from Chapter 10 so that it includes the following function:
//
// int evaluate_RPN_expression(const char *expression);
//
// The function returns the value of the RPN expression pointed to by
// `expression`.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define RPN_SIZE 10

int stack[STACK_SIZE];
int top = 0;

void clear(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(int ch);
char pop(void);
int evaluate_RPN_expression(const char *expression);

int main(void) {
  while (1) {
    bool exit = false;
    for (int i = 0; i < STACK_SIZE; i++) {
      stack[i] = 0;
    }

    char expression[RPN_SIZE], *p = expression;

    printf("enter an RPN expression: ");
    char ch;
    while (p < expression + RPN_SIZE) {
      ch = getchar();
      if (ch == '\n') {
        break;
      }

      if (isspace(ch)) {
        continue;
      }

      if (isalpha(ch)) {
        exit = true;
        break;
      }

      *p++ = ch;
    }
    *p = '\0';

    if (exit) {
      break;
    }

    fprintf(stdout, "value of expression: %d\n",
            evaluate_RPN_expression(expression));
  }

  return 0;
}

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

int evaluate_RPN_expression(const char *expression) {
  int result = 0;
  while (*expression) {
    char ch = *expression++;
    if (isdigit(ch)) {
      push(ch - '0');
      continue;
    }

    if (ch == '=') {
      result = pop();
      break;
    }

    if (ch == '+') {
      push(pop() + pop());
      continue;
    }

    if (ch == '*') {
      push(pop() * pop());
      continue;
    }

    if (ch == '-') {
      int op1 = pop();
      int op2 = pop();

      push(op2 - op1);
      continue;
    }

    if (ch == '/') {
      int op1 = pop();
      int op2 = pop();

      push(op2 / op1);
      continue;
    }
  }

  return result;
}
