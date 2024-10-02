#include <stdio.h> 
#include <stdlib.h>

// Define the stack structure
struct stack {
    int max_size; // Maximum size of the stack
    int top;      // Index of the top element
    int* ptr;     // Pointer to dynamically allocated memory for stack elements
};

// Function to initialize the stack
int stackInit(struct stack* Stack, int maxSize) {
    // Allocate memory for the stack elements
    Stack->ptr = (int *)malloc(maxSize * sizeof(int));
    
    // Check if memory allocation was successful
    if (Stack->ptr == NULL) {
        printf("Error: Memory Not Allocated\n"); // Corrected spelling
        return -1; // Return -1 on failure
    }
    
    // Set the maximum size and initialize the top index
    Stack->max_size = maxSize;
    Stack->top = -1; // Stack is initially empty
    return 1; // Return 1 on success
}

// Function to check if the stack is empty
int isEmpty(struct stack* s) {
    // Return 1 if empty, otherwise return 0
    return (s->top <= -1) ? 1 : 0;
}

// Function to check if the stack is full
int isFull(struct stack* s) {
    // Return 1 if full, otherwise return 0
    return (s->top >= s->max_size - 1) ? 1 : 0;
}

// Function to push an element onto the stack
void push(struct stack* s, int number) {
    // Check if the stack is not full
    if (!isFull(s)) {
        // Increment top and assign the number to the stack
        s->ptr[++(s->top)] = number;
    } else {
        // Print error message if full
        printf("Error: Stack is full\n");
    }
}

// Function to pop an element from the stack
int pop(struct stack* s) {
    // Check if the stack is not empty
    if (!isEmpty(s)) {
        // Return the top element and decrement the top index
        return s->ptr[(s->top)--];
    } else {
        printf("Error: Stack is empty\n"); // Added error message
        return -1; // Return -1 if the stack is empty
    }
}

// Function to peek at an element in the stack without modifying it
int peek(struct stack* s, int index) {
    // Check if the index is within bounds
    if (index < 0 || index > s->top) {
        printf("Error: Out Of Bound\n"); // Print error if index is invalid
        return -1; // Return -1 if out of bounds
    } else {
        return s->ptr[index]; // Return the element at the specified index
    }
}

// Function to display the current contents of the stack
void showStack(struct stack* s) {
    // Check if the stack is not empty
    if (!isEmpty(s)) {
        printf("Stack Contains:\n");
        int i = s->top; // Start from the top of the stack
        // Print each element from top to bottom
        while (i >= 0) {
            printf("%d\n", s->ptr[i]);
            i--;
        }
    } else {
        printf("Stack is empty\n"); // Print message if stack is empty
    }
}

// Function to free the memory allocated for the stack
void destruction(struct stack* s) {
    if (s->ptr != NULL) { // Check if ptr is not NULL before freeing
        free(s->ptr); // Free the allocated memory
        s->ptr = NULL; // Set pointer to NULL to avoid dangling pointer
    }
}

// Main function to demonstrate stack operations
int main() {
    struct stack s1; // Declare a stack variable
    
    // Initialize the stack with a size of 4
    if (stackInit(&s1, 4) == -1) {
        return -1; // Exit if initialization fails
    }

    // Push elements onto the stack
    push(&s1, 64);
    push(&s1, 56);
    push(&s1, 6);
    showStack(&s1); // Display the stack contents

    pop(&s1); // Pop the top element from the stack
    showStack(&s1); // Display updated stack contents

    // Push more elements onto the stack
    push(&s1, 34);
    push(&s1, 23);
    showStack(&s1); // Show the final stack contents

    int index = 2; // Specify an index to peek
    printf(">> %d is at %dth place\n", peek(&s1, index), index); // Peek at the specified index

    destruction(&s1); // Clean up stack memory
    return 0; // Return 0 to indicate successful completion
}