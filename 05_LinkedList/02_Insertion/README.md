# Linked List Insertion Operations in C

## Overview
This project demonstrates various insertion operations in a singly linked list implemented in C. The linked list supports inserting new nodes at different positions: the beginning, the end, and at specific indices, as well as after a given node. Understanding these operations is essential for manipulating linked lists effectively.

## Table of Contents
| Function Name            | Description                                      |
|--------------------------|--------------------------------------------------|
| [Travel](#1-travel)     | Traverse and print the linked list elements.     |
| [InsertAtFirst](#2-insertatfirst) | Insert a new node at the beginning.        |
| [Put](#3-put)           | Insert a new node at the end of the list.       |
| [InsertAfterNode](#4-insertafternode) | Insert a new node after a specific node. |
| [InsertAt](#5-insertat) | Insert a new node at a specified index.          |

## Function Explanations

### 1. Travel
**Function Signature:** `void Travel(Node* a)`

This function traverses the linked list and prints each element.

```c
void Travel(Node* a) {
    while (a != NULL) {   
        printf("%d\t", a->data); 
        a = a->ptr;      
    }
    printf("\n");
}
```
- **How It Works:** The function iterates through the list until it reaches the end (when the pointer is `NULL`), printing each node's data.

---

### 2. InsertAtFirst
**Function Signature:** `Node* InsertAtFirst(Node* head, int newdata)`

This function inserts a new node at the beginning of the list.

```c
Node* InsertAtFirst(Node* head, int newdata) {
    Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node

    new->data = newdata; // Set the data of the new node
    new->ptr = head;     // Link the new node to the current head

    return new; // Return the new node as the new head
}
```
- **How It Works:** A new node is created and its pointer is set to the current head, effectively making it the new head of the list.

---

### 3. Put
**Function Signature:** `Node* Put(Node* head, int number)`

This function inserts a new node at the end of the list.

```c
Node* Put(Node* head, int number) {
    Node* dummy = head; // Use a dummy pointer to traverse the list

    while(dummy->ptr != NULL) { // Traverse to the last node
        dummy = dummy->ptr; 
    }

    Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
    new->data = number; // Set the data for the new node
    new->ptr = NULL;    // Set the next pointer to NULL

    dummy->ptr = new; // Link the last node to the new node

    return head; // Return the head of the list
}
```
- **How It Works:** The function traverses to the last node and appends a new node after it.

---

### 4. InsertAfterNode
**Function Signature:** `Node* InsertAfterNode(Node* head, Node* NodePtr, int number)`

This function inserts a new node after a specified node.

```c
Node* InsertAfterNode(Node* head, Node* NodePtr, int number) {
    Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node

    new->data = number; // Set the data for the new node
    new->ptr = NodePtr->ptr; // Link the new node to the next node of NodePtr

    NodePtr->ptr = new; // Link NodePtr to the new node

    return head; // Return the head of the list
}
```
- **How It Works:** A new node is created, and its pointer is set to the node after the specified node, linking the specified node to the new node.

---

### 5. InsertAt
**Function Signature:** `Node* InsertAt(Node* head, int index, int number)`

This function inserts a new node at a specified index.

```c
Node* InsertAt(Node* head, int index, int number) {
    Node* primary = head; // Use a primary pointer to traverse the list
    for (int i = 0; i <= index-1; i++) { 
        if (i == index-1) { 
            Node* new = (Node*) malloc(sizeof(Node)); 
            new->data = number; 
            new->ptr = primary->ptr; 
            primary->ptr = new; 
            return head; 
        } else {
            primary = primary->ptr; // Move to the next node
        }
    }
    return head; // Return the head of the list if index is out of bounds
}
```
- **How It Works:** The function iterates to the desired index and inserts a new node there by adjusting the pointers.

---

## Analogy
Think of a linked list like a chain of people holding hands. Each person (node) knows who is holding their hand next (the next node). You can add new people at the beginning (like welcoming a new friend into the circle), at the end (like adding a new friend at the end of the line), or between two people (like introducing a new friend between two existing friends).

## Conclusion
This implementation provides a fundamental understanding of insertion operations in a linked list in C, demonstrating how to create, traverse, and manipulate nodes effectively. Insertion operations are crucial for dynamically managing data in linked lists, enabling efficient growth and restructuring of the list.