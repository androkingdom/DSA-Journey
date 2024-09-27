#include <stdio.h> 

/*
// Linear Search :-
// ---------------------
// - Array can be sorted or unsorted.
// - It traverses along the entire array until it finds the given number.
// - If the number is found, it returns 1, otherwise it returns 0.
*/
int LinearS(int a[], int a_size, int number){
    for (size_t i = 0; i < a_size; i++){
        if (a[i] == number){ 
            return 1; // Return 1 if the number is found
        }
    }
    return 0; // Return 0 if the number is not found
}

/*
// Binary Search :-
// ---------------------
// - Array should be sorted.
// - It focuses on 3 factors: `low`, `mid`, and `high`.
// - The algorithm repeatedly divides the search space in half.
// - If the number is found, it returns 1, otherwise it returns 0.
*/
int BinaryS(int a[], int a_size, int number){
    int low = 0, high = a_size - 1, mid;
    
    while (low <= high){ 
        mid = (low + high) / 2; // Calculate the mid index
        
        if (number == a[low] || number == a[high] || number == a[mid]){
            return 1; // Return 1 if the number is found at low, high, or mid
        }
        else if (number > a[mid]){
            low = mid + 1; // Search in the right half of the array
        }
        else {
            high = mid - 1; // Search in the left half of the array
        }
    }
    return 0; // Return 0 if the number is not found
}

int main(){
    int array[] = {1, 2, 39, 60, 66, 81, 90, 100}; // Example sorted array
    
    // Test Linear Search
    printf("%d\n", LinearS(array, 8, 2)); // Expected output: 1 (found)
    
    // Test Binary Search
    printf("%d\n", BinaryS(array, 8, 2)); // Expected output: 1 (found)
    
    return 0;
}
