#ifndef CIRCULAR_DLL_H
#define CIRCULAR_DLL_H

#include <stdint.h>

typedef enum cdll_status_t_ {
    CDLL_SUCCESS = 0,
    CDLL_FAILURE,
    CDLL_INVALID_INDEX = 0xFFFF,
} cdll_status_t;

typedef struct cdll_node_t_ {
    uint32_t data;
    struct cdll_node_t_ *next;
    struct cdll_node_t_ *prev;
} cdll_node_t;

typedef struct cdll_t_ {
    cdll_node_t *head;
    /* Always points to last node to avoid traversal while inserting or deleting */
    cdll_node_t *tail;
    uint32_t size;
} cdll_t;

cdll_t *cdll_create(uint32_t data);
cdll_status_t cdll_destroy(cdll_t **list_ref);

cdll_status_t cdll_insert_at_front(cdll_t **list_ref, uint32_t data);
cdll_status_t cdll_insert_at_back(cdll_t **list_ref, uint32_t data);
cdll_status_t cdll_insert_at_index(cdll_t **list_ref, uint32_t index, uint32_t data);

cdll_status_t cdll_delete_at_front(cdll_t **list_ref);
cdll_status_t cdll_delete_at_back(cdll_t **list_ref);
cdll_status_t cdll_delete_at_index(cdll_t **list_ref, uint32_t index);
cdll_status_t cdll_delete_by_value(cdll_t **list_ref, uint32_t data);

cdll_status_t cdll_print(cdll_t *head);
uint32_t cdll_search(cdll_t *head, uint32_t data);

#endif /* CIRCULAR_SLL_H */