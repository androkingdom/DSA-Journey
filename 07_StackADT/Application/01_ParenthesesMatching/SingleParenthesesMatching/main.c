#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Check if the stack is empty
int isEmpty(Node** top) {
    return *top == NULL;
}

// Push a character onto the stack
void push(Node** top, char data) {
    Node* ptr = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    if (!ptr) {
        printf("Error: Memory Allocation Failed\n");
        return;
    }
    ptr->data = data;  // Store the character
    ptr->next = *top;  // Link the new node to the top
    *top = ptr;        // Update the top pointer
}

// Pop a character from the stack
char pop(Node** top) {
    if (isEmpty(top)) {
        return '\0';  // Return null character if the stack is empty
    }
    Node* ptr = *top;     // Get the top node
    *top = (*top)->next;  // Move the top pointer to the next node
    char popped = ptr->data; // Store the popped character
    free(ptr);           // Free the memory of the popped node
    return popped;       // Return the popped character
}

// Function to check if parentheses are balanced
int isParenMatch(char* exp) {
    Node* top = NULL;      // Initialize the stack

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(&top, '('); // Push '(' onto the stack
        } else if (exp[i] == ')') {
            char check = pop(&top); // Pop from the stack
            if (check == '\0') { // Check if the popped character is null
                return 0; // Unbalanced
            }
        }
    }

    int result = isEmpty(&top) ? 1 : 0; // Check if the stack is empty
    // Cleanup: Free remaining nodes in the stack
    while (!isEmpty(&top)) {
        pop(&top); // Free remaining nodes
    }

    return result; // Return the result
}

// Function to display the result
void showResult(int result) {
    if (result == 1) {
        printf("Parentheses are matching\n");
    } else {
        printf("Parentheses are unmatching\n");
    }
}

// Main function
int main() {
    char* exp = "8)*(9";  // Test expression with unbalanced parentheses
    char* exp2 = "(8+1*(32-32)*(93-32))-((41+23)-11)"; // Test expression with balanced parentheses

    int result = isParenMatch(exp);
    int result2 = isParenMatch(exp2);

    showResult(result);
    showResult(result2);

    return 0;
}