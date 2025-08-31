#ifndef STACK_ADT_H
#define STACK_ADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;

typedef int Item;

Stack create(int size);
void destroy(Stack s);
void clear(Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
void push(Stack s, Item ch);
Item pop(Stack s);
#endif
