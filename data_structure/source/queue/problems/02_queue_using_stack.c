#include "stack_linked_list.h"
#include <stdio.h>

typedef struct Queue {
    StackLinkedList stackEnque; // Stack for enque operations
    StackLinkedList stackDeque; // Stack for deque operations
} Queue;

static void queue_enque(Queue *queue, int value)
{
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot enqueue.\n");
        return;
    }

    // while enque, if the deque stack is not empty, transfer all elements from deque stack to enque stack
    if(!stack_linked_list_is_empty(&queue->stackDeque)) {
        while(!stack_linked_list_is_empty(&queue->stackDeque)) {
            int value = stack_linked_list_pop(&queue->stackDeque);
            stack_linked_list_push(&queue->stackEnque, value);
        }
    }

    // Push the new value onto the enque stack
    if (stack_linked_list_is_full(&queue->stackEnque)) {
        fprintf(stderr, "Stack overflow: Cannot enqueue %d onto full stack.\n", value);
        return; // Handle stack overflow
    }

    stack_linked_list_push(&queue->stackEnque, value);
}

static int queue_deque(Queue *queue)
{
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot dequeue.\n");
        return -1; // Handle NULL queue pointer
    }

    // If the deque stack is empty, transfer all elements from the enque stack
    if (stack_linked_list_is_empty(&queue->stackDeque)) {
        while (!stack_linked_list_is_empty(&queue->stackEnque)) {
            int value = stack_linked_list_pop(&queue->stackEnque);
            stack_linked_list_push(&queue->stackDeque, value);
        }
    }

    // If the deque stack is still empty, it means the queue is empty
    if (stack_linked_list_is_empty(&queue->stackDeque)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Handle queue underflow
    }

    // Pop from the deque stack to get the front element of the queue
    return stack_linked_list_pop(&queue->stackDeque);
}

int main(void)
{

    Queue queue;
    stack_linked_list_init(&queue.stackEnque);
    stack_linked_list_init(&queue.stackDeque);

    // Enqueue some elements
    for (int i = 1; i <= 5; i++) {
        queue_enque(&queue, i);
    }
    // Dequeuing elements
    for(int i = 1; i <= 5; i++) {
        int value = queue_deque(&queue);
        if (value != -1) {
            printf("Dequeued: %d\n", value);
        } else {
            printf("Queue is empty, cannot dequeue.\n");
        }
    }

    queue_enque(&queue, 0);
    printf("%d\n", queue_deque(&queue));
    queue_enque(&queue, 1);
    queue_enque(&queue, 2);
    printf("%d\n", queue_deque(&queue));
    queue_enque(&queue, 3);
    queue_enque(&queue, 4);
    queue_enque(&queue, 5);
    printf("%d\n", queue_deque(&queue));
    queue_enque(&queue, 6);
    printf("%d\n", queue_deque(&queue));
    printf("%d\n", queue_deque(&queue));
    printf("%d\n", queue_deque(&queue));
    printf("%d\n", queue_deque(&queue));
    return 0;
}
