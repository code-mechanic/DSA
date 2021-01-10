#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "single_LL.h"

void create_single_LL(SLL_st *L_list)
{
    L_list->length = 0;
    (L_list->head) = NULL;
}

void append_single_LL(SLL_st *L_List, int x)
{
    SLL_node_st *newnode = (SLL_node_st*)malloc(sizeof(SLL_node_st));
    L_List->length++;
    newnode->data = x;
    newnode->next = NULL;

    if(L_List->head == NULL)
    {
        L_List->head = newnode;
        return;
    }

    SLL_node_st *temp = L_List->head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void pop_single_LL(SLL_st *L_List)
{
    SLL_node_st *temp1 = L_List->head;
    SLL_node_st *temp2 = L_List->head;
    int count = 0;
    while(temp1->next != NULL)
    {
        if(count == 1)
        {
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        count = 1;
    }
    free(temp1);
    temp2->next = NULL;
    L_List->length--;
}

void insert_single_LL(SLL_st *L_List, int x, int pos)
{
    if(pos > L_List->length)
    {
        printf("FATAL : Specified position %d is greater than List length %d\n", pos, L_List->length);
        return;
    }
    else if(pos < 0)
    {
        printf("FATAL : Specified position is less than 0\n");
        return;
    }

    SLL_node_st *newnode = (SLL_node_st*)malloc(sizeof(SLL_node_st));
    L_List->length++;
    newnode->data = x;

    if(L_List->head == NULL)
    {
        L_List->head = newnode;
        L_List->head->next = NULL;
        return;
    }
    else
    {
        SLL_node_st *temp1 = L_List->head;
        SLL_node_st *temp2 = L_List->head;
        for(int i=0; i<pos-1; i++)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2 = temp2->next;
        temp1->next = newnode;
        newnode->next = temp2;
    }
}

void print_single_LL(SLL_st *L_List)
{
    SLL_node_st *temp = L_List->head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_single_LL(SLL_st *L_List)
{
    SLL_node_st *temp = L_List->head;
    while(L_List->head != NULL)
    {
        printf("Deleting : %d\n", L_List->head->data);
        L_List->head = L_List->head->next;
        free(temp);
        temp = L_List->head;
    }
    L_List->length = 0;
}