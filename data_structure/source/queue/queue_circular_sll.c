#include "queue_circular_sll.h"
#include <stdio.h>
#include <stdlib.h>

void queue_circular_sll_init(QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot initialize a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    queue->front = NULL; // Initialize front to NULL
    queue->rear = NULL;  // Initialize rear to NULL
    queue->size = 0;     // Initialize size to 0
}

void queue_circular_sll_enqueue(QueueCircularSLL *queue, int value)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot enqueue onto a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    if (queue_circular_sll_is_full(queue)) {
        fprintf(stderr, "Queue overflow: Cannot enqueue %d onto full queue.\n", value);
        return; // Handle queue overflow
    }

    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed: Cannot enqueue %d.\n", value);
        return; // Handle memory allocation failure
    }
    
    new_node->value = value;
    new_node->next = NULL;

    if (queue->size == 0) {
        queue->front = new_node;
        queue->rear = new_node;
        new_node->next = new_node; // Point to itself to make it circular
    } else {
        queue->rear->next = new_node; // Link the new node at the end
        queue->rear = new_node; // Update rear to the new node
        new_node->next = queue->front; // Point the new node to front
    }

    queue->size++; // Increment the size of the queue
}

int queue_circular_sll_dequeue(QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot dequeue from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_sll_is_empty(queue)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue.\n");
        return -1; // Handle queue underflow
    }

    QueueNode *temp = queue->front;
    int value = temp->value;

    if (queue->size == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next; // Move front to the next node
        queue->rear->next = queue->front; // Update rear to point to new front
    }

    free(temp); // Free the dequeued node
    queue->size--; // Decrement the size of the queue

    return value; // Return the dequeued value
}

int queue_circular_sll_peek(const QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot peek from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_sll_is_empty(queue)) {
        fprintf(stderr, "Queue is empty: Cannot peek.\n");
        return -1; // Handle peek on empty queue
    }

    return queue->front->value; // Return the value at the front of the queue without modifying it
}

int queue_circular_sll_is_empty(const QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot check if a NULL queue is empty.\n");
        return 1; // Consider NULL queue as empty
    }

    return queue->size == 0; // Check if the size of the queue is 0
}

int queue_circular_sll_is_full(const QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot check if a NULL queue is full.\n");
        return 0; // Consider NULL queue as not full
    }

    return queue->size >= QUEUE_CIRCULAR_SLL_MAX_SIZE; // Check if the size of the queue exceeds the maximum size
}

void queue_circular_sll_clear(QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot clear a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    while (!queue_circular_sll_is_empty(queue)) {
        queue_circular_sll_dequeue(queue); // Dequeue all elements
    }

    queue->front = NULL; // Reset front to NULL
    queue->rear = NULL;  // Reset rear to NULL
    queue->size = 0;     // Reset size to 0
}

void queue_circular_sll_enqueue_front(QueueCircularSLL *queue, int value)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot enqueue front onto a NULL queue.\n");
        return; // Handle NULL queue pointer
    }

    if (queue_circular_sll_is_full(queue)) {
        fprintf(stderr, "Queue overflow: Cannot enqueue %d onto full queue.\n", value);
        return; // Handle queue overflow
    }

    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed: Cannot enqueue %d at front.\n", value);
        return; // Handle memory allocation failure
    }

    new_node->value = value;

    if (queue->size == 0) {
        new_node->next = new_node; // Point to itself to make it circular
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        new_node->next = queue->front; // Point new node to current front
        queue->rear->next = new_node;   // Link rear to the new node
        queue->front = new_node;         // Update front to the new node
    }

    queue->size++; // Increment the size of the queue
}

void queue_circular_sll_enqueue_rear(QueueCircularSLL *queue, int value)
{
    queue_circular_sll_enqueue(queue, value); // Use the existing enqueue function for rear
}

int queue_circular_sll_dequeue_front(QueueCircularSLL *queue)
{
    return queue_circular_sll_dequeue(queue); // Use the existing dequeue function for front
}

int queue_circular_sll_dequeue_rear(QueueCircularSLL *queue)
{
    /* Input argument check */
    if (!queue) {
        fprintf(stderr, "Queue is NULL: Cannot dequeue rear from a NULL queue.\n");
        return -1; // Handle NULL queue pointer
    }

    if (queue_circular_sll_is_empty(queue)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue rear from an empty queue.\n");
        return -1; // Handle queue underflow
    }

    if (queue->size == 1) {
        return queue_circular_sll_dequeue(queue); // If only one element, use the existing dequeue function
    }

    QueueNode *current = queue->front;
    while (current->next != queue->rear) {
        current = current->next; // Traverse to the second last node
    }

    int value = queue->rear->value; // Get the value of the rear node
    free(queue->rear); // Free the rear node
    queue->rear = current; // Update rear to the second last node
    queue->rear->next = queue->front; // Make it circular again
    queue->size--; // Decrement the size of the queue

    return value; // Return the dequeued value from the rear
}
