#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "circular_sll.h"
#include "circular_dll.h"
#include <stdio.h>
#include <stdlib.h>

static void test_singly_linked_list(void);
static void test_doubly_linked_list(void);
static void test_circular_singly_linked_list(void);
static void test_circular_doubly_linked_list(void);

int main()
{
    printf("Singly Linked List Test\n");
    test_singly_linked_list();

    printf("Doubly Linked List Test\n");
    test_doubly_linked_list();

    printf("Circular Singly Linked List Test\n");
    test_circular_singly_linked_list();

    printf("Circular Doubly Linked List Test\n");
    test_circular_doubly_linked_list();

    return 0;
}

static void test_singly_linked_list(void)
{
    sll_t *sll = sll_create(0);
    sll_node_t *nth_node = NULL;

    for(int i = 0; i < 10; i++) {
        if(sll_insert_at_front(&sll, i) != SLL_SUCCESS) { printf("Failed to insert at front\n"); }
    }
    sll_print(sll);
    for(int i = 0; i < 10; i++) {
        if(sll_delete_at_front(&sll) != SLL_SUCCESS) { printf("Failed to delete at front\n"); }
    }
    sll_print(sll);

    for(int i = 0; i < 10; i++) {
        if (sll_insert_at_back(&sll, i) != SLL_SUCCESS) { printf("Failed to insert at back\n"); }
    }
    sll_print(sll);
    for(int i = 0; i < 10; i++) {
        if (sll_delete_at_back(&sll) != SLL_SUCCESS) { printf("Failed to delete at back\n"); }
    }
    sll_print(sll);

    for(int i = 1; i < 10; i++) {
        if(sll_insert_at_index(&sll, i, i*10) != SLL_SUCCESS) { printf("Failed to insert at index\n"); }
    }
    sll_print(sll);
    for(int i = 1; i < 10; i++) {
        if(sll_delete_at_index(&sll, 1) != SLL_SUCCESS) { printf("Failed to delete at index\n"); }
    }
    sll_print(sll);

    if (sll_destroy(&sll) != SLL_SUCCESS) { printf("Failed to destroy sll\n"); }
    if(sll == NULL) {
        printf("\nSLL destroyed successfully\n\n");
    }

    sll = sll_create(100);
    sll_insert_at_back(&sll, 200);
    sll_insert_at_back(&sll, 300);
    sll_insert_at_back(&sll, 400);
    sll_insert_at_back(&sll, 500);
    sll_insert_at_back(&sll, 600);
    sll_insert_at_back(&sll, 700);
    sll_insert_at_back(&sll, 800);
    sll_insert_at_back(&sll, 900);
    sll_insert_at_back(&sll, 1000);
    printf("\nGetting nth node data from end:\n");
    nth_node = sll_get_nth_node_from_end(&sll, 1); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 2); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 3); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 4); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 5); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 6); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 7); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 8); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 9); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    nth_node = sll_get_nth_node_from_end(&sll, 10);if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }
    // Testing with an index greater than the size of the list
    printf("\nTrying to get nth node data from end with index greater than size:\n");
    nth_node =sll_get_nth_node_from_end(&sll, 120); if(nth_node != NULL) { printf("%d ", nth_node->data); } else { printf("NULL "); }

    if (sll_destroy(&sll) != SLL_SUCCESS) { printf("Failed to destroy sll\n"); }
    if(sll == NULL) {
        printf("\nSLL destroyed successfully\n\n");
    }
}

static void test_doubly_linked_list(void)
{
    dll_t *dll = dll_create(0);

    for(int i = 0; i < 10; i++) {
        if(dll_insert_at_front(&dll, i) != DLL_SUCCESS) { printf("Error inserting at front\n"); }
    }
    dll_print(dll);
    for(int i = 0; i < 10; i++) {
        if (dll_delete_at_front(&dll) != DLL_SUCCESS) { printf("Error deleting at front\n"); }
    }
    dll_print(dll);

    for(int i = 0; i < 10; i++) {
        if (dll_insert_at_back(&dll, i) != DLL_SUCCESS) { printf("Error inserting at back\n"); }
    }
    dll_print(dll);
    for(int i = 0; i < 10; i++) {
        if (dll_delete_at_back(&dll) != DLL_SUCCESS) { printf("Error deleting at back\n"); }
    }
    dll_print(dll);

    for(int i = 1; i < 10; i++) {
        if(dll_insert_at_index(&dll, i, i*10) != DLL_SUCCESS) { printf("Error inserting at index\n"); }
    }
    dll_print(dll);
    for(int i = 1; i < 10; i++) {
        if(dll_delete_at_index(&dll, 1) != DLL_SUCCESS) { printf("Error deleting at index\n"); } 
    }
    dll_print(dll);

    if(dll_destroy(&dll) != DLL_SUCCESS) { printf("Error destroying dll\n"); }
    if(dll == NULL) {
        printf("DLL destroyed successfully\n");
    }
}

static void test_circular_singly_linked_list(void)
{
    csll_t *csll = csll_create(0);

    for(int i = 0; i < 10; i++) {
        if(csll_insert_at_front(&csll, i) != CSLL_SUCCESS) { printf("Error inserting at front\n"); }
    }
    csll_print(csll);
    for(int i = 0; i < 10; i++) {
        if (csll_delete_at_front(&csll) != CSLL_SUCCESS) { printf("Error deleting at front\n"); }
    }
    csll_print(csll);

    for(int i = 0; i < 10; i++) {
        if (csll_insert_at_back(&csll, i) != CSLL_SUCCESS) { printf("Error inserting at back\n"); }
    }
    csll_print(csll);
    for(int i = 0; i < 10; i++) {
        if (csll_delete_at_back(&csll) != CSLL_SUCCESS) { printf("Error deleting at back\n"); }
    }
    csll_print(csll);

    for(int i = 1; i < 10; i++) {
        if(csll_insert_at_index(&csll, i, i*10) != CSLL_SUCCESS) { printf("Error inserting at index\n"); }
    }
    csll_print(csll);
    for(int i = 1; i < 10; i++) {
        if(csll_delete_at_index(&csll, 1) != CSLL_SUCCESS) { printf("Error deleting at index\n"); } 
    }
    csll_print(csll);

    if(csll_destroy(&csll) != CSLL_SUCCESS) { printf("Error destroying csll\n"); }
    if(csll == NULL) {
        printf("CSLL destroyed successfully\n");
    }
}

static void test_circular_doubly_linked_list(void)
{
    cdll_t *cdll = cdll_create(0);

    for(int i = 0; i < 10; i++) {
        if(cdll_insert_at_front(&cdll, i) != CDLL_SUCCESS) { printf("Error inserting at front\n"); }
    }
    cdll_print(cdll);
    for(int i = 0; i < 10; i++) {
        if (cdll_delete_at_front(&cdll) != CDLL_SUCCESS) { printf("Error deleting at front\n"); }
    }
    cdll_print(cdll);

    for(int i = 0; i < 10; i++) {
        if (cdll_insert_at_back(&cdll, i) != CDLL_SUCCESS) { printf("Error inserting at back\n"); }
    }
    cdll_print(cdll);
    for(int i = 0; i < 10; i++) {
        if (cdll_delete_at_back(&cdll) != CDLL_SUCCESS) { printf("Error deleting at back\n"); }
    }
    cdll_print(cdll);

    for(int i = 1; i < 10; i++) {
        if(cdll_insert_at_index(&cdll, i, i*10) != CDLL_SUCCESS) { printf("Error inserting at index\n"); }
    }
    cdll_print(cdll);
    for(int i = 1; i < 10; i++) {
        if(cdll_delete_at_index(&cdll, 1) != CDLL_SUCCESS) { printf("Error deleting at index\n"); } 
    }
    cdll_print(cdll);

    if(cdll_destroy(&cdll) != CDLL_SUCCESS) { printf("Error destroying cdll\n"); }
    if(cdll == NULL) {
        printf("CDLL destroyed successfully\n");
    }
}
