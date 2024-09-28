#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the linked list
typedef struct Node {
    int data;            // Integer data of the node
    struct Node* ptr;    // Pointer to the next node
} Node;

// Function to traverse the linked list and print its elements
void Travel(Node* a) {
    while (a != NULL) {   // Iterate until the end of the list
        printf("%d\t", a->data); // Print the data of the current node
        a = a->ptr;      // Move to the next node
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the list
Node* InsertAtFirst(Node* head, int newdata) {
    Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node

    new->data = newdata; // Set the data of the new node
    new->ptr = head;     // Link the new node to the current head

    return new; // Return the new node as the new head
}

// Function to insert a new node at the end of the list
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

// Function to insert a new node after a specified node
Node* InsertAfterNode(Node* head, Node* NodePtr, int number) {
    Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node

    new->data = number; // Set the data for the new node
    new->ptr = NodePtr->ptr; // Link the new node to the next node of NodePtr

    NodePtr->ptr = new; // Link NodePtr to the new node

    return head; // Return the head of the list
}

// Function to insert a new node at a specified index
Node* InsertAt(Node* head, int index, int number) {
    Node* primary = head; // Use a primary pointer to traverse the list
    for (int i = 0; i <= index-1; i++) { // Iterate up to the desired index
        if (i == index-1) { // If at the correct index
            Node* new = (Node*) malloc(sizeof(Node)); // Allocate memory for the new node
            new->data = number; // Set the data for the new node
            new->ptr = primary->ptr; // Link new node to the next node
            primary->ptr = new; // Link primary node to the new node
            return head; // Return the head of the list
        } else {
            primary = primary->ptr; // Move to the next node
        }
    }
    return head; // Return the head of the list if index is out of bounds
}

int main() {
    Node* head;    // Pointer to the head of the list
    Node* next1;   // Pointer to the second node
    Node* next2;   // Pointer to the third node

    // Allocate memory for the three initial nodes
    head = (Node*) malloc(sizeof(Node));
    next1 = (Node*) malloc(sizeof(Node));
    next2 = (Node*) malloc(sizeof(Node));

    // Initialize the first node
    head->data = 12;
    head->ptr = next1;

    // Initialize the second node
    next1->data = 142;
    next1->ptr = next2;

    // Initialize the third node
    next2->data = 532;
    next2->ptr = NULL; // The last node points to NULL

    // Print the original linked list
    printf("Original Linked List\n");
    Travel(head);

    // Insert an element at the beginning
    printf("\nElement Inserted At First\n");
    head = InsertAtFirst(head, 31); // Update head after insertion
    Travel(head);

    // Insert an element at index 2
    printf("\nElement Insertion With Index\n");
    head = InsertAt(head, 2, 98); // Update head after insertion
    Travel(head);

    // Insert an element at the end
    printf("\nElement Insertion At End\n");
    head = Put(head, 101); // Update head after insertion
    Travel(head);

    // Insert an element after a specific node
    printf("\nElement Insertion After Node\n");
    head = InsertAfterNode(head, next2, 87); // Update head after insertion
    Travel(head);

    // Free allocated memory for nodes (optional)
    // In practice, you would want to free each node to avoid memory leaks.

    return 0; // End of the program
}
