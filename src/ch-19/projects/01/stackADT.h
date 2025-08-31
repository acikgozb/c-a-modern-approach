#ifndef STACK_ADT_H
#define STACK_ADT_H

#include <stdbool.h>

// The incomplete type.
typedef struct stack_type *Stack;

typedef char Item;

bool is_empty(const Stack s);
bool is_full(const Stack s);
Item pop(Stack s);
void push(Stack s, Item ch);
Stack create(void);
void destroy(Stack s);
#endif
