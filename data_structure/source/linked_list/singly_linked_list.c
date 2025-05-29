#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//==============================================================================
//                             Basic operations
//==============================================================================

sll_t *sll_create(uint32_t data)
{
    /* Allocate memory for the sll_t struct */
    sll_t *sll = (sll_t *) malloc(sizeof(sll_t));
    if(sll == NULL) {
        return NULL;
    }

    /* Allocate memory for the sll_node_t struct */
    sll->head = (sll_node_t *) malloc(sizeof(sll_node_t));
    if(sll->head == NULL) {
        free(sll);
        return NULL;
    }

    sll->head->data = data;
    sll->head->next = NULL;
    sll->size = 1;
    return sll;
}

sll_status_t sll_destroy(sll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    /* Free the memory allocated for the sll_t struct and sll_node_t struct */
    sll_node_t *temp = (*list_ref)->head;
    while (temp != NULL)
    {
        sll_node_t *next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list_ref);
    *list_ref = NULL;
    return SLL_SUCCESS;
}

sll_status_t sll_insert_at_front(sll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    /* Allocate memory for the sll_node_t struct */
    sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));
    if (new_node == NULL) {
        return SLL_FAILURE;
    }
    new_node->data = data;

    /* Insert head node to next of new node */
    new_node->next = (*list_ref)->head;

    /* Make new node as the head node */
    (*list_ref)->head = new_node;
    (*list_ref)->size++;

    return SLL_SUCCESS;
}

sll_status_t sll_insert_at_back(sll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    /* Allocate memory for the sll_node_t struct */
    sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));
    if(new_node == NULL) {
        return SLL_FAILURE;
    }
    new_node->data = data;
    new_node->next = NULL;

    /* Find the last node */
    sll_node_t *temp = (*list_ref)->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /* Insert the new node */
    temp->next = new_node;
    (*list_ref)->size++;

    return SLL_SUCCESS;
}

sll_status_t sll_insert_at_index(sll_t **list_ref, uint32_t index, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    if(index > (*list_ref)->size || index < 1) {
        /* Index should not be greater than size and one-index based */
        return SLL_FAILURE;
    }

    if(index == 1) {
        return sll_insert_at_front(list_ref, data);
    } else {
        /* Allocate memory for the sll_node_t struct */
        sll_node_t *new_node = (sll_node_t *) malloc(sizeof(sll_node_t));
        if(new_node == NULL) {
            return SLL_FAILURE;
        }
        new_node->data = data;
        new_node->next = NULL;

        /* Example logic if index is other than 1:
        *
        * Initial state:
        * head -> [10|*] -> [11|*] -> [12|*] -> [13|NULL]
        * 
        * new node [14|NULL] at index 3
        * 
        *                idx:1     idx:2     idx:3     idx:4
        *        head -> [10|*] -> [11|*] -> [12|*] -> [13|NULL]
        * step1:           temp -> [11|*]
        * step2:                   [14|*] -> [12|*]
        * step3:                   [11|*] -> [14|*] -> [12|*]
        * 
        */
        sll_node_t *temp = (*list_ref)->head;
        
        /*
        * head_pos is assigned to 1 becasue index is one-index based and already
        * head points to the first node and Find the node at the index - 1
        */
        for (uint32_t head_pos = 1; head_pos < index - 1; head_pos++)
        {
            temp = temp->next;
        }

        /* Insert the new node */
        new_node->next = temp->next;
        temp->next = new_node;
    }

    (*list_ref)->size++;
    return SLL_SUCCESS;
}

sll_status_t sll_delete_at_front(sll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    sll_node_t *temp = (*list_ref)->head;
    (*list_ref)->head = temp->next;
    free(temp);
    (*list_ref)->size--;
    return SLL_SUCCESS;
}

sll_status_t sll_delete_at_back(sll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    /* Check if the list has only one node */
    if((*list_ref)->head->next == NULL) {
        return sll_delete_at_front(list_ref);
    }

    /* Delete the last node */
    sll_node_t *temp = (*list_ref)->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    (*list_ref)->size--;
    return SLL_SUCCESS;
}

sll_status_t sll_delete_at_index(sll_t **list_ref, uint32_t index)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    if(index > (*list_ref)->size || index < 1) {
        /* Index should not be greater than size and one-index based */
        return SLL_FAILURE;
    }

    /* Delete the node at the index */
    if(index == 1) {
        return sll_delete_at_front(list_ref);
    } else {
        /* Example logic if index is other than 1:
        *
        * Initial state:
        * head -> [10|*] -> [11|*] -> [12|*] -> [14|*] -> [13|NULL]
        * 
        * delete node at index 4, [14|*]
        * 
        *                idx:1     idx:2     idx:3     idx:4     idx:5
        *        head -> [10|*] -> [11|*] -> [12|*] -> [14|*] -> [13|NULL]
        * step1:                     temp -> [12|*]
        * step2:                        delete_node -> [14|*]
        * step3:                             [12|*] -> [13|NULL]
        * 
        */
        sll_node_t *temp = (*list_ref)->head;

        /*
        * head_pos is assigned to 1 becasue index is one-index based and already
        * head points to the first node and Find the node at the index - 1
        */
        for (uint32_t head_pos = 1; head_pos < index - 1; head_pos++)
        {
            temp = temp->next;
        }
        sll_node_t *delete_node = temp->next;
        temp->next = delete_node->next;
        free(delete_node);
    }
    (*list_ref)->size--;
    return SLL_SUCCESS;
}

sll_status_t sll_delete_by_value(sll_t **list_ref, uint32_t data)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    /* Find the index of the data */
    uint32_t index = sll_search(*list_ref, data);
    if(index == SLL_INVALID_INDEX) {
        return SLL_FAILURE;
    }

    /* Delete the node at the index */
    return sll_delete_at_index(list_ref, index);
}

sll_status_t sll_delete_node(sll_t **list_ref, sll_node_t *node)
{
    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    if(node == NULL) {
        /* Node to be deleted should not be NULL */
        return SLL_FAILURE;
    }

    sll_node_t *temp = node->next;
    if(temp == NULL) {
        /* If the node to be deleted is the last node, delete it */
        return sll_delete_at_back(list_ref);
    } else {
        /* Copy the data from the next node to the current node and delete the next node */
        node->data = temp->data;
        node->next = temp->next;
        free(temp);
        (*list_ref)->size--;
        return SLL_SUCCESS;
    }
}
//==============================================================================
//                            Traversal operations
//==============================================================================

sll_status_t sll_print(sll_t *list)
{
    /* Input argument check */
    if(list == NULL) {
        return SLL_FAILURE;
    }

    sll_node_t *temp = list->head;
    while (temp != NULL)
    {
        printf("%d ", (int) temp->data);
        temp = temp->next;
    }
    printf("\n");
    return SLL_SUCCESS;
}

sll_node_t *sll_get_nth_node_from_end(sll_t **list_ref, uint32_t nth_node)
{
    /*
     * This funciton is implemented using two-pointer technique and it will not
     * use size member of the sll_t struct.
     */

    /* Input argument check */
    if(list_ref == NULL) {
        return NULL;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return NULL;
    }

    sll_node_t *slow_ptr = (*list_ref)->head;
    sll_node_t *fast_ptr = (*list_ref)->head;

    /*
     * Move the fast pointer nth_node times ahead of the slow pointer.
     * This will ensure that when the fast pointer reaches the end of the list,
     * the slow pointer will be at the nth node from the end.
     */
    for(uint32_t count = 1; count < nth_node; count++) {
        if(fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
        }
    }

    if(fast_ptr == NULL) {
        /* If the fast pointer is NULL, it means the list has less than nth_node elements */
        return NULL;
    }

    /*
     * Move both pointers at the same pace until the fast pointer reaches the end of the list.
     * When the fast pointer reaches NULL, the slow pointer will be at the nth node from the end.
     */
    while(fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    return slow_ptr;
}

uint32_t sll_detect_loop(sll_t **list_ref)
{
    /*
     * This funciton is implemented using two-pointer technique and it will not
     * use size member of the sll_t struct.
     */

    /* Input argument check */
    if(list_ref == NULL) {
        return SLL_FAILURE;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return SLL_FAILURE;
    }

    sll_node_t *slow_ptr = (*list_ref)->head;
    sll_node_t *fast_ptr = (*list_ref)->head;

    /*
     * Move the slow pointer one step at a time and the fast pointer two steps at a time.
     * If there is a loop, the fast pointer will eventually meet the slow pointer.
     */
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr) {
            return SLL_SUCCESS;
        }
    }
    return SLL_FAILURE;
}

sll_node_t *sll_detect_and_find_first_node_of_loop(sll_t **list_ref)
{
    /*
     * This funciton is implemented using two-pointer technique and it will not
     * use size member of the sll_t struct.
     */

    /* Input argument check */
    if(list_ref == NULL) {
        return NULL;
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return NULL;
    }

    sll_node_t *slow_ptr = (*list_ref)->head;
    sll_node_t *fast_ptr = (*list_ref)->head;

    /*
     * Move the slow pointer one step at a time and the fast pointer two steps at a time.
     * If there is a loop, the fast pointer will eventually meet the slow pointer.
     */
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr) {
            /* Loop detected, now find the first node of the loop. first node can
             * be found by moving slow pointer to the head and moving both pointers
             * one step at a time until they meet again.
             */
            slow_ptr = (*list_ref)->head;
            while(slow_ptr != fast_ptr) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
            return slow_ptr; // First node of the loop
        }
    }
    return NULL; // No loop found
}

uint32_t sll_detect_and_find_length_of_loop(sll_t **list_ref)
{
    /*
     * This funciton is implemented using two-pointer technique and it will not
     * use size member of the sll_t struct.
     */

    /* Input argument check */
    if(list_ref == NULL) {
        return 0; // No loop found
    }

    if((*list_ref)->head == NULL) {
        /* 
         * This scenario will never occur if properly created by sll_create().
         * Use sll_destroy() followed by sll_create(). 
         */
        return 0; // No loop found
    }

    sll_node_t *slow_ptr = (*list_ref)->head;
    sll_node_t *fast_ptr = (*list_ref)->head;

    /*
     * Move the slow pointer one step at a time and the fast pointer two steps at a time.
     * If there is a loop, the fast pointer will eventually meet the slow pointer.
     */
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr) {
            // Loop detected, now find the length of the loop
            uint32_t length = 1;
            sll_node_t *temp = slow_ptr;
            while(temp->next != slow_ptr) {
                temp = temp->next;
                length++;
            }
            return length; // Length of the loop
        }
    }
    return 0; // No loop found
}

sll_status_t sll_reverse_iterative(sll_t **list_ref)
{
    /* Input argument check */
    if(list_ref == NULL || *list_ref == NULL || (*list_ref)->head == NULL) {
        return SLL_FAILURE;
    }

    sll_node_t *prev = NULL;
    sll_node_t *current = (*list_ref)->head;
    sll_node_t *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev pointer to current pointer
        current = next;       // Move current pointer to the next node
    }

    (*list_ref)->head = prev; // Update the head to the new first node
    return SLL_SUCCESS;
}

uint32_t sll_find_middle_node(sll_t **list_ref)
{
    /*
     * This funciton is implemented using two-pointer technique and it will not
     * use size member of the sll_t struct.
     */

    /* Input argument check */
    if(list_ref == NULL || *list_ref == NULL || (*list_ref)->head == NULL) {
        return 0;
    }

    sll_node_t *slow_ptr = (*list_ref)->head;
    sll_node_t *fast_ptr = (*list_ref)->head;

    /*
     * Use the two-pointer technique to find the middle node.
     * The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.
     * When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
     */
    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    /*
     * When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
     * If the list has an even number of nodes, the slow pointer will point to the second middle node.
     */
    return slow_ptr->data;
}

//==============================================================================
//                        Search and compare operations
//==============================================================================

uint32_t sll_search(sll_t *list, uint32_t data)
{
    if(list == NULL) {
        return SLL_INVALID_INDEX;
    }

    sll_node_t *temp = list->head;
    uint32_t index = 1;
    while (temp != NULL)
    {
        if(temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return SLL_INVALID_INDEX;
}
