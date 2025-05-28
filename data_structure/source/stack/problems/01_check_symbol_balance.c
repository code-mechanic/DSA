#include "stack_linked_list.h"
#include <stdio.h>

static void check_symbol_balance(StackLinkedList *stack, const char *expression);

int main(void)
{
    StackLinkedList stack;
    stack_linked_list_init(&stack);

    check_symbol_balance(&stack, "((a + b) * (c - d))");
    check_symbol_balance(&stack, "((a + b) * (c - d)))");
    return 0;
}

static void check_symbol_balance(StackLinkedList *stack, const char *expression)
{
    char ch;
    for (int i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];
        if (ch == '(') {
            stack_linked_list_push(stack, ch);
        } else if (ch == ')') {
            // If we encounter a closing parenthesis, we check if the stack is empty
            // If it is empty, it means there is no matching opening parenthesis
            if (stack_linked_list_is_empty(stack)) {
                printf("Unbalanced parentheses\n");
                return;
            }
            stack_linked_list_pop(stack);
        }
    }

    // If the stack is empty after processing the expression, parentheses are balanced
    // If not, they are unbalanced
    if (stack_linked_list_is_empty(stack)) {
        printf("Balanced parentheses\n");
    } else {
        printf("Unbalanced parentheses\n");
    }
}