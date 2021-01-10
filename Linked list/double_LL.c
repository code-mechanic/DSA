#include "double_LL.h"
#include <stdio.h>
#include <stdlib.h>

void create_double_LL(DLL_st *L_List)
{
    L_List->length = 0;
    L_List->head = NULL;
}

void append_double_LL(DLL_st *L_List, int x)
{
    DLL_node_st *newnode = (DLL_node_st*)malloc(sizeof(DLL_node_st));
    L_List->length++;
    newnode->data = x;
    newnode->next = NULL;

    if(L_List->head == NULL)
    {
        L_List->head = newnode;
        newnode->previous = NULL;
        return;
    }

    DLL_node_st *temp = L_List->head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->previous = temp;
}

void print_double_LL(DLL_st *L_List)
{
    DLL_node_st *temp = L_List->head;
    printf("Forward printing\n");
    while(temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\nBackward printing\n",temp->data);
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->previous;     
    }
    printf("\n");
}

void delete_double_LL(DLL_st *L_List)
{
    DLL_node_st *temp = L_List->head;
    while((L_List->head) != NULL)
    {
        printf("Deleting : %d\n", L_List->head->data);
        (L_List->head) = L_List->head->next;
        free(temp);
        temp = (L_List->head);
    }
    if((L_List->head) == NULL)
        printf("Deleting success\n");

    L_List->length = 0;
}