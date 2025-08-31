// Write a basic program that determines whether the user-provided braces are
// nested properly or not.
//
// Examples:
// ((){}{()}) -> nested properly.
// (() -> not nested properly.
//
// Modify Project 1 from Chapter 10 so that it uses the stack ADT described in
// Section 19.4.
// You may use any of the implementations of the ADT described in that section.

#include "stackADT.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  Stack s = create();
  printf("enter parantheses and/or braces: ");

  bool is_nested = true;
  char ch;
  while ((ch = getchar()) != '\n') {
    if (ch == '{' || ch == '(') {
      push(s, ch);
      continue;
    }

    if (ch == '}') {
      char prev = pop(s);
      if (prev != '{') {
        is_nested = false;
      }
    }

    if (ch == ')') {
      char prev = pop(s);
      if (prev != '(') {
        is_nested = false;
      }
    }
  }

  if (!is_empty(s) || !is_nested) {
    printf("parantheses/braces are not nested properly\n");
  } else {
    printf("parantheses/braces are nested properly\n");
  }

  destroy(s);
  return 0;
}
