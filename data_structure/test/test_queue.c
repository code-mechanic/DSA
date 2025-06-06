#include "queue_circular_array.h"
#include "queue_circular_sll.h"
#include <stdio.h>

static void test_queue_circular_array(void);
static void test_queue_circular_sll(void);
static void test_double_ended_queue_circular_array(void);
static void test_double_ended_queue_circular_sll(void);
static void queue_circular_array_print(const QueueCircularArray *queue);
static void queue_circular_sll_print(const QueueCircularSLL *queue);

int main()
{
    printf("Testing Circular Array Queue Implementation:\n");
    test_queue_circular_array();

    printf("\nTesting Circular Singly Linked List Queue Implementation:\n");
    test_queue_circular_sll();

    printf("Testing Circular Array double Ended Queue Implementation:\n");
    test_double_ended_queue_circular_array();

    printf("Testing Circular Singly Linked List double Ended Queue Implementation:\n");
    test_double_ended_queue_circular_sll();

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

static void test_double_ended_queue_circular_array(void)
{
    QueueCircularArray queue;
    queue_circular_array_init(&queue);
    
    queue_circular_array_enqueue_front(&queue, 1);
    queue_circular_array_enqueue_front(&queue, 2);
    queue_circular_array_enqueue_front(&queue, 3);
    queue_circular_array_enqueue_front(&queue, 4);

    queue_circular_array_enqueue_rear(&queue, 5);
    queue_circular_array_enqueue_rear(&queue, 6);
    queue_circular_array_enqueue_rear(&queue, 7);
    queue_circular_array_enqueue_rear(&queue, 8);

    /* At this point queue should be {4, 3, 2, 1, 5, 6, 7, 8} */
    queue_circular_array_print(&queue);

    queue_circular_array_dequeue_front(&queue);
    queue_circular_array_dequeue_rear(&queue);
    
    /* After dequeue operations, queue should be {3, 2, 1, 5, 6, 7} */
    queue_circular_array_print(&queue);
    
    queue_circular_array_dequeue_front(&queue);
    queue_circular_array_dequeue_front(&queue);
    queue_circular_array_print(&queue);

    queue_circular_array_dequeue_rear(&queue);
    queue_circular_array_dequeue_rear(&queue);
    queue_circular_array_print(&queue);

    queue_circular_array_dequeue_front(&queue);
    queue_circular_array_dequeue_front(&queue);
    queue_circular_array_print(&queue);
}

static void test_double_ended_queue_circular_sll(void)
{
    QueueCircularSLL queue;
    queue_circular_sll_init(&queue);
    
    queue_circular_sll_enqueue_front(&queue, 1);
    queue_circular_sll_enqueue_front(&queue, 2);
    queue_circular_sll_enqueue_front(&queue, 3);
    queue_circular_sll_enqueue_front(&queue, 4);

    queue_circular_sll_enqueue_rear(&queue, 5);
    queue_circular_sll_enqueue_rear(&queue, 6);
    queue_circular_sll_enqueue_rear(&queue, 7);
    queue_circular_sll_enqueue_rear(&queue, 8);

    /* At this point queue should be {4, 3, 2, 1, 5, 6, 7, 8} */
    printf("Queue after enqueuing elements:\n");
    queue_circular_sll_print(&queue);

    queue_circular_sll_dequeue_front(&queue);
    queue_circular_sll_dequeue_rear(&queue);
    
    /* After dequeue operations, queue should be {3, 2, 1, 5, 6, 7} */
    printf("Queue after dequeuing front and rear:\n");
    queue_circular_sll_print(&queue);
    
    queue_circular_sll_dequeue_front(&queue);
    queue_circular_sll_dequeue_front(&queue);
    printf("Queue after dequeuing two fronts:\n");
    queue_circular_sll_print(&queue);

    queue_circular_sll_dequeue_rear(&queue);
    queue_circular_sll_dequeue_rear(&queue);
    printf("Queue after dequeuing two rears:\n");
    queue_circular_sll_print(&queue);

    queue_circular_sll_dequeue_front(&queue);
    queue_circular_sll_dequeue_front(&queue);
    printf("Queue after dequeuing remaining elements:\n");
    queue_circular_sll_print(&queue);
}

static void queue_circular_sll_print(const QueueCircularSLL *queue)
{
    if (!queue) {
        printf("Queue is NULL.\n");
        return;
    }

    if (queue_circular_sll_is_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    QueueNode *current = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

static void queue_circular_array_print(const QueueCircularArray *queue)
{
    if (!queue) {
        printf("Queue is NULL.\n");
        return;
    }

    if (queue_circular_array_is_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (uint32_t i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[(queue->front + i) % QUEUE_CIRCULAR_ARRAY_MAX_SIZE]);
    }
    printf("\n");
}

