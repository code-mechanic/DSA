#include "glue_linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/*---------------------------------- Macros ----------------------------------*/
#define MAX_ELEMENT                                                         (5U)

/*------------------------ Application data structure ------------------------*/
typedef struct{
  int X;
  int Y;
  Glue_t Glnode;
  Glue_t Glnode_Dist;
}Position_t; 

/*------------------- Function prototype for Application Data ----------------*/
void SetPosition(Position_t *Pos, int x, int y);
void Print_Pos(Position_t *ptr);

/*-------------------------------- Main function -----------------------------*/
int main(void)
{
  Position_t Pos[MAX_ELEMENT];
  int Idx;
  Position_t *ptr = NULL;
  
  /* Initialization of all members of application data */
  for(Idx = 0; Idx < MAX_ELEMENT; Idx++)
  {
    SetPosition(&Pos[Idx], Idx, Idx * 10);
  }
  
  /* Creating Two lists(Circular Doubly linked list) and initializing a list */
  List_t Pos_List;
  List_t Distance_List;
  List_Init(&Pos_List, OFFSET(Position_t, Glnode));
  List_Init(&Distance_List, OFFSET(Position_t, Glnode_Dist));
  
  /* Inserting a application data into list */
  List_Add(&Pos_List, &(Pos[0].Glnode));
  List_Add(&Pos_List, &(Pos[4].Glnode));
  List_Add(&Pos_List, &(Pos[3].Glnode));
  List_Add(&Pos_List, &(Pos[1].Glnode));
  List_Add(&Pos_List, &(Pos[2].Glnode));
  
  List_Add(&Distance_List, &(Pos[2].Glnode_Dist));
  List_Add(&Distance_List, &(Pos[3].Glnode_Dist));
  List_Add(&Distance_List, &(Pos[4].Glnode_Dist));
  List_Add(&Distance_List, &(Pos[0].Glnode_Dist));
  
  printf("Pos_List Count = %d\n", Pos_List.Count);
  printf("Distance_List Count = %d\n", Distance_List.Count);
  
  /* Printing of Linked list */
  printf("Pos_List entries:\n");
  ptr = NULL;
  ITERATE_LIST_BEGIN(&Pos_List, Position_t, ptr)
  {
    Print_Pos(ptr);
  }ITERATE_LIST_END;
  
  printf("Distance_List entries:\n");
  ptr = NULL;
  ITERATE_LIST_BEGIN(&Distance_List, Position_t, ptr)
  {
    Print_Pos(ptr);
  }ITERATE_LIST_END;
  
  /* Removing a node from the list */
  List_Remove(&Pos_List, &(Pos[0].Glnode));
  List_Remove(&Pos_List, &(Pos[3].Glnode));
  List_Remove(&Pos_List, &(Pos[2].Glnode));
  
  List_Remove(&Distance_List, &(Pos[2].Glnode_Dist));
  List_Remove(&Distance_List, &(Pos[3].Glnode_Dist));
  List_Remove(&Distance_List, &(Pos[0].Glnode_Dist));

  printf("Pos_List Count = %d\n", Pos_List.Count);
  printf("Distance_List Count = %d\n", Distance_List.Count);
 
  /* Printing of Linked list */
  printf("\nAfter the Removal\n");
  printf("Pos_List entries:\n");
  ptr = NULL;
  ITERATE_LIST_BEGIN(&Pos_List, Position_t, ptr)
  {
    Print_Pos(ptr);
  }ITERATE_LIST_END;
  
  printf("Distance_List entries:\n");
  ptr = NULL;
  ITERATE_LIST_BEGIN(&Distance_List, Position_t, ptr)
  {
    Print_Pos(ptr);
  }ITERATE_LIST_END;
  return 0;
}

/*------------------ Function definition for Application data ----------------*/
void SetPosition(Position_t *Pos, int x, int y)
{
  Pos->X = x;
  Pos->Y = y;
  (Pos->Glnode).Left = NULL;
  (Pos->Glnode).Right = NULL;
}

void Print_Pos(Position_t *ptr)
{
  printf("  X value = %d\n", ptr->X);
  printf("  Y value = %d\n", ptr->Y);
}