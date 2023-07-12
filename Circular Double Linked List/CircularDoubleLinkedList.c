#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev, newNode->next = NULL;
    return newNode;
}

int getSize(struct Node* head){

    struct Node* temp = head;
    int size = 0;

    if(temp == NULL){
        return 0;
    }

    if(temp->next == NULL){
        size = 1;
        return size;
    }

    do{
        size++;
        temp = temp->next;
    } while (temp!=head);

    return size;
}

void printList(struct Node* head){

    struct Node* temp = head;

    if(head ==NULL){
        printf("Empty List...");
    }

    printf("List is : ");
    while(temp->next != head){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    return;

}


void Insert(struct Node** head,int data,int pos){

    struct Node* temp = *head;
    struct Node* newNode = createNode(data);
    int size = getSize(*head);

    if(*head == NULL){
        // Empty List
        *head = newNode;
        return;
    }

    if(pos>size){
        pos = 0;
    }

    if(pos==1){
        // Inserting at the begining of List

        printf("Inserting %d at the beggining of the list...\n",data);
        newNode->next = temp; 

        if(size == 1){
            newNode->prev = temp;
            temp->next = newNode;
        }
        else{
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
        }

        temp->prev = newNode;
        *head = newNode;

        return;
    }
    
    if(pos==0){
        // Inserting at Last

        printf("Inserting %d at Last Position... \n", data);
        if(size == 1){

            newNode->prev = temp;
            newNode->next = temp;
            temp->next = newNode;
            temp->prev = newNode;

            return;
        }

        struct Node* lastNode = temp->prev;
        temp->prev = newNode;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = temp;
        return;

    }

    printf("Inserting %d at %dth position...\n",data,pos);

    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    struct Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;
    
    return;

};


void Delete(struct Node** head, int pos){
    struct Node* temp = *head;
    int size = getSize(temp);

    if(temp==NULL){
        printf("Empty List...\n");
        return;
    }

    if (pos>size){
        printf("Invalid position...\n");
        return;
    }

    if(pos==size){
        pos=0;
    }

    if(size == 1){
        *head = NULL;
        free(temp);
        return;
    }

    if(pos==1){

        if( size == 2 ){

            struct Node* next = temp->next;
            *head = next;
            next->prev, next->next = NULL;
            free(temp);
            return; 

        }

        struct Node* prev = temp->prev;
        struct Node* next = temp->next;

        prev->next = next;
        next->prev = prev;
        *head = next;
        free(temp);
        return;
    }

    if(pos==0){

        struct Node* lastNode = temp->prev;
        struct Node* newLastNode = lastNode->prev;
        newLastNode->next = lastNode->next; //Head
        temp->prev = newLastNode;
        free(lastNode);
        return;

    }

    for(int i=0;i<pos-2;i++){

        temp = temp->next;

    }

    struct Node* deleteNode = temp->next;
    struct Node* temp1 = deleteNode->next;
    temp->next = temp1;
    temp1->prev = temp;
    free(deleteNode);
    return;

}


int main(){

    struct Node* head = NULL;

    Insert(&head,1,1);
    Insert(&head,3,0);
    Insert(&head,4,0);
    Insert(&head,2,2);
    Delete(&head,3);
    printList(head);

}