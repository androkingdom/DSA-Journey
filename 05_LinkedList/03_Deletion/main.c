#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;            // Data part of the node
    struct Node* next;   // Pointer to the next node
} Node;

// Function to traverse and print the linked list
void travel(Node* head) {
    Node* ptr = head;  // Pointer to iterate through the list
    while (ptr != NULL) {
        printf("%d\t", ptr->data); // Print current node's data
        ptr = ptr->next; // Move to the next node
    }
    printf("\n"); // Print a newline after the list
}

// Function to remove the head (first node) of the linked list
Node* RemoveHead(Node* head) {
    Node* ptr = head; // Store the current head

    // Move head to the next node
    head = ptr->next; 
    free(ptr); // Free memory of the old head

    return head; // Return the new head
}

// Function to remove the tail (last node) of the linked list
Node* RemoveTail(Node* head) {
    if (head == NULL) { // Check if the list is empty
        return NULL; // Return NULL for an empty list
    }

    if (head->next == NULL) { // Check if there's only one node
        free(head); // Free the only node
        return NULL; // Return NULL for the empty list
    }

    Node* ptr1 = head; // Pointer to the second last node
    Node* ptr2 = head->next; // Pointer to the last node

    // Traverse to the end of the list
    while(ptr2->next != NULL) {
        ptr1 = ptr1->next; // Move ptr1 to the next node
        ptr2 = ptr2->next; // Move ptr2 to the next node
    }

    free(ptr2); // Free memory of the last node
    ptr1->next = NULL; // Set the next of second last node to NULL

    return head; // Return the updated head
}

// Function to remove a node by its value from the linked list
Node* RemoveValue(Node* head, int number) {
    Node* ptr1 = head; // Pointer to the current node
    Node* ptr2 = head->next; // Pointer to the next node

    // Check if the head node contains the value
    if(ptr1->data == number) {
        head = ptr2; // Update head to the next node
        free(ptr1); // Free the old head
        return head; // Return the new head
    }

    // Traverse the list to find the value
    while(ptr2 != NULL) {
        if(ptr2->data == number) { // If found
            ptr1->next = ptr2->next; // Bypass the node to remove it
            free(ptr2); // Free the node
            return head; // Return the updated head
        }
        ptr1 = ptr1->next; // Move to the next node
        ptr2 = ptr2->next; // Move to the next node
    }

    // If the value is not found in the list
    printf("Error: Number Not Found\n");
    return head; // Return the unchanged head
}

// Function to remove a node at a specific index
Node* RemoveAt(Node* head, int index) {
    if (head == NULL) { // Check if the list is empty
        printf("Error: List is empty\n");
        return NULL; // Return NULL for an empty list
    }

    Node* ptr = head; // Pointer to the current node
    Node* removal = head; // Pointer to the node to remove

    // Check if the index is 0
    if(index == 0) {
        head = ptr->next; // Update head to the next node
        free(ptr); // Free the old head
        return head; // Return the new head
    }

    int indx = 0; // Initialize index counter
    while(indx != index - 1 && removal != NULL) { // Traverse to the node before the index
        ptr = ptr->next; // Move to the next node
        removal = removal->next; // Move to the next node
        indx++; // Increment index counter
    }

    // Check if removal node is valid
    if (removal != NULL) {
        ptr->next = removal->next; // Bypass the node to remove it
        free(removal); // Free the node
    } else {
        printf("Error: Index out of bounds\n"); // Error message for invalid index
    }

    return head; // Return the updated head
}

// Main function to demonstrate the linked list operations
int main() {
    // Allocate memory for nodes
    Node* head = (Node*) malloc(sizeof(Node));
    Node* sec = (Node*) malloc(sizeof(Node));
    Node* third = (Node*) malloc(sizeof(Node));
    Node* forth = (Node*) malloc(sizeof(Node));
    Node* fiv = (Node*) malloc(sizeof(Node));
    Node* six = (Node*) malloc(sizeof(Node));
    Node* sev = (Node*) malloc(sizeof(Node));

    // Initialize node data and links
    head->data = 12;
    head->next = sec;

    sec->data = 23;
    sec->next = third;

    third->data = 56;
    third->next = forth;

    forth->data = 61;
    forth->next = fiv;

    fiv->data = 69;
    fiv->next = six;

    six->data = 23;
    six->next = sev;

    sev->data = 102;
    sev->next = NULL; // Last node points to NULL

    // Display original linked list
    printf("Original Linked List\n");
    travel(head);

    // Remove the head node
    printf("Delete First Element\n");
    head = RemoveHead(head);
    travel(head);

    // Remove node at index 0 (new head)
    printf("Delete Element By Index\n");
    head = RemoveAt(head, 0);
    travel(head);

    // Remove the last node
    printf("Delete Last Element\n");
    head = RemoveTail(head);
    travel(head);

    // Remove node with value 23
    printf("Delete Element By Value\n");
    head = RemoveValue(head, 23);
    travel(head);

    // Free remaining nodes before exiting
    while (head != NULL) {
        head = RemoveHead(head);
    }

    return 0; // Indicate successful completion
}