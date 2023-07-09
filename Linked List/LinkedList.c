#include <stdio.h>
#include <stdlib.h>

struct Node{
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
    printf("\nCurrent List is : ");
    if(temp==NULL){
        printf("Empty List..");
        return;
    }
    while(temp != NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("end\n");
    return;

}

void ReversePrint(struct Node* p){
    if(p == NULL){
        printf("Printing list from last.. :\n");
        return;
    }
    ReversePrint(p->next);
    printf("%d->",p->data);
}

void Insert(struct Node** head,int pos, int data){

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    int size = Size(*head);
    if(pos>size){
        pos=0;
    }
    if(*head==NULL){
        //Empty List
        *head=temp;
        return;
    }

    if(pos == 1){ 
        //Begining of List
        temp->next = *head;
        *head = temp;
        return;
    } 
    else if(pos == 0){
        //End of List
        struct Node* temp1 = *head;
        while(temp1->next!=NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
        return;
    } else{
        struct Node* temp1 = *head;
        for(int i=0;i<pos-2;i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
        return;
    }
    
}

void Delete(struct Node** head,int pos){

    int size = Size(*head);
    struct Node* temp = *head;

    if(pos>size){
        printf("Invalid position");
        return;
    }
    if( size == 1){
        free(temp);
        *head=NULL;
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

void Reverse(struct Node** head){
    if(*head == NULL){
        printf("\nCannot reverse...");
        return; 
    }
    int size = Size(*head);
    if(size == 1){
        printf("\nsingle noded list...");
        return;
    }
    struct Node *prev,*current,*next;
    current = *head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return;
}

void recursiveReverse(struct Node** head,struct Node* p){
    if(p->next == NULL){
        *head=p;
        return;
    }
    recursiveReverse(head,p->next);
    struct Node* q = p->next;
    q->next=p;
    p->next=NULL;
}

int main(){
    struct Node* head = NULL;
    Insert(&head,1,1);
    Insert(&head,1,2);
    Insert(&head,0,5);
    Insert(&head,3,6);
    Print(head);
    int size = Size(head);
    printf("\nsize of the list is: %d",size);
    Insert(&head,3,7);
    printf("\nBefore deleting element :");
    Print(head);
    Delete(&head,10);
    Delete(&head,3);
    printf("\nSize of list is: %d",Size(head));
    Print(head);
    Delete(&head,3);
    // printf("\nSize of list is: %d",Size());
    Print(head);
    recursiveReverse(&head,head);
    // Reverse(&head);
    Print(head);
    // ReversePrint(head);
    // Delete(1);
    // Delete(1);
    // Print();
    // Reverse();
    // printf("\n%d",Size());
    // Delete(1);
    // Print(); 
    // printf("\n%d",Size());
}