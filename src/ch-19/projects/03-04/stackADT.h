#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;
// SOLTUION(04-01): Replace the `Item` type with `void *`.
// typedef int Item;

// SOLUTION(03-03): Add a new function declaration to return
// the current length of a given `Stack`.
int length(const Stack s);
Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
// SOLTUION(04-01): Replace the `Item` type with `void *`.
// As an extra, the return type is changed to
// delegate the error handling to the client.
Stack push(Stack s, void *i);
// SOLTUION(04-01): Replace the `Item` type with `void *`.
void *pop(Stack s);

#endif
