// Write a basic RPN (Reverse Polish Notation) evaluator.
//
// Examples:
// 1 2 3 + * = -> the expression is equal to 7.
// 5 8 * 4 9 - / = -> the expression is equal to -8.
// Any non operand or operator character -> terminate the program.
//
// Modify Project 6 from Chapter 10 so that it uses the stack ADT described in
// Section 19.4.
// You may use any of the implementations of the ADT described in that section.

#include "stackADT.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RPN_SIZE 20

int main(void) {
  while (1) {
    Stack s = create(RPN_SIZE);
    if (s == NULL) {
      fprintf(stderr, "fatal: cannot init RPN calculator: out of memory");
      exit(EXIT_FAILURE);
    }

    printf("enter an RPN expression: ");

    char ch;
    while (1) {
      scanf(" %c", &ch);
      if (ch == '\n') {
        break;
      }

      if (isdigit(ch)) {
        push(s, ch - '0');
        continue;
      }

      if (ch == '=') {
        int res = pop(s);
        printf("value of expression: %d\n", res);
        break;
      }

      if (ch == '+') {
        push(s, pop(s) + pop(s));
        continue;
      }

      if (ch == '*') {
        push(s, pop(s) * pop(s));
        continue;
      }

      if (ch == '-') {
        int op1 = pop(s);
        int op2 = pop(s);

        push(s, op2 - op1);
        continue;
      }

      if (ch == '/') {
        int op1 = pop(s);
        int op2 = pop(s);

        push(s, op2 / op1);
        continue;
      }

      return 0;
    }

    destroy(s);
  }

  return 0;
}
