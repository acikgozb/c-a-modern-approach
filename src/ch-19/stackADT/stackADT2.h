#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;
typedef int Item;

// NOTE:
// Now that we want to use a dynamically
// allocated array for our stack, we need
// the initial size from the clients.
// By doing so, we avoid allocating too much
// or less, we just allocate the exact amount
// that clients want.
Stack create(int size);

void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
