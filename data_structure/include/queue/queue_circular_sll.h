#ifndef QUEUE_CIRCULAT_SLL_H
#define QUEUE_CIRCULAR_SLL_H

#include <stdint.h>

#define QUEUE_CIRCULAR_SLL_MAX_SIZE 10 // Define the maximum size of the queue

typedef struct QueueNode {
    int value; // Value of the node
    struct QueueNode *next; // Pointer to the next node
} QueueNode;

typedef struct {
    QueueNode *front; // Pointer to the front node
    QueueNode *rear;  // Pointer to the rear node
    uint32_t size;    // Number of elements in the queue
} QueueCircularSLL;

void queue_circular_sll_init(QueueCircularSLL *queue);
/* Similar to csll_insert_at_end() */
void queue_circular_sll_enqueue(QueueCircularSLL *queue, int value);
/* Similar to csll_delete_at_front() */
int queue_circular_sll_dequeue(QueueCircularSLL *queue);
int queue_circular_sll_peek(const QueueCircularSLL *queue);
int queue_circular_sll_is_empty(const QueueCircularSLL *queue);
int queue_circular_sll_is_full(const QueueCircularSLL *queue);
void queue_circular_sll_clear(QueueCircularSLL *queue);

#endif // QUEUE_CIRCULAT_SLL_H