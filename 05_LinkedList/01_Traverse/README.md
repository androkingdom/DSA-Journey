# Linked List Implementation in C

## Overview
This project demonstrates a simple **Singly Linked List** implementation in C. It consists of nodes where each node holds data and a reference to the next node. This structure allows dynamic memory management, where elements can be easily inserted or removed without needing to reallocate the entire structure, making it useful for various applications in programming.

In this implementation, we create a linked list with three nodes and traverse it to print the data.

---

## What is a Linked List?
A **Linked List** is a dynamic data structure where each element, called a **Node**, contains two parts:
1. **Data**: Stores the actual information.
2. **Pointer (Next)**: A reference (or pointer) to the next node in the list.

Unlike arrays, linked lists are not stored in contiguous memory blocks, allowing for efficient insertions and deletions.

![Linked List Visualization](https://media.geeksforgeeks.org/wp-content/uploads/20220712172013/Singlelinkedlist.png)  
*Visual representation of a Singly Linked List with 3 nodes*

---

## Why Use a Linked List?

### Advantages:
- **Dynamic Size**: The list can grow or shrink dynamically as needed.
- **Efficient Insertion/Deletion**: Inserting or removing nodes (elements) can be done in constant time, O(1), if the position is known.
- **Flexible Memory Usage**: Memory is allocated only when a node is created, unlike arrays, which may need large memory blocks to be allocated in advance.

### Disadvantages:
- **No Random Access**: To access a specific element, you must traverse the list from the beginning (O(n) time complexity), unlike arrays where you can directly index elements.
- **Extra Memory for Pointers**: Each node requires extra memory for the pointer to the next node.

---

## Code Explanation

### 1. **Node Structure**
A `Node` is defined as a structure containing `Data` (an integer in this case) and a `Next` pointer, which points to the next node in the list.

```c
typedef struct Node {
    int Data;            // Data stored in the node
    struct Node *Next;   // Pointer to the next node in the linked list
} Node;
```

### 2. **Creating Nodes and Linking Them**
In the `main` function, we create three nodes using `malloc` to allocate memory dynamically. We also link these nodes using the `Next` pointer.

```c
Node* Head = (Node*) malloc(sizeof(Node));   // Allocate memory for the first node
Node* Sec = (Node*) malloc(sizeof(Node));    // Allocate memory for the second node
Node* Third = (Node*) malloc(sizeof(Node));  // Allocate memory for the third node

// Linking the nodes
Head->Next = Sec;   // First node points to the second node
Sec->Next = Third;  // Second node points to the third node
Third->Next = NULL; // Third node is the last, points to NULL
```

### 3. **Traversal of the Linked List**
To traverse the linked list, we start from the head node and move along the list by following the `Next` pointers, printing the data of each node.

```c
void TravelInLL(Node *a) {
    while (a != NULL) {  
        printf("%d\t", a->Data);  // Print the data of the current node
        a = a->Next;  // Move to the next node
    }
    printf("\n");
}
```

### 4. **Output**
When you run this code, it will output:
```
10    12    143
```
This shows that the list was traversed, and all the data in the nodes was printed.

---

## Advantages of Linked Lists Over Arrays

| Feature                | Array                            | Linked List                    |
|------------------------|----------------------------------|--------------------------------|
| **Size**               | Fixed size, needs to be predefined | Dynamic size, can grow/shrink  |
| **Memory Allocation**   | Contiguous                       | Non-contiguous, efficient usage |
| **Insertion/Deletion**  | Costly, requires shifting elements | Efficient, O(1) at head/tail   |
| **Access Time**         | O(1) (Direct Access)             | O(n) (Sequential Access)       |

---

## Pros and Cons of Linked Lists

### Pros:
- **Efficient Memory Usage**: Memory is only allocated when required.
- **Ease of Insertion/Deletion**: Insertions and deletions can be performed without reallocation or shifting elements.

### Cons:
- **No Direct Access**: To access a particular node, you need to traverse the list from the beginning.
- **Memory Overhead**: Each node needs extra memory for the `Next` pointer.

---

## Visualizing Linked Lists
A linked list is often visualized as a series of boxes, where each box contains data and a pointer to the next box. Here's a simplified visual for the linked list created in this program:

```
[10 | Next] --> [12 | Next] --> [143 | NULL]
```

---

## Conclusion
Linked lists are a fundamental data structure that offer flexibility in memory management and efficient insertions and deletions. This code demonstrates a basic linked list traversal in C, helping understand its structure and operations.

For more advanced operations like insertion, deletion at specific positions, or sorting, linked lists provide a versatile tool, especially when dynamic memory management is crucial.

---

### Usage
To compile and run the code:
```
gcc linkedlist.c -o linkedlist
./linkedlist
```

---

### Further Reading
- **[GeeksForGeeks - Linked Lists](https://www.geeksforgeeks.org/linked-list-data-structure/)**
- **[Wikipedia - Linked Lists](https://en.wikipedia.org/wiki/Linked_list)**