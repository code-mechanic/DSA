#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdint.h>

/* Maximum size of the stack */
#define STACK_ARRAY_MAX_SIZE (10U)

typedef struct {
    /* Index of the top element */
    int data[STACK_ARRAY_MAX_SIZE];
    int32_t top;
    uint32_t size; // Current size of the stack
} StackArray;

void stack_array_init(StackArray *stack);
void stack_array_push(StackArray *stack, int value);
int stack_array_pop(StackArray *stack);
int stack_array_peek(const StackArray *stack);
int stack_array_is_empty(const StackArray *stack);
int stack_array_is_full(const StackArray *stack);
void stack_array_clear(StackArray *stack);

#endif // STACK_ARRAY_H