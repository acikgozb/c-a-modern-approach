#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define STACK_SIZE 10

extern int stack[];
extern int top;

void clear(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(int ch);
char pop(void);
#endif
