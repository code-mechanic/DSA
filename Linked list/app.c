#include "linked_list.h"
#include <stdio.h>

int main()
{
    SLL_st list1;

    create_single_LL(&list1);
    for(int i = 0; i<10; i++)
        append_single_LL(&list1, i);
    print_single_LL(&list1);
    printf("Length of list = %d\n", list1.length);
    /*insert_single_LL(&list1, 100, 2);
    insert_single_LL(&list1, 101, 10);
    insert_single_LL(&list1, 102, -2);
    print_single_LL(&list1);*/
    pop_single_LL(&list1);
    pop_single_LL(&list1);
    print_single_LL(&list1);
    printf("Length of list = %d\n", list1.length);
    delete_single_LL(&list1);
    return 0;
}
