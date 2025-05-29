
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdint.h>
typedef enum sll_status_t_ {
    SLL_SUCCESS = 0,
    SLL_FAILURE,
    SLL_INVALID_INDEX = 0xFFFE,
} sll_status_t;

typedef struct sll_node_t_ {
    uint32_t data;
    struct sll_node_t_ *next;
} sll_node_t;

typedef struct sll_t_ {
    sll_node_t *head;
    uint32_t size;
} sll_t;

/* Basic operations */
sll_t       *sll_create(uint32_t data);
sll_status_t sll_destroy(sll_t **list_ref);

sll_status_t sll_insert_at_front(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_back(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_index(sll_t **list_ref, uint32_t index, uint32_t data);

sll_status_t sll_delete_at_front(sll_t **list_ref);
sll_status_t sll_delete_at_back(sll_t **list_ref);
sll_status_t sll_delete_at_index(sll_t **list_ref, uint32_t index);
sll_status_t sll_delete_by_value(sll_t **list_ref, uint32_t data);
sll_status_t sll_delete_node(sll_t **list_ref, sll_node_t *node);

/* Traversal operations */
sll_status_t sll_print(sll_t *head);
sll_node_t  *sll_get_nth_node_from_end(sll_t **list_ref, uint32_t nth_node);
uint32_t     sll_detect_loop(sll_t **list_ref);
sll_node_t  *sll_detect_and_find_first_node_of_loop(sll_t **list_ref);
uint32_t     sll_detect_and_find_length_of_loop(sll_t **list_ref);
sll_status_t sll_reverse_iterative(sll_t **list_ref);
uint32_t     sll_find_middle_node(sll_t **list_ref);

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
Merge two sorted linked lists
*/

#endif /* SINGLY_LINKED_LIST_H */