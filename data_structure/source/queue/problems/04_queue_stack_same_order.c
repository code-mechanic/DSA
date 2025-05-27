/*
Given queue Q [1, 2, 3, 4, 5]
               ^           ^
               |           |
               front       rear

Make the stack S such that the elements in the stack are in the same order as the queue.
The stack S will be [1, 2, 3, 4, 5] with the top of the stack being 1.
*/

#include "stack_linked_list.h"
#include "queue_circular_sll.h"
#include <stdio.h>

static void make_same_order_stack(QueueCircularSLL *queue, StackLinkedList *stack);

int main(void)
{
    QueueCircularSLL queue;
    StackLinkedList stack;
    queue_circular_sll_init(&queue);
    stack_linked_list_init(&stack);
    queue_circular_sll_enqueue(&queue, 1);
    queue_circular_sll_enqueue(&queue, 2);
    queue_circular_sll_enqueue(&queue, 3);
    queue_circular_sll_enqueue(&queue, 4);
    queue_circular_sll_enqueue(&queue, 5);

    printf("Stack elements in the same order as queue:\n");
    make_same_order_stack(&queue, &stack);
}

static void make_same_order_stack(QueueCircularSLL *queue, StackLinkedList *stack)
{
    // reverse the queue using stack
    while (!queue_circular_sll_is_empty(queue)) {
        int value = queue_circular_sll_dequeue(queue);
        stack_linked_list_push(stack, value);
    }
    // transfer elements from stack to queue
    while (!stack_linked_list_is_empty(stack)) {
        int value = stack_linked_list_pop(stack);
        queue_circular_sll_enqueue(queue, value);
    }
    // transfer elements from queue to stack
    while (!queue_circular_sll_is_empty(queue)) {
        int value = queue_circular_sll_dequeue(queue);
        stack_linked_list_push(stack, value);
    }
    // print stack elements
    StackNode *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
