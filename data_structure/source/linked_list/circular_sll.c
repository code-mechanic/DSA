#include "circular_sll.h"
#include <stdlib.h>
#include <stdio.h>

csll_t *csll_create(uint32_t data)
{
    /* Allocate memory for the csll_t struct */
    csll_node_t *node = malloc(sizeof(csll_node_t));
    if(node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = node;

    /* Allocate memory for the csll_t struct */
    csll_t *list = malloc(sizeof(csll_t));
    if(list == NULL) {
        free(node);
        return NULL;
    }
    list->head = node;
    list->tail = node;
    list->size = 1;

    return list;
}

csll_status_t csll_destroy(csll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    csll_node_t *temp = (*list_ref)->head;
    while(temp != (*list_ref)->tail) {
        csll_node_t *next = temp->next;
        free(temp);
        temp = next;
    }

    free(temp);
    free(*list_ref);
    *list_ref = NULL;
    return CSLL_SUCCESS;
}

csll_status_t csll_insert_at_front(csll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    csll_node_t *node = malloc(sizeof(csll_node_t));
    if(node == NULL) {
        return CSLL_FAILURE;
    }
    node->data = data;
    node->next = (*list_ref)->head;
    (*list_ref)->head = node;
    (*list_ref)->tail->next = node;
    (*list_ref)->size++;
    return CSLL_SUCCESS;
}

csll_status_t csll_insert_at_back(csll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    if((*list_ref)->tail == (*list_ref)->head) {
        return csll_insert_at_front(list_ref, data);
    } else {
        csll_node_t *node = malloc(sizeof(csll_node_t));
        if(node == NULL) {
            return CSLL_FAILURE;
        }
        node->data = data;
        node->next = (*list_ref)->head;
        (*list_ref)->tail->next = node;
        (*list_ref)->tail = node;
        (*list_ref)->size++;
        return CSLL_SUCCESS;
    }
}

csll_status_t csll_insert_at_index(csll_t **list_ref, uint32_t index, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    if(index > (*list_ref)->size) {
        /* Index should not be greater than size */
        return CSLL_FAILURE;
    }

    if(index == 1) {
        return csll_insert_at_front(list_ref, data);
    } else {
        csll_node_t *node = malloc(sizeof(csll_node_t));
        if(node == NULL) {
            return CSLL_FAILURE;
        }
        node->data = data;
        csll_node_t *temp = (*list_ref)->head;
        for(uint32_t i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        (*list_ref)->size++;
    }

    return CSLL_SUCCESS;
}

csll_status_t csll_delete_at_front(csll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    csll_node_t *temp = (*list_ref)->head;
    (*list_ref)->head = temp->next;
    (*list_ref)->tail->next = (*list_ref)->head;
    free(temp);
    (*list_ref)->size--;
    return CSLL_SUCCESS;
}

csll_status_t csll_delete_at_back(csll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    if((*list_ref)->tail == (*list_ref)->head) {
        return csll_delete_at_front(list_ref);
    } else {
        csll_node_t *temp = (*list_ref)->head;
        while(temp->next != (*list_ref)->tail) {
            temp = temp->next;
        }
        temp->next = (*list_ref)->head;
        free((*list_ref)->tail);
        (*list_ref)->tail = temp;
        (*list_ref)->size--;
        return CSLL_SUCCESS;
    }
}

csll_status_t csll_delete_at_index(csll_t **list_ref, uint32_t index)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    if(index > (*list_ref)->size) {
        /* Index should not be greater than size */
        return CSLL_FAILURE;
    }

    if(index == 1) {
        return csll_delete_at_front(list_ref);
    } else if(index == (*list_ref)->size) {
        return csll_delete_at_back(list_ref);
    } else {
        csll_node_t *temp = (*list_ref)->head;
        /*
         * `i` is assigned to 1 becasue index is one-index based and already
         * head points to the first node and Find the node at the index - 1
         */
        for(uint32_t i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        csll_node_t *node = temp->next;
        temp->next = node->next;
        free(node);
        (*list_ref)->size--;
        return CSLL_SUCCESS;
    }
}

csll_status_t csll_delete_by_value(csll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CSLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by csll_create().
         * Use csll_destroy() followed by csll_create(). 
         */
        return CSLL_FAILURE;
    }

    uint32_t index = csll_search(*list_ref, data);
    if(index == CSLL_INVALID_INDEX) {
        return CSLL_FAILURE;
    } else {
        return csll_delete_at_index(list_ref, index);
    }
}

csll_status_t csll_print(csll_t *head)
{
    /* Input argument check */
    if(head == NULL) {
        return CSLL_FAILURE;
    }

    csll_node_t *temp = head->head;
    while(temp != head->tail) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);

    return CSLL_SUCCESS;
}

uint32_t csll_search(csll_t *head, uint32_t data)
{
    /* Input argument check */
    if(head == NULL) {
        return CSLL_INVALID_INDEX;
    }

    csll_node_t *temp = head->head;
    uint32_t index = 1;
    while(temp != head->tail) {
        if(temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    if(temp->data == data) {
        return index;
    }

    return CSLL_INVALID_INDEX;
}
