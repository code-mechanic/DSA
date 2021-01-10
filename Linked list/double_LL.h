#ifndef _DOUBLE_LL_H
#define _DOUBLE_LL_H

typedef struct Dnode_s
{
    int data;
    struct Dnode_s *previous;
    struct Dnode_s *next;
} DLL_node_st;

typedef struct
{
    unsigned int length;
    DLL_node_st *head;
}DLL_st;

void create_double_LL(DLL_st *L_List);
void append_double_LL(DLL_st *L_List, int x);
void pop_double_LL(DLL_st *L_List);
void print_double_LL(DLL_st *L_List);
void delete_double_LL(DLL_st *L_List);

#endif