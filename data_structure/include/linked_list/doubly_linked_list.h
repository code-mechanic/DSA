#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdint.h>

/* Forward declaration */
typedef struct dll_node_t_ dll_node_t;

typedef enum dll_status_t_ {
    DLL_SUCCESS = 0,
    DLL_FAILURE,
    DLL_INVALID_INDEX = 0xFFFF,
} dll_status_t;

typedef struct dll_t_ {
    dll_node_t *head;
    uint32_t size;
} dll_t;

dll_t *dll_create(uint32_t data);
dll_status_t dll_destroy(dll_t **list_ref);

dll_status_t dll_insert_at_front(dll_t **list_ref, uint32_t data);
dll_status_t dll_insert_at_back(dll_t **list_ref, uint32_t data);
dll_status_t dll_insert_at_index(dll_t **list_ref, uint32_t index, uint32_t data);

dll_status_t dll_delete_at_front(dll_t **list_ref);
dll_status_t dll_delete_at_back(dll_t **list_ref);
dll_status_t dll_delete_at_index(dll_t **list_ref, uint32_t index);
dll_status_t dll_delete_by_value(dll_t **list_ref, uint32_t data);

dll_status_t dll_print(dll_t *head);
uint32_t dll_search(dll_t *head, uint32_t data);

#endif /* DOUBLY_LINKED_LIST_H */