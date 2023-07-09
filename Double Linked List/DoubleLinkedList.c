#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

int Size(struct Node* head){

    struct Node* temp = head;
    if(temp == NULL){
        return 0;
    }
    int size = 0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;

}

void Print(struct Node* head){
    struct Node* temp = head;
    struct Node* rev;

    printf("\nCurrent List is : start->");

    if(temp==NULL){
        printf("Empty List..");
        return;
    }

    while(temp != NULL){
        printf("%d->",temp->data);
        rev = temp;
        temp=temp->next;
    }

    printf("end\n");

    printf("\n List in Reverse Order : end->");

    while(rev != NULL){
        printf("%d->",rev->data);
        rev = rev->prev;
    }

    printf("start\n");

    return;
}

void Insert(struct Node** head, int pos, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    int size = Size(*head);
   
    if(pos>size){
        pos = 0;
    }
    if(pos==1){
   
        //Inserting at begining
        temp->prev = newNode;
        newNode->next = temp;
        *head = newNode;
        return;
    }
    if(pos == 0){
        //Inserting at Last 
  
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
    for (int i = 1; i < pos-1; i++){
        temp=temp->next;
    }
    struct Node* temp1 = temp->next;
    newNode->next = temp1;
    newNode->prev = temp;
    temp->next = newNode;
    temp1->prev = newNode; 
    return;
}

void Delete(struct Node** head, int pos){

    struct Node* temp = *head;
    int size = Size(temp);

    if(temp == NULL){
        printf("Invalid Position..\n");
        return;
    }

    if(pos>size|pos==0){
        printf("Invalid Position...\n");
        return;
    }

    if(size==1 & pos==1){
       *head = NULL;
       free(temp);
       return; 
    }

    if(pos==1){
        *head = temp->next;
        temp->next->prev = NULL;
        free(temp);
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    struct Node* temp1 = temp->next;
    if(pos==size){
        temp->next=NULL;
        free(temp1);
        return;   
    }

    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
    return;

}

int main(){
    struct Node* head = NULL;
    Insert(&head,1,1);
    Print(head);
    Insert(&head,2,2);
    Print(head);
    Insert(&head,3,3);
    Print(head);
    Insert(&head,4,5);
    Print(head);
    Insert(&head,4,4);
    Print(head);
    printf("Success..\n");
    Delete(&head,4);
    Print(head);
    Delete(&head,4);
    Print(head);
}