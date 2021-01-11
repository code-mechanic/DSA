#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push_stack(stack_st *stack, int x)
{
    s_node_st *newnode = (s_node_st*)malloc(sizeof(s_node_st));
    newnode->data = x;
    stack->length++;
    stack->top = x;

    if((stack->head) == NULL)
    {
        stack->head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = stack->head;
        stack->head = newnode;
    }
    
}
void pop_stack(stack_st *head);
void print_stack(stack_st *head);
void delete_stack(stack_st *head);