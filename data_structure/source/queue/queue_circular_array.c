#include "queue_circular_array.h"
#include <stdio.h>

void queue_circular_array_init(QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot initialize a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    for (uint32_t i = 0; i < QUEUE_CIRCULAR_ARRAY_MAX_SIZE; i++) {
        queue->data[i] = 0; // Optionally initialize the data array to zero
    }

    queue->front = 0; // Initialize the front index to 0
    queue->rear = 0;  // Initialize the rear index to 0
    queue->size = 0;  // Initialize the size of the queue to 0
}

void queue_circular_array_enqueue(QueueCircularArray *queue, int value)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot enqueue onto a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    if (queue_circular_array_is_full(queue)) {
        fprintf(stderr, "Queue overflow: Cannot enqueue %d onto full queue.\n", value);
        return; // Handle queue overflow
    }

    queue->data[queue->rear] = value; // Add the value to the rear of the queue
    queue->rear = (queue->rear + 1) % QUEUE_CIRCULAR_ARRAY_MAX_SIZE; // Update rear index circularly
    queue->size++; // Increment the size of the queue
}

int queue_circular_array_dequeue(QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot dequeue from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_array_is_empty(queue)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Handle queue underflow
    }

    int value = queue->data[queue->front]; // Get the value at the front of the queue
    queue->front = (queue->front + 1) % QUEUE_CIRCULAR_ARRAY_MAX_SIZE; // Update front index circularly
    queue->size--; // Decrement the size of the queue

    return value; // Return the dequeued value
}

int queue_circular_array_peek(const QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot peek from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_array_is_empty(queue)) {
        fprintf(stderr, "Queue is empty: Cannot peek.\n");
        return -1; // Handle peek on empty queue
    }

    return queue->data[queue->front]; // Return the value at the front of the queue without modifying it
}

int queue_circular_array_is_empty(const QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot check if a NULL queue is empty.\n");
        return 1; // Consider NULL queue as empty
    }

    return queue->size == 0; // Check if the size of the queue is 0
}

int queue_circular_array_is_full(const QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot check if a NULL queue is full.\n");
        return 0; // Consider NULL queue as not full
    }

    return queue->size == QUEUE_CIRCULAR_ARRAY_MAX_SIZE; // Check if the size of the queue is equal to its maximum size
}

void queue_circular_array_clear(QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot clear a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    queue->front = 0; // Reset the front index to 0
    queue->rear = 0;  // Reset the rear index to 0
    queue->size = 0;  // Reset the size of the queue to 0

    for (uint32_t i = 0; i < QUEUE_CIRCULAR_ARRAY_MAX_SIZE; i++) {
        queue->data[i] = 0; // Optionally reset the data array to zero
    }
}

void queue_circular_array_enqueue_front(QueueCircularArray *queue, int value)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot enqueue onto a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    if (queue_circular_array_is_full(queue)) {
        fprintf(stderr, "Queue overflow: Cannot enqueue %d onto full queue.\n", value);
        return; // Handle queue overflow
    }

    queue->front = (queue->front - 1 + QUEUE_CIRCULAR_ARRAY_MAX_SIZE) % QUEUE_CIRCULAR_ARRAY_MAX_SIZE; // Update front index circularly
    queue->data[queue->front] = value; // Add the value to the front of the queue
    queue->size++; // Increment the size of the queue
}

void queue_circular_array_enqueue_rear(QueueCircularArray *queue, int value)
{
    queue_circular_array_enqueue(queue, value); // Use the existing enqueue function for rear insertion
}

int queue_circular_array_dequeue_front(QueueCircularArray *queue)
{
    return queue_circular_array_dequeue(queue);
}

int queue_circular_array_dequeue_rear(QueueCircularArray *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot dequeue from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_array_is_empty(queue)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Handle queue underflow
    }

    queue->rear = (queue->rear - 1 + QUEUE_CIRCULAR_ARRAY_MAX_SIZE) % QUEUE_CIRCULAR_ARRAY_MAX_SIZE; // Update rear index circularly
    int value = queue->data[queue->rear]; // Get the value at the rear of the queue
    queue->size--; // Decrement the size of the queue

    return value; // Return the dequeued value
}
