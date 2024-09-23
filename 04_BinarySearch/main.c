#include <stdio.h> 

/*
// Linear Search :-
---------------------
- Arrary can be sorted or unsorted.
- It Traverse along the end of array untill it find given number.
*/

int LinearS(int a[], int a_size, int number){
    for (size_t i = 0; i < a_size; i++){
        if(a[i] == number){
            return 1;
        }
    }
    return 0;
}
/*
// Binary Search :-
---------------------
- Arrary should be sorted.
- It focuse on 3 factor `low`, `mid`, `high`.
*/

int BinaryS(int a[], int a_size, int number){
    
    while(1){
        int low = a[0], high = a[a_size-1], mid = (low + high)/2;

    }
}

int main(){
    int array[] = {1, 2, 39, 60, 66, 81, 90, 100};
    printf("%d\n", LinearS(array, 2, 8));
    return 0;
}