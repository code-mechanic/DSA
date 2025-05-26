#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node_t_ {
    uint32_t data;
    struct dll_node_t_ *next;
    struct dll_node_t_ *prev;
} dll_node_t;

dll_t *dll_create(uint32_t data)
{
    /* Allocate memory for the dll_t struct */
    dll_t *dll = (dll_t *) malloc(sizeof(dll_t));
    if(dll == NULL) {
        return NULL;
    }

    /* Allocate memory for the dll_node_t struct */
    dll->head = (dll_node_t *) malloc(sizeof(dll_node_t));
    if(dll->head == NULL) {
        free(dll);
        return NULL;
    }

    dll->head->data = data;
    dll->head->next = NULL;
    dll->head->prev = NULL;
    dll->size = 1;
    return dll;
}

dll_status_t dll_destroy(dll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    /* Free the memory allocated for the dll_t struct and dll_node_t struct */
    dll_node_t *temp = (*list_ref)->head;
    while (temp != NULL)
    {
        dll_node_t *next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list_ref);
    *list_ref = NULL;
    return DLL_SUCCESS;
}

dll_status_t dll_insert_at_front(dll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    /* Allocate memory for the dll_node_t struct */
    dll_node_t *new_node = (dll_node_t *) malloc(sizeof(dll_node_t));
    if(new_node == NULL) {
        return DLL_FAILURE;
    }
    new_node->data = data;
    new_node->next = (*list_ref)->head;
    new_node->prev = NULL;

    /* Insert head node to next of new node */
    (*list_ref)->head->prev = new_node;

    /* Make new node as the head node */
    (*list_ref)->head = new_node;
    (*list_ref)->size++;

    return DLL_SUCCESS;
}

dll_status_t dll_insert_at_back(dll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    /* Allocate memory for the dll_node_t struct */
    dll_node_t *new_node = (dll_node_t *) malloc(sizeof(dll_node_t));
    if(new_node == NULL) {
        return DLL_FAILURE;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    /* Find the last node */
    dll_node_t *temp = (*list_ref)->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /* Insert the new node at the end */
    temp->next = new_node;
    new_node->prev = temp;
    (*list_ref)->size++;

    return DLL_SUCCESS;
}

dll_status_t dll_insert_at_index(dll_t **list_ref, uint32_t index, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    if(index > (*list_ref)->size || index < 1) {
        /* Index should not be greater than size and one-index based */
        return DLL_FAILURE;
    }

    if(index == 1) {
        return dll_insert_at_front(list_ref, data);
    } else {
        /* Example logic if index is other than 1:
        *
        * Initial state:
        * head -> [NULL|10|*] -> [*|11|*] -> [*|12|*] -> [*|13|NULL]
        * 
        * new node [NULL|14|NULL] at index 3
        * 
        *                idx:1          idx:2       idx:3       idx:4
        *        head -> [NULL|10|*] -> [*|11|*] -> [*|12|*] -> [*|13|NULL]
        * step1:                temp -> [*|11|*]
        * step2:                        [NULL|14|*] -> [*|12|*]
        * step3:            [*|11|*] -> [*|14|*] -> [*|12|*]
        * 
        */

        /* Allocate memory for the dll_node_t struct */
        dll_node_t *new_node = (dll_node_t *) malloc(sizeof(dll_node_t));
        if(new_node == NULL) {
            return DLL_FAILURE;
        }
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        /* Insert the new node at the index */
        dll_node_t *temp = (*list_ref)->head;
        /*
         * `i` is assigned to 1 becasue index is one-index based and already
         * head points to the first node and Find the node at the index - 1
         */
        for (uint32_t i = 1; i < index - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
        (*list_ref)->size++;
    }

    return DLL_SUCCESS;
}

dll_status_t dll_delete_at_front(dll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    /* Delete the head node */
    dll_node_t *temp = (*list_ref)->head;
    (*list_ref)->head = temp->next;
    (*list_ref)->head->prev = NULL;
    free(temp);
    (*list_ref)->size--;
    return DLL_SUCCESS;
}

dll_status_t dll_delete_at_back(dll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    /* check if there is only one node in the list */
    if((*list_ref)->head->next == NULL) {
        return dll_delete_at_front(list_ref);
    }

    /* Delete the last node */
    dll_node_t *temp = (*list_ref)->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    (*list_ref)->size--;
    return DLL_SUCCESS;
}

dll_status_t dll_delete_at_index(dll_t **list_ref, uint32_t index)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    if(index > (*list_ref)->size) {
        /* Index should not be greater than size and one-index based */
        return DLL_FAILURE;
    }

    /* Delete the node at the index */
    if(index == 1) {
        return dll_delete_at_front(list_ref);
    } else if (index == (*list_ref)->size) {
        return dll_delete_at_back(list_ref);
    } else {
        /* Example logic if index is other than 1:
        *
        * Initial state:
        * head -> [NULL|10|*] -> [*|11|*] -> [*|12|*] -> [*|14|*] -> [*|13|NULL]
        * 
        * delete node at index 4, [NULL|14|NULL]
        * 
        *                idx:1          idx:2       idx:3       idx:4
        *        head -> [NULL|10|*] -> [*|11|*] -> [*|12|*] -> [*|14|*] -> [*|13|NULL]
        * step1:                            temp -> [*|12|*]
        * step2:                              node_to_delete -> [*|14|*]
        * step3:                            temp -> [*|12|*] -> [*|13|NULL]
        * 
        */

        dll_node_t *temp = (*list_ref)->head;
        /*
        * head_pos is assigned to 1 becasue index is one-index based and already
        * head points to the first node and Find the node at the index - 1
        */
        for (uint32_t head_pos = 1; head_pos < index - 1; head_pos++)
        {
            temp = temp->next;
        }
        dll_node_t *node_to_delete = temp->next;
        temp->next = node_to_delete->next;
        node_to_delete->next->prev = temp;
        free(node_to_delete);
        (*list_ref)->size--;
    }
    return DLL_SUCCESS;
}

dll_status_t dll_delete_by_value(dll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return DLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by dll_create().
         * Use dll_destroy() followed by dll_create(). 
         */
        return DLL_FAILURE;
    }

    /* Find the index of the data */
    uint32_t index = dll_search(*list_ref, data);
    if(index == DLL_INVALID_INDEX) {
        return DLL_FAILURE;
    }

    /* Delete the node at the index */
    return dll_delete_at_index(list_ref, index);
}

dll_status_t dll_print(dll_t *head)
{
    /* Input argument check */
    if(head == NULL) {
        return DLL_FAILURE;
    }

    dll_node_t *temp = head->head;
    while (temp != NULL)
    {
        printf("%d ", (int) temp->data);
        temp = temp->next;
    }
    printf("\n");
    return DLL_SUCCESS;
}

uint32_t dll_search(dll_t *head, uint32_t data)
{
    /* Input argument check */
    if(head == NULL) {
        return DLL_INVALID_INDEX;
    }

    dll_node_t *temp = head->head;
    uint32_t index = 1;
    while (temp != NULL)
    {
        if(temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return DLL_INVALID_INDEX;
}
