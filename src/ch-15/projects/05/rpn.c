// Modify Project 6 from Chapter 10 so that it has separate `stack.h` and
// `stack.c` files, as described in Section 15.2.

#include "stack.h"
#include <ctype.h>
#include <stdio.h>

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
