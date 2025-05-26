#include "stack_array.h"
#include "stack_linked_list.h"
#include <stdio.h>

static void test_stack_array(void);
static void test_stack_linked_list(void);

int main(void) {

    printf("Testing Stack Array Implementation:\n");
    test_stack_array();

    printf("\nTesting Stack Linked List Implementation:\n");
    test_stack_linked_list();

    return 0;
}

static void test_stack_array(void) {
    StackArray stack;
    stack_array_init(&stack);

    // Test pushing elements onto the stack
    for (int i = 0; i < 5; i++) {
        stack_array_push(&stack, i);
        printf("Pushed %d onto the stack.\n", i);
    }

    // Test peeking the top element
    int top_value = stack_array_peek(&stack);
    printf("Top value is: %d\n", top_value);

    // Test popping elements from the stack
    while (!stack_array_is_empty(&stack)) {
        int popped_value = stack_array_pop(&stack);
        printf("Popped %d from the stack.\n", popped_value);
    }

    // Test underflow condition
    int underflow_value = stack_array_pop(&stack);
    printf("Attempted to pop from empty stack, got: %d\n", underflow_value);

    // Test overflow condition
    for (uint32_t i = 0; i < STACK_ARRAY_MAX_SIZE + 2; i++) {
        stack_array_push(&stack, i);
        if (i < STACK_ARRAY_MAX_SIZE) {
            printf("Pushed %d onto the stack.\n", i);
        } else {
            printf("Attempted to push %d onto full stack.\n", i);
        }
    }

    // Test clearing the stack
    stack_array_clear(&stack);
    printf("Stack cleared.\n");
}

static void test_stack_linked_list(void) {
    StackLinkedList stack;
    stack_linked_list_init(&stack);

    // Test pushing elements onto the stack
    for (int i = 0; i < 5; i++) {
        stack_linked_list_push(&stack, i);
        printf("Pushed %d onto the stack.\n", i);
    }

    // Test peeking the top element
    int top_value = stack_linked_list_peek(&stack);
    printf("Top value is: %d\n", top_value);

    // Test popping elements from the stack
    while (!stack_linked_list_is_empty(&stack)) {
        int popped_value = stack_linked_list_pop(&stack);
        printf("Popped %d from the stack.\n", popped_value);
    }

    // Test underflow condition
    int underflow_value = stack_linked_list_pop(&stack);
    printf("Attempted to pop from empty stack, got: %d\n", underflow_value);

    // Test overflow condition
    for (uint32_t i = 0; i < STACK_ARRAY_MAX_SIZE + 2; i++) {
        stack_linked_list_push(&stack, i);
        if (i < STACK_ARRAY_MAX_SIZE) {
            printf("Pushed %d onto the stack.\n", i);
        } else {
            printf("Attempted to push %d onto full stack.\n", i);
        }
    }

    // Test clearing the stack
    stack_linked_list_clear(&stack);
    printf("Stack cleared.\n");
}