// The implentation of `stack.h` by using a linked list.

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// NOTE:
// Similar to `stack1.c`, `top` and `terminate` are
// implementation details that are kept hidden from
// other parts of the program by using `static`.
static struct node *top = NULL;

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(void) {
  while (!is_empty()) {
    pop();
  }
}

bool is_empty() { return top == NULL; }

bool is_full(void) { return false; }

void push(int i) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    terminate("error in push: stack is full");
  }

  new_node->data = i;
  new_node->next = top;
  top = new_node;
}

int pop(void) {
  struct node *old_top;
  int i;

  if (is_empty()) {
    terminate("error in pop: stack is empty");
  }

  old_top = top;
  i = top->data;
  top = top->next;
  free(old_top);

  return i;
}
