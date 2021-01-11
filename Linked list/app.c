#include "linked_list.h"
#include <stdio.h>

int main()
{
    CSLL_st list1;

    create_circular_SLL(&list1);
    for(int i=1; i<=5; i++)
        append_circular_SLL(&list1, i*10);
    
    print_circular_SLL(&list1);
    delete_circular_SLL(&list1);
    
    return 0;
}
