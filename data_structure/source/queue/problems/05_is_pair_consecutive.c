/*
    Given a stack of integers, how do you check whether each successive pair of numbers in the stack is consecutive or not.
    The pairs can be increasing or decreasing, and if the stack has an odd number of elements, the element at the top is 
    left out of a pair. For example, if the stack of elements are [4, 5, -2, -3, 11, 10, 5, 6, 20], then the output should
    be true because each of the pairs (4, 5), (-2, -3), (11, 10), and (5, 6) consists of consecutive numbers.
*/

#include "queue_circular_sll.h"
#include "stack_linked_list.h"
#include <stdio.h>

static int is_pair_consecutive(StackLinkedList *stack);
static void stack_linked_list_print(StackLinkedList *stack)
{
    if (!stack || stack_linked_list_is_empty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    StackNode *current = stack->top;
    printf("Stack elements: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    StackLinkedList stack;
    stack_linked_list_init(&stack);

    /* Populate sample pair of numbers in the stack */
    stack_linked_list_push(&stack, 4);
    stack_linked_list_push(&stack, 5);
    stack_linked_list_push(&stack, -2);
    stack_linked_list_push(&stack, -3);
    stack_linked_list_push(&stack, 11);
    stack_linked_list_push(&stack, 10);
    stack_linked_list_push(&stack, 5);
    stack_linked_list_push(&stack, 6);
    stack_linked_list_push(&stack, 20);
    stack_linked_list_push(&stack, 23);

    stack_linked_list_print(&stack);
    printf("is_pair_consecutive: %s\n", is_pair_consecutive(&stack) ? "true" : "false");
    stack_linked_list_print(&stack);

    // Free the stack
    stack_linked_list_clear(&stack);
    return 0;
}

static int is_pair_consecutive(StackLinkedList *stack)
{
    if (!stack || stack_linked_list_is_empty(stack)) {
        return 1; // Empty stack or NULL stack is considered as having consecutive pairs
    }

    int value;
    int is_consecutive = 1;
    QueueCircularSLL queue;
    queue_circular_sll_init(&queue);

    // Reverse the stack
    while(!stack_linked_list_is_empty(stack)) {
        value = stack_linked_list_pop(stack);
        queue_circular_sll_enqueue(&queue, value);
    }

    while(!queue_circular_sll_is_empty(&queue)) {
        value = queue_circular_sll_dequeue(&queue);
        stack_linked_list_push(stack, value);
    }

    // Check pairs in the stack
    while(!stack_linked_list_is_empty(stack)) {
        int first = stack_linked_list_pop(stack);
        // Push the elements to queue to maintain the original order
        queue_circular_sll_enqueue(&queue, first);

        if (!stack_linked_list_is_empty(stack)) {
            int second = stack_linked_list_pop(stack);
            // Push the elements to queue to maintain the original order
            queue_circular_sll_enqueue(&queue, second);

            // Check if the pair is consecutive
            if (! (((first + 1) == second) || ((first - 1) == second))) {
                is_consecutive = 0; // If any pair is not consecutive, set flag to false
            }
        }
    }

    // Restore the stack from the queue
    while(!queue_circular_sll_is_empty(&queue)) {
        value = queue_circular_sll_dequeue(&queue);
        stack_linked_list_push(stack, value);
    }

    return is_consecutive;
}