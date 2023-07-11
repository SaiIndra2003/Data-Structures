#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getSize(struct Node* head){

    if(head == NULL){
        return 0;
    }

    if(head->next == NULL){
        return 1;
    }

    struct Node* temp = head;
    int size=1;

    while(temp->next!=head){ 
        size++;
        temp = temp->next;
    }

    return size;
}

void InsertNode(struct Node** head, int pos, int data){

    struct Node* newNode = CreateNode(data);
    struct Node* temp = *head;
    int size = getSize(*head);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    if(pos==1){ // Inserting at 1st position..
        newNode->next = temp;
        if(size == 1){
            temp->next = newNode;
        }
        *head = newNode;
        return;
    }

    if(pos>size){
        pos = 0;
    }

    if(pos==0){ // Inserting at Last position
        while(temp->next!=*head){
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        return;
    }
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;

}

void DeleteNode(struct Node** head, int pos){

    if(head==NULL){
        printf("Empty List..");
        return;
    }

    int size = getSize(*head);

    if(pos>size){
        printf("Invalid entry... \n");
        return;
    }

    struct Node* temp = *head;
    if(pos == 1){ // 1st node

        struct Node* lastNode = *head;

        while(lastNode->next != *head){
            lastNode = lastNode->next;
        }

        struct Node* deletNode = temp;
        temp=temp->next;
        *head = temp;
        lastNode->next = temp;
        free(deletNode);
        return;

    }
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    struct Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
    return;
}

// void Reverse(struct Node** head){
//     if(*head ==  NULL){
//         printf("Empty List...\n");
//         return;
//     }
//     int size = getSize(*head);
//     if(size == 1){
//         printf("Single Noded List...\n");
//         return;
//     }
//     struct Node *prev,*current,*next;
//     current = *head;
//     prev = NULL;
//     while(current->next != *head){
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//         printf("%d\n",current->data);
//     }
//     next = current->next;
//     current->next = prev;
//     prev = current;
//     current = next;
//     printf("%d\n",current->data);
//     *head = prev;
//     return;
// }

int main(){
    struct Node* head = NULL;
    InsertNode(&head,1,2);
    InsertNode(&head,1,1);
    InsertNode(&head,0,3);
    InsertNode(&head,4,5);
    InsertNode(&head,4,4);
    DeleteNode(&head,5);
    // Reverse(&head);
    printList(head);
}