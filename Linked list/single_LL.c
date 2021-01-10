#include <stdio.h>
#include <stdlib.h>
#include "single_LL.h"

void findMinMax(SLL_st *L_List)
{
    SLL_node_st *temp = L_List->head;
    int max_data = temp->data;
    int min_data = temp->data;
    while(temp != NULL)
    {
        if(temp->data > max_data) max_data = temp->data;
        if(temp->data < min_data) min_data = temp->data;
        temp = temp->next;
    }
    L_List->max = max_data;
    L_List->min = min_data;
}

void create_single_LL(SLL_st *L_list)
{
    L_list->length = 0;
    L_list->max = 0;
    L_list->min = INT_MAX;
    L_list->total = 0;
    (L_list->head) = NULL;
}

void append_single_LL(SLL_st *L_List, int x)
{
    SLL_node_st *newnode = (SLL_node_st*)malloc(sizeof(SLL_node_st));
    L_List->length++;
    L_List->total += x; 
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
    findMinMax(L_List);
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
    L_List->total -= temp1->data;
    free(temp1);
    temp2->next = NULL;
    L_List->length--;
    findMinMax(L_List);
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
    L_List->total += x;
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
    findMinMax(L_List);
}

void remove_single_LL(SLL_st *L_List, int pos)
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

    if(L_List->head == NULL)
    {
        printf("Nothing to remove\n");
    }

    SLL_node_st *temp1 = L_List->head;
    SLL_node_st *temp2 = L_List->head;
    for(int i=0; i<pos-1; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next->next;
    L_List->total -= temp1->next->data;
    free(temp1->next);
    temp1->next = temp2;
    L_List->length--;
    findMinMax(L_List);
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
    L_List->total = 0;
    L_List->max = 0;
    L_List->min = 0;
}