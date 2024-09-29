# README for Doubly Linked List

## Overview

A doubly linked list is a type of linked list in which each node contains a data field and two pointers: one pointing to the next node and the other pointing to the previous node. This structure allows for traversal in both directions, making it easier to insert and delete nodes compared to singly linked lists. The operations for managing a doubly linked list are similar to those of a singly linked list but with added complexity due to the extra pointer.

![Doubly Linked List Structure](https://i.postimg.cc/mZCCv4Kb/Untitled-2024-09-29-1331.png)  
*Figure: Representation of a Doubly Linked List*

## Table of Contents
1. [Code Explanation](#code-explanation)
   - [Node Structure](#node-structure)
   - [Traversal Function](#traversal-function)
2. [Common Operations](#common-operations)
   - [Insertion](#insertion)
   - [Deletion](#deletion)
3. [Advantages of Doubly Linked Lists](#advantages-of-doubly-linked-lists)
4. [Conclusion](#conclusion)

---

## Code Explanation

### Node Structure

The node structure for the doubly linked list is defined as follows:

```c
struct Node {
    int data;                // Data part of the node
    struct Node* prev;      // Pointer to the previous node
    struct Node* next;      // Pointer to the next node
};
```
Each node holds an integer value (`data`) and two pointers (`prev` and `next`).

### Traversal Function

The `travel` function is designed to traverse the entire doubly linked list from head to tail and then from tail back to head:

```c
void travel(struct Node* head) {
    struct Node* ptrFor = head;  // Pointer for forward traversal
    struct Node* ptrBack = NULL;  // Pointer for backward traversal

    // Traverse from head to tail
    while (ptrFor != NULL) {
        printf("%d\t", ptrFor->data);  // Print current node's data
        ptrBack = ptrFor;               // Update ptrBack to current node
        ptrFor = ptrFor->next;          // Move to the next node
    }

    // Traverse from tail to head
    while (ptrBack != NULL) {
        printf("%d\t", ptrBack->data);  // Print current node's data
        ptrBack = ptrBack->prev;        // Move to the previous node
    }
    printf("\n");  // Print a newline at the end
}
```

In the above code, the `travel` function first prints the data from the head to the last node, then it prints the data from the last node back to the head.

## Common Operations

### Insertion

To insert a new node in a doubly linked list, you can do it at the beginning, end, or at a specific position. Below is the pseudocode for each scenario:

**1. Insertion at the Beginning:**

```
function insertAtBeginning(head, newNode):
    newNode.next = head
    if head is not NULL:
        head.prev = newNode
    head = newNode
    newNode.prev = NULL
    return head
```

**2. Insertion at the End:**

```
function insertAtEnd(head, newNode):
    if head is NULL:
        head = newNode
        newNode.prev = NULL
        newNode.next = NULL
        return head
    
    last = head
    while last.next is not NULL:
        last = last.next
    
    last.next = newNode
    newNode.prev = last
    newNode.next = NULL
    return head
```

**3. Insertion at a Specific Position:**

```
function insertAtPosition(head, newNode, position):
    if position == 0:
        return insertAtBeginning(head, newNode)

    current = head
    for i from 0 to position - 1:
        if current is NULL:
            print("Position out of bounds")
            return head
        current = current.next

    newNode.next = current
    newNode.prev = current.prev
    if current.prev is not NULL:
        current.prev.next = newNode
    current.prev = newNode
    return head
```

### Deletion

Similar to insertion, deletion can be done at the beginning, end, or by value. Here’s the pseudocode for each operation:

**1. Deletion at the Beginning:**

```
function deleteAtBeginning(head):
    if head is NULL:
        print("List is empty")
        return head

    head = head.next
    if head is not NULL:
        head.prev = NULL
    return head
```

**2. Deletion at the End:**

```
function deleteAtEnd(head):
    if head is NULL:
        print("List is empty")
        return head

    last = head
    while last.next is not NULL:
        last = last.next

    if last.prev is not NULL:
        last.prev.next = NULL
    else:
        head = NULL
    free(last)
    return head
```

**3. Deletion by Value:**

```
function deleteByValue(head, value):
    current = head
    while current is not NULL:
        if current.data == value:
            if current.prev is not NULL:
                current.prev.next = current.next
            if current.next is not NULL:
                current.next.prev = current.prev
            if current == head: // If head is to be deleted
                head = current.next
            free(current)
            return head
        current = current.next
    print("Value not found in the list")
    return head
```

## Advantages of Doubly Linked Lists

1. **Bidirectional Traversal**: You can traverse the list in both directions.
2. **Easier Deletion**: Given a node pointer, you can easily delete it without needing to traverse from the head to find the previous node.
3. **Flexible Insertion**: You can insert nodes before or after a given node with ease.

## Conclusion

Doubly linked lists provide a powerful and flexible way to manage collections of data. They enhance the capabilities of singly linked lists by allowing easier navigation and manipulation of the list's elements. Their complexity is slightly higher than that of singly linked lists due to the additional pointer, but the advantages they offer in terms of ease of use and functionality are often worth it.