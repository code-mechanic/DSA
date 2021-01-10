#include "linked_list.h"
#include <stdio.h>

int main()
{
    SLL_st list1;
    create_single_LL(&list1);
    for(int i=1; i<=5; i++)
        append_single_LL(&list1, i);
    print_single_LL(&list1);

    printf("\nmin = %d\nmax = %d\ntotal = %d\nlength = %d\n", list1.min, list1.max, list1.total, list1.length);
    append_single_LL(&list1, 10);
    print_single_LL(&list1);
    printf("\nmin = %d\nmax = %d\ntotal = %d\nlength = %d\n", list1.min, list1.max, list1.total, list1.length);
    insert_single_LL(&list1, 20, 3);
    print_single_LL(&list1);
    printf("\nmin = %d\nmax = %d\ntotal = %d\nlength = %d\n", list1.min, list1.max, list1.total, list1.length);
    pop_single_LL(&list1);
    print_single_LL(&list1);
    printf("\nmin = %d\nmax = %d\ntotal = %d\nlength = %d\n", list1.min, list1.max, list1.total, list1.length);
    remove_single_LL(&list1, 1);
    print_single_LL(&list1);
    printf("\nmin = %d\nmax = %d\ntotal = %d\nlength = %d\n", list1.min, list1.max, list1.total, list1.length);
    
    return 0;
}
