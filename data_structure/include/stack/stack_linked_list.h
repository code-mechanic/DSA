#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <stdint.h>

#define STACK_LINKED_LIST_MAX_SIZE (10U)

typedef struct stack_node_t_ {
    int value; // Value stored in the node
    struct stack_node_t_ *next; // Pointer to the next node in the stack
} StackNode;

typedef struct stack_linked_list_t_ {
    StackNode *top; // Pointer to the top node of the stack
    uint32_t size; // Current size of the stack
} StackLinkedList;

void stack_linked_list_init(StackLinkedList *stack);
/* similat to sll_insert_at_front */
void stack_linked_list_push(StackLinkedList *stack, int value);
/* similat to sll_delete_at_front */
int stack_linked_list_pop(StackLinkedList *stack);
int stack_linked_list_peek(StackLinkedList *stack);
int stack_linked_list_is_empty(StackLinkedList *stack);
int stack_linked_list_is_full(StackLinkedList *stack);
void stack_linked_list_clear(StackLinkedList *stack);

#endif // STACK_LINKED_LIST_H