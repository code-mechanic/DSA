#ifndef _DOUBLE_LL_H
#define _DOUBLE_LL_H

typedef struct node_s
{
    int data;
    struct node_s *previous;
    struct node_s *next;
} DLL_node_st;

typedef struct
{
    unsigned int length;
    DLL_node_st *head;
}DLL_st;

void create_double_LL(DLL_st *L_List);
void append_doublr_LL(DLL_st *L_List, int x);

#endif