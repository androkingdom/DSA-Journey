# Array Insertion Implementation in C

## Overview

This project implements basic functionality for inserting an element into an array at a specified index. It includes methods for displaying the array and managing element insertion while ensuring the array's size constraints are respected.

## Code Example

```c
#include <stdio.h> 

void show(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void insertAt(int array[], int index, int size, int number, int max_storage) {
    if (index > size || size >= max_storage) {
        printf("Error: Invalid Range\n");
        return;
    }
    for (int i = size - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }
    array[index] = number;
}

int main() {
    int list[20] = {1, 21, 14, 35, 129};
    int total_size = 20, using = 5;
    show(list, using);
    insertAt(list, 3, using, 100, total_size);
    using++;
    show(list, using);

    return 0;
}
```

## Explanation of the Insert Operation

The `insertAt` function allows you to insert a new element into the array at a specified index. Here’s how it works:

1. **Range Validation**: The function first checks if the index is within the valid range (not greater than `size`) and if the current size is less than the maximum storage capacity. If the index is invalid or the size exceeds the allowed capacity, it prints an error message and exits.

2. **Element Shifting**: If the index is valid, the function enters a loop that starts from the last used element (`size - 1`) and moves backwards. It shifts each element one position to the right to make space for the new element.

3. **Insertion**: After shifting, the function inserts the new number at the specified index.

This operation efficiently maintains the order of the array while ensuring that no out-of-bounds errors occur.

## Compilation

To compile the program, use:

```bash
gcc -o array_insertion array_insertion.c
```

## License

This project is licensed under the MIT License.
```