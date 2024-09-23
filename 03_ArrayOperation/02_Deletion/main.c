#include <stdio.h> 
#include <stdlib.h>

typedef struct list{
    int* ptr;
    int ReservedMemo;
    int UsingMemo;
} list;

void MemoInit(list* a, int NeededMemo, int UsingMemo){
    a->ptr = (int*) malloc(NeededMemo * sizeof(int));
    a->ReservedMemo = NeededMemo;
    a->UsingMemo = UsingMemo;
}

void DataInit(list* a, int array[]){
    for (int i = 0; i < a->UsingMemo; i++){
        a->ptr[i] = array[i];
    }
}

void ListDisplay(list* a){
    for (int i = 0; i < a->UsingMemo; i++){
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

int main(){
    list lst;
    int data[] = {1, 32, 12, 45};
    MemoInit(&lst, 10, 4);
    printf("Using - %d\n", lst.UsingMemo);
    DataInit(&lst, data);
    ListDisplay(&lst);
    DeleteAt(&lst, 3);
    printf("Using - %d\n", lst.UsingMemo);
    ListDisplay(&lst);
    return 0;
}