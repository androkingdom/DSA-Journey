# Linked List Deletion in C

## Overview

This repository contains a C implementation of a singly linked list with various deletion operations, including removing the head, tail, a specific value, and a node at a given index. The code demonstrates basic linked list operations, dynamic memory management, and error handling.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Code Snippets](#code-snippets)
  - [Node Structure](#node-structure)
  - [Traversal Function](#traversal-function)
  - [Remove Head Function](#remove-head-function)
  - [Remove Tail Function](#remove-tail-function)
  - [Remove Value Function](#remove-value-function)
  - [Remove At Index Function](#remove-at-index-function)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Installation

To compile and run the code, ensure you have GCC installed. You can compile the code with the following command:

```bash
gcc main.c -o linked_list_deletion
```

## Usage

Run the executable to see the linked list operations in action:

```bash
./linked_list_deletion
```

## Code Snippets

### Node Structure

The basic structure for a node in the linked list is defined as follows:

```c
typedef struct Node {
    int data;            // Data part of the node
    struct Node* next;   // Pointer to the next node
} Node;
```

### Traversal Function

The function to traverse and print the linked list:

```c
void travel(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
```

### Remove Head Function

Function to remove the head (first node) of the linked list:

```c
Node* RemoveHead(Node* head) {
    Node* ptr = head;
    head = ptr->next; 
    free(ptr); 
    return head; 
}
```

### Remove Tail Function

Function to remove the tail (last node) of the linked list:

```c
Node* RemoveTail(Node* head) {
    // Check for empty or single-node list
    if (head == NULL) return NULL; 
    if (head->next == NULL) {
        free(head); 
        return NULL; 
    }
    // Traverse to the second last node
    Node* ptr1 = head; 
    Node* ptr2 = head->next; 
    while(ptr2->next != NULL) {
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    }
    free(ptr2);
    ptr1->next = NULL; 
    return head; 
}
```

### Remove Value Function

Function to remove a node by its value:

```c
Node* RemoveValue(Node* head, int number) {
    Node* ptr1 = head;
    Node* ptr2 = head->next;
    if(ptr1->data == number) {
        head = ptr2; 
        free(ptr1); 
        return head; 
    }
    while(ptr2 != NULL) {
        if(ptr2->data == number) {
            ptr1->next = ptr2->next; 
            free(ptr2);
            return head; 
        }
        ptr1 = ptr1->next; 
        ptr2 = ptr2->next; 
    }
    printf("Error: Number Not Found\n");
    return head; 
}
```

### Remove At Index Function

Function to remove a node at a specific index:

```c
Node* RemoveAt(Node* head, int index) {
    // Check if the list is empty
    if (head == NULL) {
        printf("Error: List is empty\n");
        return NULL; 
    }
    Node* ptr = head; 
    Node* removal = head;
    if(index == 0) {
        head = ptr->next; 
        free(ptr); 
        return head; 
    }
    int indx = 0;
    while(indx != index - 1 && removal != NULL) {
        ptr = ptr->next; 
        removal = removal->next; 
        indx++; 
    }
    if (removal != NULL) {
        ptr->next = removal->next; 
        free(removal); 
    } else {
        printf("Error: Index out of bounds\n");
    }
    return head; 
}
```

## Examples

The `main` function demonstrates how to create a linked list, perform deletions, and print the list after each operation. 

## Contributing

Feel free to fork the repository and submit pull requests for improvements or additional features!

## License

This project is licensed under the MIT License.