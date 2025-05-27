/*
In this algorithm below, we make sure that one queue is always empty.
Stack push operation always use non-empty queue to add new elements.
Stack pop operation always empty the non-empty queue except the last element.
*/

#include "queue_circular_sll.h"
#include <stdio.h>

typedef struct Stack {
    QueueCircularSLL queue1;
    QueueCircularSLL queue2;
} Stack;

static void stack_push(Stack *stack, int value)
{
    // Input argument validation
    if (stack == NULL) {
        fprintf(stderr, "Error: stack is NULL\n");
        return;
    }

    // Push operation always uses the non-empty queue
    if (queue_circular_sll_is_empty(&stack->queue1)) {
        // check for stack overflow
        if (queue_circular_sll_is_full(&stack->queue2)) {
            fprintf(stderr, "Error: Stack overflow\n");
            return; // Indicating an error
        }
        queue_circular_sll_enqueue(&stack->queue2, value);
    } else {
        // check for stack overflow
        if (queue_circular_sll_is_full(&stack->queue1)) {
            fprintf(stderr, "Error: Stack overflow\n");
            return; // Indicating an error
        }
        queue_circular_sll_enqueue(&stack->queue1, value);
    }
}

static int stack_pop(Stack *stack)
{
    // Input argument validation
    if (stack == NULL) {
        fprintf(stderr, "Error: stack is NULL\n");
        return -1; // Indicating an error
    }
    // Pop operation always empties the non-empty queue except the last element
    QueueCircularSLL *non_empty_queue = &stack->queue1;
    QueueCircularSLL *empty_queue = &stack->queue2;

    if (queue_circular_sll_is_empty(&stack->queue1)) {
        non_empty_queue = &stack->queue2;
        empty_queue = &stack->queue1;
    }

    if (queue_circular_sll_is_empty(non_empty_queue)) {
        fprintf(stderr, "Error: Stack is empty\n");
        return -1; // Indicating an error
    }

    // Dequeue all elements except the last one
    while (non_empty_queue->size > 1) {
        int value = queue_circular_sll_dequeue(non_empty_queue);
        queue_circular_sll_enqueue(empty_queue, value);
    }

    // Return the last element
    return queue_circular_sll_dequeue(non_empty_queue);
}

int main(void)
{
    Stack stack;
    queue_circular_sll_init(&stack.queue1);
    queue_circular_sll_init(&stack.queue2);

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    printf("Pop: %d\n", stack_pop(&stack));
    stack_push(&stack, 30);
    stack_push(&stack, 40);
    printf("Pop: %d\n", stack_pop(&stack));
    stack_push(&stack, 50);
    printf("Pop: %d\n", stack_pop(&stack));
    printf("Pop: %d\n", stack_pop(&stack));
    printf("Pop: %d\n", stack_pop(&stack));
    printf("Pop: %d\n", stack_pop(&stack)); // Attempt to pop from an empty stack
    return 0;
}