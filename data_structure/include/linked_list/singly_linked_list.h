
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

sll_t *sll_create(uint32_t data);
sll_status_t sll_destroy(sll_t **list_ref);

sll_status_t sll_insert_at_front(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_back(sll_t **list_ref, uint32_t data);
sll_status_t sll_insert_at_index(sll_t **list_ref, uint32_t index, uint32_t data);

sll_status_t sll_delete_at_front(sll_t **list_ref);
sll_status_t sll_delete_at_back(sll_t **list_ref);
sll_status_t sll_delete_at_index(sll_t **list_ref, uint32_t index);
sll_status_t sll_delete_by_value(sll_t **list_ref, uint32_t data);

sll_status_t sll_print(sll_t *head);
uint32_t sll_search(sll_t *head, uint32_t data);

#endif /* SINGLY_LINKED_LIST_H */