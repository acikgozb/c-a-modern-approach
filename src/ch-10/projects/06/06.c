// Write a basic RPN (Reverse Polish Notation) evaluator.
//
// Examples:
// 1 2 3 + * = -> the expression is equal to 7.
// 5 8 * 4 9 - / = -> the expression is equal to -8.
// Any non operand or operator character -> terminate the program.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = 0;

void clear(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(int ch);
char pop(void);

int main(void) {
  while (1) {
    for (int i = 0; i < STACK_SIZE; i++) {
      stack[i] = 0;
    }

    printf("enter an RPN expression: ");

    char ch;
    while (1) {
      scanf(" %c", &ch);
      if (ch == '\n') {
        break;
      }

      if (isdigit(ch)) {
        push(ch - '0');
        continue;
      }

      if (ch == '=') {
        int res = pop();
        printf("value of expression: %d\n", res);
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

      return 0;
    }
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
