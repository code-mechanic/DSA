#include "queue_circular_sll.h"
#include "stack_linked_list.h"
#include <stdio.h>

static void print_qeueue(const QueueCircularSLL *queue);
static void reverse_queue(QueueCircularSLL *queue);

int main()
{
    // Create a queue
    QueueCircularSLL queue;
    queue_circular_sll_init(&queue);

    // Enqueue some elements
    for(uint32_t i = 1; i <= 5; i++) {
        queue_circular_sll_enqueue(&queue, i);
    }

    // Print the queue before reversing
    printf("Queue before reversing: ");
    print_qeueue(&queue);

    // Reverse the queue
    reverse_queue(&queue);
    printf("\nQueue after reversing: ");
    print_qeueue(&queue);
    printf("\n");

    queue_circular_sll_clear(&queue); // Clear the queue after use
    return 0;
}

void print_qeueue(const QueueCircularSLL *queue)
{
    if (!queue || queue_circular_sll_is_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    QueueNode *current = queue->front;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != queue->front);
}

void reverse_queue(QueueCircularSLL *queue)
{
    if (!queue || queue_circular_sll_is_empty(queue)) {
        return;
    }

    StackLinkedList stack;
    stack_linked_list_init(&stack);

    while (!queue_circular_sll_is_empty(queue)) {
        stack_linked_list_push(&stack, queue_circular_sll_dequeue(queue));
    }

    while (!stack_linked_list_is_empty(&stack)) {
        queue_circular_sll_enqueue(queue, stack_linked_list_pop(&stack));
    }

    stack_linked_list_clear(&stack); // Clear the stack after use
}
