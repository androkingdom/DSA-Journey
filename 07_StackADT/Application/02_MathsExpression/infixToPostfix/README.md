# Stacks Application: Infix to Postfix Conversion

## Overview

Infix expressions are the common arithmetic expressions where operators are placed between operands (e.g., `A + B`). However, this can be confusing for computers to evaluate due to operator precedence and parentheses. Postfix notation (also known as Reverse Polish Notation) eliminates the need for parentheses by placing operators after their operands (e.g., `AB+`). 

This README explains how to convert infix expressions to postfix notation using a stack data structure, making it easier for computers to evaluate expressions.

## Code Explanation

### Node Structure

We begin by defining a structure for the nodes in the stack, which holds character data and a pointer to the next node.

```c
typedef struct Node {
    char data;              // Character data
    struct Node* next;     // Pointer to the next node in the stack
} Node;
```

### Push Function

The `push` function adds a character to the top of the stack. It dynamically allocates memory for a new node and links it to the previous top.

```c
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
```

### Pop Function

The `pop` function removes a character from the top of the stack and returns it. It checks if the stack is empty before trying to remove an element.

```c
char pop(Node** top) {
    if (!(*top)) { // Check if the stack is empty
        printf("Stack is empty\n");
        return '\0'; // Return null character if empty
    }
    char chara = (*top)->data; // Get the data from the top node
    (*top) = (*top)->next; // Move the top pointer to the next node
    return chara; // Return the popped character
}
```

### Operator Check and Precedence Functions

To facilitate the conversion, we need functions to check if a character is an operator and to determine the precedence of operators.

```c
int isOp(char op) {
    return (op == '+' || op == '-' || op == '/' || op == '*') ? 1 : 0; // Check if it is an operator
}

int precedence(char c) {
    if (c == '/' || c == '*') {
        return 2; // Higher precedence
    } else if (c == '-' || c == '+') {
        return 1; // Lower precedence
    }
    return 0; // Return 0 for non-operators
}
```

### Infix to Postfix Conversion

The main function for converting infix to postfix notation iterates through the infix expression. It uses a stack to handle operators and ensures correct precedence.

```c
Node* infixToPostfix(char* exp) {
    Node* operator = NULL; // Stack for operators
    Node* postfix = NULL; // Stack for the postfix expression
    int i = 0; // Index for traversing the expression

    // Iterate through each character in the infix expression
    while (exp[i] != '\0') {
        if (!isOp(exp[i])) { // If the character is not an operator
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
```

### Main Function

The `main` function reads an infix expression from user input, converts it to postfix notation, and displays the result.

```c
int main() {
    char infix[100]; // Array to hold the input infix expression
    printf("Enter an expression: ");
    scanf("%s", &infix); // Read the infix expression from user input

    Node* try = infixToPostfix(infix); // Convert infix to postfix
    showStack(&try); // Display the resulting postfix expression

    return 0; // Return success
}
```

## Conclusion

This README provides a foundational understanding of how to use stacks for infix to postfix expression conversion. Understanding these concepts will help beginners grasp how to manage operator precedence and simplify expression evaluations in programming. 