#include <stdio.h>
#include <stdlib.h>

// Struct representing a node in the linked list
typedef struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node
} Node;

// Function to check if the stack is empty
int isEmpty(Node** top) {
    return *top == NULL;   // Return true if the top pointer is NULL
}

// Function to display the elements of the stack
void showStack(Node** top) {
    // Check if the stack is empty
    if (*top == NULL) {
        printf("Error: Stack is empty\n");
        return;
    }

    Node* ptr = *top;       // Start from the top of the stack
    printf("Stack Contains:\n");
    // Traverse the stack and print each element
    while (ptr != NULL) {
        printf("%d\n", ptr->data); // Print the data of the current node
        ptr = ptr->next;            // Move to the next node
    }
    printf("NULL\n\n");            // Indicate the end of the stack
}

// Function to push an element onto the stack
void push(Node** top, int number) {
    Node* ptr = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    if (ptr == NULL) {  // Check if memory allocation succeeded
        printf("Memory allocation failed\n");
        return; // Exit the function if allocation failed
    }
    ptr->data = number;       // Set the data for the new node
    ptr->next = *top;         // Link the new node to the current top
    *top = ptr;               // Update the top pointer to the new node
}

// Function to pop an element from the stack
Node* pop(Node** top) {
    // Check if the stack is empty
    if (isEmpty(top)) {
        printf("Error: Stack is empty\n");
        return NULL; // Return NULL if the stack is empty
    }
    Node* ptr = *top;         // Save the current top node
    *top = (*top)->next;      // Move the top pointer to the next node
    return ptr;               // Return the popped node
}

// Function to peek at an element at a given index in the stack
int peek(Node** top, int index) {
    Node* ptr = *top;         // Start from the top of the stack
    // Check if the stack is empty
    if (isEmpty(top)) {
        printf("Error: Stack is empty\n");
        return -1;           // Return -1 if the stack is empty
    } else {
        int i = 0;           // Initialize an index counter
        // Traverse the stack to find the element at the given index
        while (ptr != NULL) {
            if (index == i) { // Check if the current index matches the requested index
                return ptr->data; // Return the data of the node at the index
            } else {
                i++;           // Increment the index counter
                ptr = ptr->next; // Move to the next node
            }
        }
    }
    printf("Error: Invalid position\n");
    return -1;               // Return -1 if the index is invalid
}

int main() {
    Node* top = NULL;             // Initialize the top of the stack to NULL
    Node** topPtr = &top;         // Pointer to pointer for modifying top in functions 

    push(topPtr, 15);             // Push an element onto the stack
    showStack(topPtr);            // Display the current stack

    Node* poppedNode = pop(topPtr); // Pop the top element from the stack
    // Check if a node was popped successfully
    if (poppedNode != NULL) {
        printf("pop out element is %d\n", poppedNode->data); // Print the popped element
        free(poppedNode); // Free the memory after use
    }
    showStack(topPtr);            // Display the current stack

    // Push more elements onto the stack
    push(topPtr, 54);
    push(topPtr, 23);
    push(topPtr, 12);
    showStack(topPtr);            // Display the current stack

    int index = 2;                // Specify the index to peek
    printf("Element at index %d is %d\n", index, peek(topPtr, index)); // Peek at the specified index

    return 0;                     // Exit the program
}