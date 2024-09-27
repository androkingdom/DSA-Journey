# Search Algorithms in C

## Overview
This repository contains the implementation of two fundamental search algorithms in C:
- **Linear Search**: A simple search algorithm that works on both sorted and unsorted arrays.
- **Binary Search**: An efficient search algorithm that works on sorted arrays by repeatedly dividing the search space in half.

These algorithms are useful for finding the presence of a number in an array. This implementation also includes clear and concise comments to explain the steps involved.

## Code Explanation

```c
#include <stdio.h> 

// Linear Search Function
int LinearS(int a[], int a_size, int number);

// Binary Search Function
int BinaryS(int a[], int a_size, int number);

int main(){
    int array[] = {1, 2, 39, 60, 66, 81, 90, 100}; // Example sorted array

    // Test Linear Search
    printf("%d\n", LinearS(array, 8, 2)); // Expected output: 1 (found)

    // Test Binary Search
    printf("%d\n", BinaryS(array, 8, 2)); // Expected output: 1 (found)

    return 0;
}
```

### Function Breakdown

- **`LinearS()`**: This function performs a linear search over an array, checking each element sequentially.
- **`BinaryS()`**: This function performs a binary search over a sorted array, dividing the array into halves and focusing the search accordingly.

### Working of Linear Search
Linear search is straightforward:
1. **Input**: An array of numbers and the number you want to find.
2. **Process**: Traverse each element of the array one by one. Compare each element to the target number.
3. **Output**: Return `1` if the number is found, and `0` if it's not.

Linear search doesn't require the array to be sorted. It simply goes through each element until it either finds the target number or reaches the end.

#### Code Example for Linear Search:
```c
int LinearS(int a[], int a_size, int number) {
    for (size_t i = 0; i < a_size; i++) {
        if (a[i] == number) {
            return 1; // Number found
        }
    }
    return 0; // Number not found
}
```

### Working of Binary Search
Binary search only works on **sorted arrays**. It’s more efficient than linear search:
1. **Input**: A sorted array of numbers and the number to find.
2. **Process**: The array is divided into two halves:
   - If the target number is equal to the middle element, the search ends.
   - If the target number is smaller, search the left half.
   - If the target number is larger, search the right half.
   This process continues until the number is found or the array cannot be divided further.
3. **Output**: Returns `1` if the number is found, otherwise `0`.

#### Code Example for Binary Search:
```c
int BinaryS(int a[], int a_size, int number) {
    int low = 0, high = a_size - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2; // Find middle index
        
        if (number == a[low] || number == a[high] || number == a[mid]) {
            return 1; // Number found
        } else if (number > a[mid]) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }
    return 0; // Number not found
}
```

## Conclusion
This repository demonstrates two basic but important searching techniques in C programming:
- **Linear Search**: Easy to implement, but not as efficient for large data sets.
- **Binary Search**: More efficient for large, sorted data sets, reducing the number of comparisons significantly.