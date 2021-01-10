#include "linked_list.h"
#include <stdio.h>

int main()
{
    DLL_st list1;
    create_double_LL(&list1);
    for(int i=0; i<10; i++)
        append_double_LL(&list1, i);
    print_double_LL(&list1);

    /*pop_double_LL(&list1);
    pop_double_LL(&list1);
    print_double_LL(&list1);

    remove_double_LL(&list1, 3);
    remove_double_LL(&list1, 3);
    print_double_LL(&list1);*/

    insert_double_LL(&list1, 100, 0);
    insert_double_LL(&list1, 101, 10);
    insert_double_LL(&list1, 102, 11);
    insert_double_LL(&list1, 999, 50);
    insert_double_LL(&list1, 115, -50);
    print_double_LL(&list1);

    delete_double_LL(&list1);
    
    return 0;
}
