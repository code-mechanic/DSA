#ifndef QUEUE_CIRCULAR_ARRAY_H
#define QUEUE_CIRCULAR_ARRAY_H

#include <stdint.h>

#define QUEUE_CIRCULAR_ARRAY_MAX_SIZE 10 // Define the maximum size of the queue

typedef struct {
    int data[QUEUE_CIRCULAR_ARRAY_MAX_SIZE]; // Array to hold the queue elements
    uint32_t front; // Index of the front element
    uint32_t rear;  // Index of the rear element
    uint32_t size;  // Number of elements in the queue
} QueueCircularArray;

/* Classic queue operations */
void queue_circular_array_init(QueueCircularArray *queue);
void queue_circular_array_enqueue(QueueCircularArray *queue, int value);
int queue_circular_array_dequeue(QueueCircularArray *queue);
int queue_circular_array_peek(const QueueCircularArray *queue);
int queue_circular_array_is_empty(const QueueCircularArray *queue);
int queue_circular_array_is_full(const QueueCircularArray *queue);
void queue_circular_array_clear(QueueCircularArray *queue);

/* Double Ended queue (DEque) operations */
void queue_circular_array_enqueue_front(QueueCircularArray *queue, int value);
void queue_circular_array_enqueue_rear(QueueCircularArray *queue, int value);
int queue_circular_array_dequeue_front(QueueCircularArray *queue);
int queue_circular_array_dequeue_rear(QueueCircularArray *queue);

#endif // QUEUE_CIRCULAR_ARRAY_H