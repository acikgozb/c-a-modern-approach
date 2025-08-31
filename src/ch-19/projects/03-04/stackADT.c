// Implementing `stackADT.h` using a linked-list.

#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  // SOLUTION(04-02): Replace `Item` type with `void *` in stack ADT
  // implementation.
  // old field: Item data;
  void *data;
  struct node *next;
};

struct stack_type {
  struct node *top;
  // SOLUTION(03-01): Add the length field to the main struct.
  int len;
};

// SOLUTION(03-04): Add the definition of `length`.
int length(const Stack s) { return s->len; }

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    return NULL;
  }

  s->top = NULL;
  // SOLUTION(03-02): Initialize the length when the stack struct
  // is created.
  s->len = 0;
  return s;
}

void destroy(Stack s) {
  make_empty(s);
  free(s);
}

void make_empty(Stack s) {
  while (!is_empty(s)) {
    pop(s);
  }
}

bool is_empty(Stack s) { return s->top == NULL; }

bool is_full(Stack s) { return false; }

// SOLUTION(04-02): Replace `Item` type with `void *` in stack ADT
// implementation.
Stack push(Stack s, void *i) {
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    return NULL;
  }

  n->data = i;
  n->next = s->top;
  s->top = n;

  // SOLUTION(03-05): Update length accordingly
  // when the nodes of a stack gets changed.
  s->len++;

  return s;
}

// SOLUTION(04-02): Replace `Item` type with `void *` in stack ADT
// implementation.
void *pop(Stack s) {
  if (is_empty(s)) {
    return NULL;
  }

  struct node *old_top = s->top;
  void *i = old_top->data;

  s->top = old_top->next;
  free(old_top);

  // SOLUTION(03-05): Update length accordingly
  // when the nodes of a stack gets changed.
  s->len--;

  return i;
}
