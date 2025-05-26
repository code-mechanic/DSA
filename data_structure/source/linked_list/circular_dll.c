#include "circular_dll.h"
#include <stdio.h>
#include <stdlib.h>

cdll_t *cdll_create(uint32_t data)
{
    /* Allocate memory for the cdll_node_t struct */
    cdll_node_t *node = malloc(sizeof(cdll_node_t));
    if(node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = node;
    node->prev = node;

    /* Allocate memory for the cdll_t struct */
    cdll_t *cdll = malloc(sizeof(cdll_t));
    if(cdll == NULL) {
        free(node);
        return NULL;
    }
    cdll->head = node;
    cdll->tail = node;
    cdll->size = 1;

    return cdll;
}

cdll_status_t cdll_destroy(cdll_t **list_ref)
{
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    cdll_node_t *temp = (*list_ref)->head;
    while(temp != (*list_ref)->tail) {
        cdll_node_t *next = temp->next;
        free(temp);
        temp = next;
    }
    free(temp);
    free(*list_ref);
    *list_ref = NULL;

    return CDLL_SUCCESS;
}

cdll_status_t cdll_insert_at_front(cdll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    cdll_node_t *node = malloc(sizeof(cdll_node_t));
    if(node == NULL) {
        return CDLL_FAILURE;
    }

    node->data = data;
    node->next = (*list_ref)->head;
    node->prev = (*list_ref)->tail;
    (*list_ref)->head->prev = node;
    (*list_ref)->tail->next = node;
    (*list_ref)->head = node;
    (*list_ref)->size++;

    return CDLL_SUCCESS;
}

cdll_status_t cdll_insert_at_back(cdll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    if((*list_ref)->tail == (*list_ref)->head) {
        return cdll_insert_at_front(list_ref, data);
    } else {
        cdll_node_t *node = malloc(sizeof(cdll_node_t));
        if(node == NULL) {
            return CDLL_FAILURE;
        }
        node->data = data;
        node->next = (*list_ref)->head;
        node->prev = (*list_ref)->tail;
        (*list_ref)->tail->next = node;
        (*list_ref)->tail = node;
        (*list_ref)->size++;
        return CDLL_SUCCESS;
    }
}

cdll_status_t cdll_insert_at_index(cdll_t **list_ref, uint32_t index, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    if(index > (*list_ref)->size) {
        return CDLL_INVALID_INDEX;
    }

    if(index == 1) {
        return cdll_insert_at_front(list_ref, data);
    } else {
        cdll_node_t *temp = (*list_ref)->head;
        /*
         * `i` is assigned to 1 becasue index is one-index based and already
         * head points to the first node and Find the node at the index - 1
         */
        for(uint32_t i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        cdll_node_t *node = malloc(sizeof(cdll_node_t));
        if(node == NULL) {
            return CDLL_FAILURE;
        }
        node->data = data;
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        (*list_ref)->size++;
        return CDLL_SUCCESS;
    }
}

cdll_status_t cdll_delete_at_front(cdll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    cdll_node_t *delete_node = (*list_ref)->head;
    (*list_ref)->head = (*list_ref)->head->next;
    (*list_ref)->head->prev = (*list_ref)->tail;
    (*list_ref)->tail->next = (*list_ref)->head;
    free(delete_node);
    (*list_ref)->size--;
    return CDLL_SUCCESS;
}

cdll_status_t cdll_delete_at_back(cdll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    cdll_node_t *delete_node = (*list_ref)->tail;
    (*list_ref)->tail = (*list_ref)->tail->prev;
    (*list_ref)->tail->next = (*list_ref)->head;
    (*list_ref)->head->prev = (*list_ref)->tail;
    free(delete_node);
    (*list_ref)->size--;
    return CDLL_SUCCESS;
}

cdll_status_t cdll_delete_at_index(cdll_t **list_ref, uint32_t index)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    if(index > (*list_ref)->size) {
        return CDLL_INVALID_INDEX;
    }

    if(index == 1) {
        return cdll_delete_at_front(list_ref);
    } else if(index == (*list_ref)->size) {
        return cdll_delete_at_back(list_ref);
    } else {
        cdll_node_t *temp = (*list_ref)->head;
        /*
         * `i` is assigned to 1 becasue index is one-index based and already
         * head points to the first node and Find the node at the index - 1
         */
        for(uint32_t i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        cdll_node_t *delete_node = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(delete_node);
        (*list_ref)->size--;
        return CDLL_SUCCESS;
    }
}

cdll_status_t cdll_delete_by_value(cdll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return CDLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by cdll_create().
         * Use cdll_destroy() followed by cdll_create(). 
         */
        return CDLL_FAILURE;
    }

    uint32_t index = cdll_search(*list_ref, data);
    if(index == CDLL_INVALID_INDEX) {
        return CDLL_FAILURE;
    }

    return cdll_delete_at_index(list_ref, index);
}

cdll_status_t cdll_print(cdll_t *head)
{
    /* Input argument check */
    if(head == NULL) {
        return CDLL_FAILURE;
    }

    cdll_node_t *temp = head->head;
    for(uint32_t i = 0; i < head->size; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return CDLL_SUCCESS;
}

uint32_t cdll_search(cdll_t *head, uint32_t data)
{
    /* Input argument check */
    if(head == NULL) {
        return CDLL_INVALID_INDEX;
    }

    cdll_node_t *temp = head->head;
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

    return CDLL_INVALID_INDEX;
}