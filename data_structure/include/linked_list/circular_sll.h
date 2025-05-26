#ifndef CIRCULAR_SLL_H
#define CIRCULAR_SLL_H

#include <stdint.h>

typedef enum csll_status_t_ {
    CSLL_SUCCESS = 0,
    CSLL_FAILURE,
    CSLL_INVALID_INDEX = 0xFFFF,
} csll_status_t;

typedef struct csll_node_t_ {
    uint32_t data;
    struct csll_node_t_ *next;
} csll_node_t;

typedef struct csll_t_ {
    csll_node_t *head;
    /* Always points to last node to avoid traversal while inserting or deleting */
    csll_node_t *tail;
    uint32_t size;
} csll_t;

csll_t *csll_create(uint32_t data);
csll_status_t csll_destroy(csll_t **list_ref);

csll_status_t csll_insert_at_front(csll_t **list_ref, uint32_t data);
csll_status_t csll_insert_at_back(csll_t **list_ref, uint32_t data);
csll_status_t csll_insert_at_index(csll_t **list_ref, uint32_t index, uint32_t data);

csll_status_t csll_delete_at_front(csll_t **list_ref);
csll_status_t csll_delete_at_back(csll_t **list_ref);
csll_status_t csll_delete_at_index(csll_t **list_ref, uint32_t index);
csll_status_t csll_delete_by_value(csll_t **list_ref, uint32_t data);

csll_status_t csll_print(csll_t *head);
uint32_t csll_search(csll_t *head, uint32_t data);

#endif /* CIRCULAR_SLL_H */