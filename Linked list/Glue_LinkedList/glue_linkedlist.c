#include "glue_linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/* -------------------------------- PRIVATE --------------------------------- */
/* -------------------------------- PUBLIC ---------------------------------- */
void List_Init(List_t *list, unsigned int offset)
{
  list->Head = NULL;
  list->Offset = offset;
  list->Count = 0;
}

/*
 * NOTE: List is assumed to be a circular double linked list. 
 */
void List_Add(List_t *list, Glue_t *glnode)
{
  /* For safty purpose members of Glue_t is again initializing to NULL */
  glnode->Left = NULL;
  glnode->Right = NULL;
  
    list->Count++;
  /* Condition for adding glnode at first position */
  if(list->Head == NULL)
  {
    list->Head = glnode;
    return;
  }
  
  /* Condition for adding glnode at Second position */
  if(list->Head->Right == NULL)
  {
    list->Head->Right = glnode;
    glnode->Left = list->Head;
  }
  else
  {
    /* Insert operation for rest of glnode */
    Glue_t *Temp = list->Head->Left;
    glnode->Left = list->Head->Left;
    Temp->Right = glnode;
  }
  
  /* glnode's right links to Head while Head left links to glonde */
  glnode->Right = list->Head;
  list->Head->Left = glnode;
}

/*
 * NOTE: List is assumed to be a circular double linked list. 
 */
void List_Remove(List_t *list, Glue_t *glnode)
{
  list->Count--;
  if(list->Head == glnode)
  {
    list->Head = list->Head->Right;
  }
  glnode->Left->Right = glnode->Right;
  glnode->Right->Left = glnode->Left;
  glnode->Right = NULL;
  glnode->Left = NULL;
}