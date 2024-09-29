#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
    struct Node* prev;     // Pointer to the previous node
};

// Function to traverse and print the doubly linked list
void travel(struct Node* head) {
    struct Node* ptrFor = head; // Pointer for forward traversal
    struct Node* ptrBack = NULL; // Pointer for backward traversal

    // Traverse forward to print the list
    while (ptrFor != NULL) {
        printf("%d\t", ptrFor->data); // Print current node's data
        ptrBack = ptrFor; // Update ptrBack to the current node
        ptrFor = ptrFor->next; // Move to the next node
    }

    // Now ptrBack points to the last node, traverse backward
    while (ptrBack != NULL) {
        printf("%d\t", ptrBack->data); // Print current node's data
        ptrBack = ptrBack->prev; // Move to the previous node
    }

    printf("\n"); // Newline after backward traversal
}

// Example usage
int main() {
    // Create nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 31;
    head->next = second;
    head->prev = NULL;

    second->data = 32;
    second->next = third;
    second->prev = head;

    third->data = 43;
    third->next = NULL;
    third->prev = second;

    // Call travel function
    travel(head);

    // Free allocated memory
    free(third);
    free(second);
    free(head);

    return 0; // Indicate successful completion
}