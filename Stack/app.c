#include "stack.h"
#include <stdio.h>

int main()
{
    stack_st stk1;

    create_stack(&stk1);
    for(int i=1; i<=10; i++)
        push_stack(&stk1, i*10);

    print_stack(&stk1);
    printf("length : %d\nTop : %d\n", stk1.length, stk1.top);

    delete_stack(&stk1);
    return 0;
}