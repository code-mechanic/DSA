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

void pop_double_LL(DLL_st *L_List)
{
    int flag = 0;
    if(L_List->head == NULL)
    {
        printf("Nothing to pop\n");
        return;
    }
    DLL_node_st *temp = L_List->head;
    DLL_node_st *temp2 = L_List->head;
    while(temp->next != NULL)
    {
        if(flag == 1)
        {
            temp2 = temp2->next;
        }
        temp = temp->next;
        flag = 1;
    }
    free(temp);
    temp2->next = NULL;
    L_List->length--;
}

void insert_double_LL(DLL_st *L_List, int x, int pos)
{
    if(pos > L_List->length)
    {
        printf("Specified position %d is greater than List length %d\n", pos, L_List->length);
        return;
    }
    else if(pos < 0)
    {
        printf("Specified position is less than zero\n");
        return;
    }

    DLL_node_st *newnode = (DLL_node_st*)malloc(sizeof(DLL_node_st));
    L_List->length++;
    newnode->data = x;
    
    if(pos == 0)
    {
        L_List->head->previous = newnode;
        newnode->previous = NULL;
        newnode->next = L_List->head;
        L_List->head = newnode;
    }
    else
    {
        DLL_node_st *temp1 = L_List->head;
        DLL_node_st *temp2 = L_List->head;
        for(int i=0; i<pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = newnode;
        newnode->next = temp2;
        temp2->previous = newnode;
        newnode->previous = temp1;
    }
}

void remove_double_LL(DLL_st *L_List, int pos)
{
    if(pos > L_List->length)
    {
        printf("Specified position %d is greater than List length %d\n", pos, L_List->length);
        return;
    }
    else if(pos < 0)
    {
        printf("Specified position is less than zero\n");
        return;
    }

    DLL_node_st *temp1 = L_List->head;
    DLL_node_st *temp2 = L_List->head;
    for(int i=0; i<pos-1; i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next->next;
    free(temp1->next);
    temp1->next = temp2;
    temp2->previous = temp1;
    L_List->length--;
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