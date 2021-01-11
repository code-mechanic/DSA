#ifndef _CIRCULAR_SLL_H_
#define _CIRCULAR_SLL_H_

typedef struct CSnode_s
{
    int data;
    struct CSnode_s *next;
}CSLL_node_st;

typedef struct
{
    unsigned int length;
    int total;
    CSLL_node_st *head;
}CSLL_st;

void create_circular_SLL(CSLL_st *L_List);
void append_circular_SLL(CSLL_st *L_List, int x);
void print_circular_SLL(CSLL_st *L_List);
void delete_circular_SLL(CSLL_st *L_List);

#endif