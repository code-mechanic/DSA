
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdint.h>

/* Forward declaration */
typedef struct sll_node_t_ sll_node_t;

typedef enum sll_status_t_ {
    SLL_SUCCESS = 0,
    SLL_FAILURE,
    SLL_INVALID_INDEX = 0xFFFF,
} sll_status_t;

typedef struct sll_t_ {
    sll_node_t *head;
    uint32_t size;
} sll_t;

/* Basic operations */
sll_t *sll_create(uint32_t data);
sll_status_t sll_destroy(sll_t **list_ref);

sll_status_t sll_insert_at_front(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_back(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_index(sll_t **list_ref, uint32_t index, uint32_t data);

sll_status_t sll_delete_at_front(sll_t **list_ref);
sll_status_t sll_delete_at_back(sll_t **list_ref);
sll_status_t sll_delete_at_index(sll_t **list_ref, uint32_t index);
sll_status_t sll_delete_by_value(sll_t **list_ref, uint32_t data);

/* TODO Traversal operations */
sll_status_t sll_print(sll_t *head);
/*
Reverse the list - Iterative versions.
print the list in reverse order - Use stack
Count the number of nodes
Check if list is empty
Get nth node from beginning/end
Find middle element of the list
Detect and remove loop (cycle) - Use Floyd’s Cycle-Finding Algorithm (Tortoise & Hare).
*/

/* TODO Modification operations */
/*
Remove duplicates
From unsorted list (use hash set).
From sorted list (linear scan).
Sort the linked list
Merge sort (efficient for linked lists).
Swap two nodes by value (not data)
Rotate the list
Rotate by k positions (left or right).
Move last node to front
Move last ‘k’ nodes to the front
*/

/* TODO Search and compare operations */
uint32_t sll_search(sll_t *head, uint32_t data);

/*
Compare two lists
    Element-wise check for equality.
Check if a list is palindrome
    Use fast/slow pointers + stack or reverse second half.
Find intersection point of two linked lists
Merge two sorted linked lists
*/

#endif /* SINGLY_LINKED_LIST_H */