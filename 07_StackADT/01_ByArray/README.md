# Stack ADT

## Overview

A **Stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. This means that the last element added to the stack will be the first one to be removed. Stacks are widely used in various applications, including function call management, expression evaluation, and backtracking algorithms.

This README provides a detailed explanation of the stack implementation in C, covering the fundamental operations such as push, pop, peek, and more.

![Stack Illustration](https://i.postimg.cc/Y26rHvqn/Untitled-2024-09-29-1331.png)  <!-- Add your image here -->

## Code Explanation

### 1. Stack Structure

The stack is defined as a structure that contains the following components:

```c
struct stack {
    int max_size; // Maximum size of the stack
    int top;      // Index of the top element
    int* ptr;     // Pointer to dynamically allocated memory for stack elements
};
```

- `max_size`: Stores the maximum number of elements that can be held in the stack.
- `top`: Indicates the index of the current top element of the stack.
- `ptr`: A pointer to an array that dynamically holds the stack elements.

### 2. Initialization Function

The `stackInit` function initializes the stack, allocating memory for its elements:

```c
int stackInit(struct stack* Stack, int maxSize) {
    Stack->ptr = (int *)malloc(maxSize * sizeof(int));
    if (Stack->ptr == NULL) {
        printf("Error: Memory Not Allocated\n");
        return -1;
    }
    Stack->max_size = maxSize;
    Stack->top = -1; // Stack is initially empty
    return 1; // Return 1 on success
}
```

- It allocates memory for the stack and checks if the allocation was successful.
- Sets the `max_size` and initializes the `top` index.

### 3. Push Operation

The `push` function adds an element to the top of the stack:

```c
void push(struct stack* s, int number) {
    if (!isFull(s)) {
        s->ptr[++(s->top)] = number;
    } else {
        printf("Error: Stack is full\n");
    }
}
```

- It first checks if the stack is full. If not, it increments the `top` index and adds the number to the stack.

### 4. Pop Operation

The `pop` function removes the top element from the stack:

```c
int pop(struct stack* s) {
    if (!isEmpty(s)) {
        return s->ptr[(s->top)--];
    } else {
        printf("Error: Stack is empty\n");
        return -1;
    }
}
```

- It checks if the stack is empty before attempting to remove an element. If the stack is empty, it returns an error message.

### 5. Peek Operation

The `peek` function allows access to an element at a specific index without modifying the stack:

```c
int peek(struct stack* s, int index) {
    if (index < 0 || index > s->top) {
        printf("Error: Out Of Bound\n");
        return -1;
    } else {
        return s->ptr[index];
    }
}
```

- It checks if the given index is valid and returns the element at that index.

### 6. Displaying the Stack

The `showStack` function prints all elements currently in the stack:

```c
void showStack(struct stack* s) {
    if (!isEmpty(s)) {
        printf("Stack Contains:\n");
        int i = s->top;
        while (i >= 0) {
            printf("%d\n", s->ptr[i]);
            i--;
        }
    } else {
        printf("Stack is empty\n");
    }
}
```

- It iterates from the `top` of the stack to the bottom, displaying each element.

### 7. Memory Cleanup

The `destruction` function frees the memory allocated for the stack:

```c
void destruction(struct stack* s) {
    if (s->ptr != NULL) {
        free(s->ptr);
        s->ptr = NULL;
    }
}
```

- This is crucial to avoid memory leaks.

## Conclusion

This implementation of the Stack Abstract Data Type in C is a simple yet effective way to understand how stacks operate. By using this code, you can grasp the fundamental operations of stack data structures and their significance in programming.

For further exploration, you can modify the code to implement additional features such as dynamic resizing of the stack or error handling enhancements.