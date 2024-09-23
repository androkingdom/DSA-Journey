#include <stdio.h> 

void show(int array[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void insertAt(int array[], int index, int size, int number, int max_storage){
    if(index > size && size > max_storage){
        printf("Error: Invalid Range\n");
        return;
    }
    for (int i = size-1; i >= index; i--){
        array[i+1] = array[i];
    }
    array[index] = number;
}

int main(){
    int list[20] = {1, 21, 14, 35,129};
    int total_size = 20, using = 5;
    show(list, using);
    insertAt(list, 3, using, 100, total_size);
    using++;
    show(list, using);

    return 0;
}