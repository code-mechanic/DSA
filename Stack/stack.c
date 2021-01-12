#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void create_stack(stack_st *stack)
{
    stack->head = NULL;
    stack->length = 0;
    stack->top = 0;
}

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

void pop_stack(stack_st *stack)
{
    s_node_st *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->length--;
    stack->top = stack->head->data;
}

void print_stack(stack_st *stack)
{
    s_node_st *temp = stack->head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_stack(stack_st *stack)
{
    s_node_st *temp = stack->head;
    while(temp != NULL)
    {
        printf("deleting : %d\n",stack->head->data);
        stack->head = stack->head->next;
        free(temp);
        temp = stack->head;
    }    
    if(stack->head == NULL)
        printf("delete success\n");
}