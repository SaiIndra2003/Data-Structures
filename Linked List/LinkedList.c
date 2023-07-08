#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head; 

int Size(){
    struct Node* temp = head;
    int size = 0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}

void Print(){
    struct Node* temp = head;
    printf("\nCurrent List is : ");
    while(temp != NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("end");
    return;
}

void Insert(int pos, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    int size = Size();
    if(pos>size){
        pos=size;
    }
    if(head==NULL){
        //Empty List
        head=temp;
        return;
    }

    if(pos == 1){ 
        //Begining of List
        temp->next = head;
        head = temp;
        return;
    } 
    else if(pos == 0){
        //End of List
        struct Node* temp1 = head;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
        return;
    } else{
        struct Node* temp1 = head;
        for(int i=0;i<pos-2;i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
        return;
    }
    

}

void Delete(int pos){

    int size = Size();
    struct Node* temp = head;
    if(pos>size){
        printf("Invalid position");
        return;
    }

    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }

    if(pos==size){
        free(temp->next->next);
        temp->next = NULL;
        return;
    }

    struct Node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return;

}


int main(){
    head = NULL;
    Insert(1,1);
    Insert(1,2);
    Insert(0,5);
    Insert(3,6);
    Print();
    int size = Size();
    printf("size of the list is: %d",size);
    Insert(3,7);
    printf("\nBefore deleting element :");
    Print();
    Delete(10);
    Delete(3);
    printf("\nSize of list is: %d",Size());
    Print();
    Delete(3);
    printf("\nSize of list is: %d",Size());
    Print();
}