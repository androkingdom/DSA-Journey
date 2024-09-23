# Dynamic List Implementation in C

## Overview

This project implements a dynamic list structure in C, providing functionality to manage a collection of integers. The primary focus is on the delete operation, which allows elements to be removed from the list efficiently while maintaining the integrity of the remaining elements.

## Code Example

```c
#include <stdio.h> 
#include <stdlib.h>

typedef struct list {
    int* ptr;
    int ReservedMemo;
    int UsingMemo;
} list;

void MemoInit(list* a, int NeededMemo, int UsingMemo) {
    a->ptr = (int*) malloc(NeededMemo * sizeof(int));
    a->ReservedMemo = NeededMemo;
    a->UsingMemo = UsingMemo;
}

void DataInit(list* a, int array[]) {
    for (int i = 0; i < a->UsingMemo; i++) {
        a->ptr[i] = array[i];
    }
}

void ListDisplay(list* a) {
    for (int i = 0; i < a->UsingMemo; i++) {
        printf("%d\t", a->ptr[i]);
    }
    printf("\n");
}

void DeleteAt(list* a, int index) {
    if (index < 0 || index >= a->UsingMemo) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < a->UsingMemo - 1; i++) {
        a->ptr[i] = a->ptr[i + 1];
    }
    a->UsingMemo--;
}

int main() {
    list lst;
    int data[] = {1, 32, 12, 45};
    MemoInit(&lst, 10, 4);
    DataInit(&lst, data);
    ListDisplay(&lst);
    DeleteAt(&lst, 2); // Deleting the element at index 2
    ListDisplay(&lst);
    return 0;
}
```

## Explanation of the Delete Operation

The `DeleteAt` function allows you to remove an element from the dynamic list at a specified index. Here’s how it works:

1. **Index Validation**: The function first checks if the provided index is within the valid range (0 to `UsingMemo - 1`). If the index is out of bounds, it prints an error message and exits.

2. **Element Shifting**: If the index is valid, the function enters a loop that starts from the specified index and continues to the second-to-last element of the list. It shifts each element one position to the left, effectively overwriting the element at the specified index.

3. **Update Usage Count**: After shifting the elements, the function decreases `UsingMemo`, which keeps track of the number of currently used elements in the list.

This operation efficiently maintains the list's integrity while ensuring that no memory leaks occur.

## Compilation

To compile the program, use:

```bash
gcc -o dynamic_list dynamic_list.c
```

## License

This project is licensed under the MIT License.