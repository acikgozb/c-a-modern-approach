// Implementing `stackADT.h` using a linked-list.

#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
};

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void) {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    terminate("error in create: stack could not be created");
  }

  s->top = NULL;
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

void push(Stack s, Item i) {
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    terminate("error in push: stack is full");
  }

  n->data = i;
  n->next = s->top;
  s->top = n;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    terminate("error in pop: stack is empty");
  }

  struct node *old_top = s->top;
  Item i = old_top->data;

  s->top = old_top->next;
  free(old_top);

  return i;
}
