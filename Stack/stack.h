#ifndef _STACK_H_
#define _STACK_H_

typedef struct s_node
{
    int data;
    struct s_node *next;
}s_node_st;

typedef struct
{
    s_node_st *head;
    unsigned int length;
    int top;
}stack_st;

void create_stack(stack_st *stack);
void push_stack(stack_st *stack, int x);
void pop_stack(stack_st *stack);
void print_stack(stack_st *stack);
void delete_stack(stack_st *stack);

#endif