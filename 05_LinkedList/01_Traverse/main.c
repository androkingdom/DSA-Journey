#include <stdio.h> 
#include <stdlib.h>

// Define the structure of a Node in the linked list
typedef struct Node {
    int Data;            // Data stored in the node
    struct Node *Next;   // Pointer to the next node in the linked list
} Node;

// Function to traverse the linked list and print the data in each node
void TravelInLL(Node *a){
    while (a != NULL) {  // Continue until the last node (where a->Next is NULL)
        printf("%d\t", a->Data);  // Print the data of the current node
        a = a->Next;  // Move to the next node
    }
    printf("\n");  // Newline after printing all node data
}

int main() {
    // Declare pointers for nodes
    Node* Head;
    Node* Sec;
    Node* Third;

    // Memory Allocation for the nodes
    Head = (Node*) malloc(sizeof(Node));   // Allocating memory for the first node
    Sec = (Node*) malloc(sizeof(Node));    // Allocating memory for the second node
    Third = (Node*) malloc(sizeof(Node));  // Allocating memory for the third node

    // Data Insertion
    Head->Data = 10;   // Assign data to the first node
    Sec->Data = 12;    // Assign data to the second node
    Third->Data = 143; // Assign data to the third node

    // Linking the nodes
    Head->Next = Sec;   // First node points to the second node
    Sec->Next = Third;  // Second node points to the third node
    Third->Next = NULL; // Third node is the last, so it points to NULL

    // Traverse the linked list and print the data
    TravelInLL(Head);

    return 0;  // Exit program
}
