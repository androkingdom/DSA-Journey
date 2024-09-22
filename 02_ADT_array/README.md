# List ADT (Abstract Data Type) in C

## Overview
An **Abstract Data Type (ADT)** is a data structure that hides the details of its implementation from the user, exposing only necessary operations. This concept allows us to manage complex data structures like lists, queues, stacks, and trees more efficiently by abstracting their behaviors without focusing on the underlying details.

In this project, we implement a **List ADT** in C, which stores a dynamic array of integers and provides operations such as initialization, element retrieval, insertion, searching, and more. The code encapsulates these operations inside functions that manipulate the List, making it easy to work with without worrying about the underlying implementation details.

## Data Structure
The `List` structure contains:
- `ptr`: A pointer to an integer array (dynamic list of elements).
- `size`: The number of elements in the List.

```c
typedef struct List {
    int* ptr;    // Dynamic array pointer
    int size;    // Number of elements
} List;
```

## Functions Overview

- **`InitList(List* ListVar, int size)`**: Initializes the List with a given size and allocates memory for it.
- **`SetElements(List* ListVar, int array[], int array_size)`**: Fills the List with elements from the provided array.
- **`GetElementAt(List* ListVar, int index)`**: Retrieves the element at the specified index.
- **`ShowList(List* ListVar)`**: Displays the entire list of elements in a formatted manner.
- **`IndexOf(List* ListVar, int number)`**: Returns the index of a specified element, or `-1` if the element is not found.
- **`Max(List* ListVar)`**: Finds and returns the maximum element in the list.
- **`Min(List* ListVar)`**: Finds and returns the minimum element in the list.
- **`SumAll(List* ListVar)`**: Calculates and returns the sum of all elements in the list.
- **`Contain(List* ListVar, int number)`**: Checks if a given number exists in the list, returning `1` if true, `0` otherwise.
- **`FreeAll(List* ListVar)`**: Frees the memory allocated for the List.

## Code Explanation

1. **Initialization**:  
   The function `InitList()` allocates memory for the List and initializes its size. If memory allocation fails, an error message is printed.
   
   ```c
   void InitList(List* ListVar, int size) {
       ListVar->ptr = (int*) malloc(size * sizeof(int));
       if (ListVar->ptr == NULL) {
           printf("Error: Memory Not Allocated\n");
           return;
       }
       ListVar->size = size;
   }
   ```

2. **Setting Elements**:  
   The `SetElements()` function copies elements from a given array into the List's dynamic array.

   ```c
   void SetElements(List* ListVar, int array[], int array_size) {
       for (int i = 0; i < ListVar->size; i++) {
           ListVar->ptr[i] = array[i];
       }
   }
   ```

3. **Display & Operations**:  
   Functions like `ShowList()`, `Max()`, `Min()`, and `SumAll()` provide basic operations for displaying, finding the maximum and minimum values, and summing all elements.

   ```c
   void ShowList(List* ListVar) {
       printf("[");
       for (int i = 0; i < ListVar->size; i++) {
           printf("%d", ListVar->ptr[i]);
           if (i != (ListVar->size) - 1) {
               printf(", ");
           }
       }
       printf("]\n");
   }
   ```

4. **Memory Management**:  
   It's important to free the memory allocated to the List after you're done using it. The `FreeAll()` function handles that.

   ```c
   void FreeAll(List* ListVar) {
       free(ListVar->ptr);
       ListVar->ptr = NULL; // Avoid dangling pointers
   }
   ```

## Example Usage

In the `main()` function, a List is created and initialized with a predefined array. The list is displayed, the maximum and minimum values are printed, and finally, the memory is freed.

```c
int main() {
    List list;
    int a[5] = {1, 2, 3, 4, 5};
    InitList(&list, 5);
    SetElements(&list, a, 5);
    ShowList(&list);
    printf("Max. number in list: %d\n", Max(&list));
    printf("Min. number in list: %d\n", Min(&list));
    FreeAll(&list);
    return 0;
}
```

## Conclusion
This implementation demonstrates how to create a simple ADT for a dynamic List in C, allowing us to abstract away the complexities of memory management and focus on the core operations. This is a fundamental approach used in more advanced data structures and algorithms.

### Key Points:
- **Yes, you can call it an ADT** because it adheres to many principles of ADTs, such as abstracting operations and encapsulating list behavior through functions.

- However, it’s a **basic ADT** because it exposes the structure directly. You can improve it by making the `List` structure fully opaque (not visible to the user) and accessed only through functions.