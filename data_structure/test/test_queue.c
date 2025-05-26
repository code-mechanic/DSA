#include "queue_circular_array.h"
#include "queue_circular_sll.h"
#include <stdio.h>

static void test_queue_circular_array(void);
static void test_queue_circular_sll(void);

int main()
{
    printf("Testing Circular Array Queue Implementation:\n");
    test_queue_circular_array();

    printf("\nTesting Circular Singly Linked List Queue Implementation:\n");
    test_queue_circular_sll();

    return 0;
}

static void test_queue_circular_array(void)
{
    QueueCircularArray queue;
    queue_circular_array_init(&queue);

    // Test enqueue operation
    for (int i = 0; i < 5; i++) {
        queue_circular_array_enqueue(&queue, i);
        printf("Enqueued %d to the circular array queue.\n", i);
    }

    // Test peek operation
    int front_value = queue_circular_array_peek(&queue);
    printf("Front value is: %d\n", front_value);

    // Test dequeue operation
    while (!queue_circular_array_is_empty(&queue)) {
        int dequeued_value = queue_circular_array_dequeue(&queue);
        printf("Dequeued %d from the circular array queue.\n", dequeued_value);
    }

    // Test underflow condition
    int underflow_value = queue_circular_array_dequeue(&queue);
    printf("Attempted to dequeue from empty queue, got: %d\n", underflow_value);

    // Test overflow condition
    for (uint32_t i = 0; i < QUEUE_CIRCULAR_ARRAY_MAX_SIZE + 2; i++) {
        queue_circular_array_enqueue(&queue, i);
        if (i < QUEUE_CIRCULAR_ARRAY_MAX_SIZE) {
            printf("Enqueued %d to the circular array queue.\n", i);
        } else {
            printf("Attempted to enqueue %d to full circular array queue.\n", i);
        }
    }

    // Test clearing the queue
    queue_circular_array_clear(&queue);
    printf("Circular array queue cleared.\n");
}

static void test_queue_circular_sll(void)
{
    QueueCircularSLL queue;
    queue_circular_sll_init(&queue);

    // Test enqueue operation
    for (int i = 0; i < 5; i++) {
        queue_circular_sll_enqueue(&queue, i);
        printf("Enqueued %d to the circular singly linked list queue.\n", i);
    }

    // Test peek operation
    int front_value = queue_circular_sll_peek(&queue);
    printf("Front value is: %d\n", front_value);

    // Test dequeue operation
    while (!queue_circular_sll_is_empty(&queue)) {
        int dequeued_value = queue_circular_sll_dequeue(&queue);
        printf("Dequeued %d from the circular singly linked list queue.\n", dequeued_value);
    }

    // Test underflow condition
    int underflow_value = queue_circular_sll_dequeue(&queue);
    printf("Attempted to dequeue from empty queue, got: %d\n", underflow_value);

    // Test overflow condition
    for (uint32_t i = 0; i < QUEUE_CIRCULAR_SLL_MAX_SIZE + 2; i++) {
        queue_circular_sll_enqueue(&queue, i);
        if (i < QUEUE_CIRCULAR_SLL_MAX_SIZE) {
            printf("Enqueued %d to the circular singly linked list queue.\n", i);
        } else {
            printf("Attempted to enqueue %d to full circular singly linked list queue.\n", i);
        }
    }

    // Test clearing the queue
    queue_circular_sll_clear(&queue);
    printf("Circular singly linked list queue cleared.\n");
}
