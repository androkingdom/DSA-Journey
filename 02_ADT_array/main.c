#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int* ptr;
    int size;
} List;

// Function prototypes
void InitList(List* ListVar, int size);
void SetElements(List* ListVar, int array[], int array_size);
int GetElementAt(List* ListVar, int index);
void ShowList(List* ListVar);
int IndexOf(List* ListVar, int number);
int Max(List* ListVar);
int Min(List* ListVar);
int SumAll(List* ListVar);
int Contain(List* ListVar, int number);
void FreeAll(List* ListVar);

// Initialize the List with the specified size
void InitList(List* ListVar, int size) {
    ListVar->ptr = (int*) malloc(size * sizeof(int));
    if (ListVar->ptr == NULL) {
        printf("Error: Memory Not Allocated\n");
        return;
    }
    ListVar->size = size;
}

// Set elements of the List from an array
void SetElements(List* ListVar, int array[], int array_size) {
    for (int i = 0; i < ListVar->size; i++) {
        ListVar->ptr[i] = array[i];
    }
}

// Get the element at a specific index
int GetElementAt(List* ListVar, int index) {
    if (index < 0 || index >= ListVar->size) {
        printf("Error: Index out of bounds\n");
        return -1; // Indicate an error
    }
    return ListVar->ptr[index];
}

// Show all elements in the List
void ShowList(List* ListVar) {
    printf("[");
    for (int i = 0; i < ListVar->size; i++) {
        printf("%d", ListVar->ptr[i]);
        if (i != (ListVar->size) - 1) {
            printf(", ");
        }
    }
    printf("]");
    printf("\n");
}

// Find the index of a specific number in the List
int IndexOf(List* ListVar, int number) {
    for (int index = 0; index < ListVar->size; index++) {
        if (ListVar->ptr[index] == number) {
            return index;
        }
    }
    return -1; // Return -1 if number is not found
}

// Find the maximum value in the List
int Max(List* ListVar) {
    if (ListVar->size == 0) {
        printf("Error: List is empty\n");
        return -1; // Indicate an error
    }
    int max = ListVar->ptr[0];
    for (int i = 1; i < ListVar->size; i++) {
        if (ListVar->ptr[i] > max) {
            max = ListVar->ptr[i];
        }
    }
    return max;
}

// Find the minimum value in the List
int Min(List* ListVar) {
    if (ListVar->size == 0) {
        printf("Error: List is empty\n");
        return -1; // Indicate an error
    }
    int min = ListVar->ptr[0];
    for (int i = 1; i < ListVar->size; i++) {
        if (ListVar->ptr[i] < min) {
            min = ListVar->ptr[i];
        }
    }
    return min;
}

// Calculate the sum of all elements in the List
int SumAll(List* ListVar) {
    int sum = 0;
    for (int i = 0; i < ListVar->size; i++) {
        sum += ListVar->ptr[i];
    }
    return sum;
}

// Check if a specific number exists in the List
int Contain(List* ListVar, int number) {
    for (int i = 0; i < ListVar->size; i++) {
        if (ListVar->ptr[i] == number) {
            return 1; // Return 1 (true) if number is found
        }
    }
    return 0; // Return 0 (false) if number is not found
}

// Free memory allocated for the List
void FreeAll(List* ListVar) {
    free(ListVar->ptr);
    ListVar->ptr = NULL; // Set pointer to NULL to avoid dangling pointer
}

int main() {
    List list;
    int a[5] = {1, 2, 3, 4, 5};
    InitList(&list, 5);
    int array_size = sizeof(a) / sizeof(a[0]);
    SetElements(&list, a, array_size);
    ShowList(&list);
    printf("Max. number in list: %d\n", Max(&list));
    printf("Min. number in list: %d\n", Min(&list));
    FreeAll(&list);
    return 0;
}
