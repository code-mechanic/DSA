#include "stack_array.h"
#include <stdio.h>

void stack_array_init(StackArray *stack)
{
    stack->top = -1; // Initialize the top index to -1 indicating an empty stack
    stack->size = 0; // Initialize the size of the stack to 0
    for (uint32_t i = 0; i < STACK_ARRAY_MAX_SIZE; i++) {
        stack->data[i] = 0; // Optionally initialize the data array to zero
    }
}

void stack_array_push(StackArray *stack, int value)
{
    if (stack_array_is_full(stack)) {
        fprintf(stderr, "Stack overflow: Cannot push %d onto full stack.\n", value);
        return; // Handle stack overflow
    }
    stack->data[++stack->top] = value; // Increment top and push the value onto the stack
    stack->size++; // Increment the size of the stack
}

int stack_array_pop(StackArray *stack)
{
    if (stack_array_is_empty(stack)) {
        fprintf(stderr, "Stack underflow: Cannot pop from an empty stack.\n");
        return -1; // Handle stack underflow
    }
    return stack->data[stack->top--]; // Return the top value and decrement the top index
    stack->size--; // Decrement the size of the stack
}

int stack_array_peek(const StackArray *stack)
{
    if (stack_array_is_empty(stack)) {
        fprintf(stderr, "Stack is empty: Cannot peek.\n");
        return -1; // Handle peek on empty stack
    }
    return stack->data[stack->top]; // Return the top value without modifying the stack
}

int stack_array_is_empty(const StackArray *stack)
{
    return stack->top == -1; // Check if the stack is empty
}

int stack_array_is_full(const StackArray *stack)
{
    return stack->top == STACK_ARRAY_MAX_SIZE - 1; // Check if the stack is full
}

void stack_array_clear(StackArray *stack)
{
    stack->top = -1; // Reset the top index to -1 to clear the stack
    stack->size = 0; // Reset the size of the stack to 0
    for (uint32_t i = 0; i < STACK_ARRAY_MAX_SIZE; i++) {
        stack->data[i] = 0; // Optionally reset the data array to zero
    }
}