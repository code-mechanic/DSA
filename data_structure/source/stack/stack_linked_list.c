#include "stack_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void stack_linked_list_init(StackLinkedList *stack)
{
    stack->top = NULL; // Initialize the top pointer to NULL indicating an empty stack
    stack->size = 0; // Initialize the size of the stack to 0
}

void stack_linked_list_push(StackLinkedList *stack, int value)
{
    /* Input argument check */
    if (!stack) {
        fprintf(stderr, "Stack is NULL: Cannot push onto a NULL stack.\n");
        return; // Handle NULL stack pointer
    }

    if (stack_linked_list_is_full(stack)) {
        fprintf(stderr, "Stack overflow: Cannot push %d onto full stack.\n", value);
        return; // Handle stack overflow
    }
    
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode)); // Allocate memory for the new node
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed for new stack node.\n");
        return; // Handle memory allocation failure
    }
    
    new_node->value = value; // Set the value of the new node
    new_node->next = stack->top; // Link the new node to the previous top node
    stack->top = new_node; // Update the top pointer to the new node
    stack->size++; // Increment the size of the stack
}

int stack_linked_list_pop(StackLinkedList *stack)
{
    /* Input argument check */
    if (!stack) {
        fprintf(stderr, "Stack is NULL: Cannot pop from a NULL stack.\n");
        return -1; // Handle NULL stack pointer
    }

    if (stack_linked_list_is_empty(stack)) {
        fprintf(stderr, "Stack underflow: Cannot pop from an empty stack.\n");
        return -1; // Handle stack underflow
    }

    StackNode *top_node = stack->top; // Get the current top node
    int value = top_node->value; // Store the value to return
    stack->top = top_node->next; // Update the top pointer to the next node
    free(top_node); // Free the memory of the popped node
    stack->size--; // Decrement the size of the stack

    return value; // Return the popped value
}

int stack_linked_list_peek(StackLinkedList *stack)
{
    /* Input argument check */
    if (!stack) {
        fprintf(stderr, "Stack is NULL: Cannot peek on a NULL stack.\n");
        return -1; // Handle NULL stack pointer
    }

    if (stack_linked_list_is_empty(stack)) {
        fprintf(stderr, "Stack is empty: Cannot peek.\n");
        return -1; // Handle peek on empty stack
    }

    return stack->top->value; // Return the value of the top node without modifying the stack
}

int stack_linked_list_is_empty(StackLinkedList *stack)
{
    /* Input argument check */
    if (!stack) {
        fprintf(stderr, "Stack is NULL: Cannot check if a NULL stack is empty.\n");
        return 1; // Consider NULL stack as empty
    }

    return stack->size == 0; // Check if the size of the stack is 0
}

int stack_linked_list_is_full(StackLinkedList *stack)
{
    /* Input argument check */
    if (!stack) {
        fprintf(stderr, "Stack is NULL: Cannot check if a NULL stack is full.\n");
        return 0; // Consider NULL stack as not full
    }

    return stack->size >= STACK_LINKED_LIST_MAX_SIZE; // Check if the size of the stack exceeds the maximum size
}

void stack_linked_list_clear(StackLinkedList *stack)
{
    while (!stack_linked_list_is_empty(stack)) {
        stack_linked_list_pop(stack); // Pop elements from the stack until it is empty
    }
}
