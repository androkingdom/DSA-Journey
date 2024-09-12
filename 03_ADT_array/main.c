#include <stdio.h>
#include <stdlib.h>

// Structure to represent the array
typedef struct my_array {
    int* ptr;       // Pointer to dynamically allocated memory
    int size;       // Store the size of the array within the structure
} my_array;

// Function to allocate memory for the array
void Allocate(my_array* a, int memory) {
    a->size = memory;  // Store the size in the structure
    a->ptr = (int*) malloc(memory * sizeof(int));  // Allocate memory based on the size passed
    if (a->ptr == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        exit(1);  // Exit the program if malloc fails
    }
    printf("Memory for %d elements allocated\n", memory);
}

// Function to set elements in the array
void setElement(my_array* a) {
    for (int i = 0; i < a->size; i++) {
        printf("Enter Number %d: ", i + 1);
        scanf("%d", &a->ptr[i]);
    }
}

// Function to print all elements of the array
void showElements(my_array* a) {
    for (int i = 0; i < a->size; i++) {
        printf("%d is at index %d\n", a->ptr[i], i);
    }
}

// Function to get the last element of the array
void lastElement(my_array* a) {
    if (a->size > 0) {
        printf("Last element: %d\n", a->ptr[a->size - 1]);
    } else {
        printf("Array is empty\n");
    }
}

// Function to free the dynamically allocated memory
void freeArray(my_array* a) {
    free(a->ptr);  // Free the allocated memory
    a->ptr = NULL; // Set pointer to NULL to avoid dangling pointer
    a->size = 0;   // Reset the size
}

// Main function demonstrating the use of the array ADT
int main() {
    printf("My Structure!\n");
    
    my_array marks;   // Create an instance of my_array
    Allocate(&marks, 5);  // Allocate memory for 5 elements
    
    setElement(&marks);   // Set elements in the array
    // showElements(&marks);  // Uncomment to show all elements
    lastElement(&marks);  // Show the last element
    
    freeArray(&marks);    // Free the allocated memory
    return 0;
}
