#include <stdio.h> 
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* ptr;
} Node;

void Travel(Node* a){
    while (a != NULL){
        printf("%d\t", a->data);
        a = a->ptr;
    }
    printf("\n");
}

Node* InsertAtFirst(Node* head, int newdata){
    Node* new = (Node*) malloc(sizeof(Node));

    new->data = newdata;
    new->ptr = head;
    
    return new;
}

Node* Put(Node* head, int number){
    Node* dummy = head;

    while(dummy->ptr != NULL){
        dummy = dummy->ptr;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    new->data = number;
    new->ptr = NULL;

    dummy->ptr = new;

    return head;
}

Node* InsertAt(Node* head, int index, int number){
    Node* primary = head;
    for (int i = 0; i <= index-1; i++){
        if(i == index-1){
            Node* new = (Node*) malloc(sizeof(Node));
            new->data = number;
            new->ptr = primary->ptr;
            primary->ptr = new;
            return head;
        }
        else{
            primary = primary->ptr;       
        }
    }
    return head;
}

int main(){
    Node* head;
    Node* next1;
    Node* next2;

    head = (Node*) malloc(sizeof(Node));
    next1 = (Node*) malloc(sizeof(Node));
    next2 = (Node*) malloc(sizeof(Node));

    head->data = 12;
    head->ptr = next1;

    next1->data = 142;
    next1->ptr = next2;

    next2->data = 532;
    next2->ptr = NULL;

    printf("Orginal Linked List\n");
    Travel(head);

    printf("\nElement Inserted At First\n");
    head = InsertAtFirst(head, 31);
    Travel(head);

    printf("\nElement Insertion With Index\n");
    head = InsertAt(head, 2,31);
    Travel(head);

    printf("\nElement Insertion At End\n");
    head = Put(head, 101);
    Travel(head);



    return 0;
}