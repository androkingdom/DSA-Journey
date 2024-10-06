# Stack Application: Parentheses Matching Problem

## Overview
This project implements a parentheses matching solution using a stack. A stack is a data structure that operates on a Last In, First Out (LIFO) principle. In this program, we use a stack to check if the parentheses in a given expression are balanced. This is essential in validating mathematical expressions, programming syntax, and more. 

![Stack and Parentheses Matching Diagram](/07_StackADT/Application/image.png)

**How it Works:**  
1. Each time we encounter an opening parenthesis `(`, we push it onto the stack.
2. When we encounter a closing parenthesis `)`, we pop the stack.
3. At the end, if the stack is empty, the parentheses are balanced. If not, they are unbalanced.

## Code Explanation

### 1. Struct Definition
```c
typedef struct Node {
    char data;
    struct Node* next;
} Node;
```
This defines a `Node` structure, representing each item in the stack, which contains:
- `data`: Stores the character (in this case, the parenthesis).
- `next`: A pointer to the next node in the stack.

### 2. Checking if the Stack is Empty
```c
int isEmpty(Node** top) {
    return *top == NULL;
}
```
This function checks if the stack is empty by returning `1` if the `top` is `NULL` and `0` otherwise. This is useful to determine if the stack has no more elements to process.

### 3. Pushing an Element onto the Stack
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
The `push` function creates a new `Node`, assigns the data, links it to the current `top`, and updates `top` to the new node.

### 4. Popping an Element from the Stack
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
This function removes the `top` element from the stack. It checks if the stack is empty, removes the top element, and returns its data. If the stack is empty, it returns a null character `\0`.

### 5. Parentheses Matching Logic
```c
int isParenMatch(char* exp) {
    Node* top = NULL;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(&top, '(');
        } else if (exp[i] == ')') {
            char check = pop(&top);
            if (check == '\0') {
                return 0;
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
This function takes a character string and iterates over it:
- For every `(`, it pushes it onto the stack.
- For every `)`, it pops from the stack.
- If the stack becomes empty before the expression ends, or it’s not empty at the end, the parentheses are not balanced.

### 6. Displaying the Result
```c
void showResult(int result) {
    if (result == 1) {
        printf("Parentheses are matching\n");
    } else {
        printf("Parentheses are unmatching\n");
    }
}
```
This function prints a message based on whether the parentheses are balanced (`result` is 1) or unbalanced (`result` is 0).

## How to Use
1. Define the expression you want to check as a `char*` string in the `main` function.
2. Call `isParenMatch()` with the expression.
3. Use `showResult()` to display if the expression's parentheses are balanced.

```c
int main() {
    char* exp = "8)*(9";  
    char* exp2 = "(8+1*(32-32)*(93-32))-((41+23)-11)";
    int result = isParenMatch(exp);
    int result2 = isParenMatch(exp2);
    showResult(result);
    showResult(result2);
    return 0;
}
```

## Conclusion
This code provides a simple and efficient way to check for balanced parentheses using a stack. By following the LIFO principle, it ensures that every opening parenthesis has a corresponding closing parenthesis in the correct order.