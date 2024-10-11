#include <stdio.h> 
#include <stdlib.h>

// Define a structure for the nodes in the stack
typedef struct Node {
    char data;              // Character data
    struct Node* next;     // Pointer to the next node in the stack
} Node;

// Function to push a character onto the stack
void push(Node** top, char character) {
    Node* ptr = (Node*) malloc(sizeof(Node)); // Allocate memory for a new node
    if (ptr == NULL) { 
        printf("Memory allocation failed\n"); // Handle memory allocation failure
        return;
    }
    ptr->data = character; // Set the character data
    ptr->next = *top; // Link the new node to the previous top
    *top = ptr; // Update the top of the stack
}

// Function to pop a character from the stack
char pop(Node** top) {
    if (!(*top)) { // Check if the stack is empty
        printf("Stack is empty\n");
        return '\0'; // Return null character if empty
    }
    char chara = (*top)->data; // Get the data from the top node
    (*top) = (*top)->next; // Move the top pointer to the next node
    return chara; // Return the popped character
}

// Function to display the elements of the stack
void showStack(Node** top) {
    Node* ptr = *top; // Start from the top of the stack
    if (!ptr) { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }
    while (ptr != NULL) { // Traverse the stack
        printf("%c", ptr->data); // Print each character
        ptr = ptr->next; // Move to the next node
    }
    printf("\n"); // Print newline at the end
}

// Function to check if a character is an operator
int isOp(char op) {
    return (op == '+' || op == '-' || op == '/' || op == '*') ? 1 : 0; // Return 1 if it is an operator, else 0
}

// Function to determine the precedence of operators
int precedence(char c) {
    if (c == '/' || c == '*') {
        return 2; // Higher precedence
    } else if (c == '-' || c == '+') {
        return 1; // Lower precedence
    }
    return 0; // Return 0 for non-operators
}

// Function to reverse the order of nodes in a stack
Node* reverseNode(Node* top) {
    Node* new = NULL; // New stack for reversed nodes
    while (top != NULL) { // Traverse the original stack
        push(&new, top->data); // Push each element onto the new stack
        top = top->next; // Move to the next node
    }
    return new; // Return the reversed stack
}

// Function to convert an infix expression to postfix notation
Node* infixToPostfix(char* exp) {
    Node* operator = NULL; // Stack for operators
    Node* postfix = NULL; // Stack for the postfix expression
    int i = 0; // Index for traversing the expression

    // Iterate through each character in the infix expression
    while (exp[i] != '\0') {
        if (!isOp(exp[i])) { // If the character is not an operator (operand)
            push(&postfix, exp[i]); // Push it onto the postfix stack
        } else {
            // Pop operators from the stack to the postfix stack if they have greater or equal precedence
            while (operator != NULL && precedence(exp[i]) <= precedence(operator->data)) {
                char popped = pop(&operator); // Pop from operator stack
                push(&postfix, popped); // Push popped operator onto postfix stack
            }
            push(&operator, exp[i]); // Push the current operator onto the operator stack
        }
        i++; // Move to the next character
    }

    // Pop all remaining operators from the stack to the postfix stack
    while (operator != NULL) {
        char popped = pop(&operator); // Pop from operator stack
        push(&postfix, popped); // Push popped operator onto postfix stack
    }
    
    Node* postfixed = reverseNode(postfix); // Reverse the postfix stack for correct order
    return postfixed; // Return the postfix expression
}

// Main function to run the program
int main() {
    char infix[100]; // Array to hold the input infix expression
    printf("Enter a expression: ");
    scanf("%s", &infix); // Read the infix expression from user input

    Node* try = infixToPostfix(infix); // Convert infix to postfix
    showStack(&try); // Display the resulting postfix expression

    return 0; // Return success
}
