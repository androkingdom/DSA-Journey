# Stack Application: Multiple Parentheses Matching Problem

## Overview
This project demonstrates the use of a **stack** data structure to check if parentheses in a given expression are balanced. It supports three types of parentheses: `()`, `[]`, and `{}`. This code provides a simple yet efficient solution for validating balanced parentheses using the fundamental operations of a stack.

![Multiple Parentheses Matching](/07_StackADT/Application/01_ParenthesesMatching/image.png)

## Problem Explanation
The primary goal is to ensure every opening parenthesis has a corresponding closing parenthesis in the correct order. The algorithm uses a stack to keep track of opening parentheses and ensures they match the closing ones encountered as we iterate through the expression.

## Code Explanation
### Stack Structure
The code defines a `Node` structure to represent each element in the stack:
```c
typedef struct Node {
    char data;
    struct Node* next;
} Node;
```
Each `Node` contains a `data` field for storing characters and a `next` pointer to link nodes together.

### Stack Operations
The following operations are defined for the stack:
- **Push**: Adds an element to the top of the stack.
    ```c
    void push(Node** top, char data) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        if (!ptr) {
            printf("Error: Memory Allocation Failed\n");
            return;
        }
        ptr->data = data;
        ptr->next = *top;
        *top = ptr;
    }
    ```
- **Pop**: Removes and returns the top element from the stack. If the stack is empty, it returns `'\0'`.
    ```c
    char pop(Node** top) {
        if (isEmpty(top)) {
            return '\0';
        }
        Node* ptr = *top;
        *top = (*top)->next;
        char popped = ptr->data;
        free(ptr);
        return popped;
    }
    ```

### Checking for Balanced Parentheses
The function `isParenMatch` uses the stack to check if parentheses in the expression are balanced:
```c
int isParenMatch(char* exp) {
    Node* top = NULL;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(&top, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            int check = pop(&top);
            if ((exp[i] == ')' && check != '(') || 
                (exp[i] == ']' && check != '[') || 
                (exp[i] == '}' && check != '{')) {
                return 0; // Mismatched parentheses
            }
        }
    }
    int result = isEmpty(&top) ? 1 : 0;
    while (!isEmpty(&top)) {
        pop(&top);
    }
    return result;
}
```
This function pushes opening brackets onto the stack. For each closing bracket, it pops an element from the stack and checks if the popped element matches the expected opening bracket. If all checks pass and the stack is empty at the end, the parentheses are balanced.

### Displaying Results
The function `showResult` displays the result to the user:
```c
void showResult(int result) {
    if (result == 1) {
        printf("Parentheses are matching\n");
    } else {
        printf("Parentheses are unmatching\n");
    }
}
```

## Running the Program
The `main` function provides test expressions for checking parentheses balance:
```c
int main() {
    char* exp = "8)*(9";  // Example of unbalanced parentheses
    char* exp2 = "{2-1*(2-0}}"; // Example of unbalanced parentheses

    int result = isParenMatch(exp);
    int result2 = isParenMatch(exp2);

    showResult(result);
    showResult(result2);

    return 0;
}
```
The program outputs whether the parentheses in each expression are balanced or unbalanced.

## Conclusion
This project is a practical example of using stacks to solve the parentheses matching problem. Understanding this algorithm helps with learning the stack's functionality and how it can solve real-world problems involving balanced expressions.