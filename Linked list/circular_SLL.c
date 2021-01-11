#include <stdio.h>
#include <stdlib.h>
#include "circular_SLL.h"

void create_circular_SLL(CSLL_st *L_List)
{
    L_List->length = 0;
    L_List->total = 0;
    L_List->head = NULL;
}

void append_circular_SLL(CSLL_st *L_List, int x)
{
    CSLL_node_st *newnode = (CSLL_node_st*)malloc(sizeof(CSLL_node_st));
    L_List->length++;
    L_List->total += x;
    newnode->data = x;

    if((L_List->head) == NULL)
    {
        L_List->head = newnode;
        newnode->next = L_List->head; 
        return;
    }
    
    CSLL_node_st *temp = L_List->head;
    while(temp->next != L_List->head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = L_List->head;
}

void print_circular_SLL(CSLL_st *L_List)
{
    CSLL_node_st *temp = L_List->head;
    printf("%d ", temp->data);
    temp = temp->next;
    while(temp != L_List->head)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_circular_SLL(CSLL_st *L_List)
{
    CSLL_node_st *temp1 = L_List->head;
    CSLL_node_st *temp2 = L_List->head;
    temp1 = L_List->head->next;
    temp2 = L_List->head->next->next;
    while(temp2 != L_List->head)
    {
        printf("deleting : %d\n",temp1->data);
        free(temp1);
        temp1 = temp2;
        temp2 = temp2->next;
    }
    printf("deleting : %d\n",temp1->data);
    free(temp1);
    temp1 = temp2;
    printf("deleting : %d\n",temp1->data);
    free(temp1);
    L_List->length = 0;
    L_List->total = 0;
}