#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct LinkedList{
    struct node* head;
    struct node* tail;
};

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

struct LinkedList* createLinkedList(){
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    return list;
}

void insertAtBeg(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        list->head=newnode;
        list->tail=newnode;
    }
    else{
        newnode->next=list->head;
        list->head->prev=newnode;
        list->tail->next=newnode;
        newnode->prev=list->tail;
        list->head=newnode;
    }
}

void insertAtEnd(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        list->head=newnode;
        list->tail=newnode;
    }
    else{
        list->tail->next=newnode;
        newnode->prev=list->tail;
        newnode->next=list->head;
        list->head->prev=newnode;
        list->tail=newnode;
    }
}

void insertAt(struct LinkedList* list){
    int ind, data;
    printf("Enter index: ");
    scanf("%d", &ind);
    if(ind<0){
        printf("Invalid index!");
        return;
    }
    if(ind==0){
        insertAtBeg(list);
        return;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    int count =0;
    struct node* temp = list->head;
    while(count<ind-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==list->head){
        printf("Invalid index!");
        return;
    }
    if(temp->next==list->head){
        list->tail->next=newnode;
        newnode->prev=list->tail;
        newnode->next=list->head;
        list->head->prev=newnode;
        list->tail=newnode;
    }
    else{
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}

void delFromBeg(struct LinkedList* list){
    if(list->head==NULL){
        printf("List is empty!");
    }
    else{
        struct node* temp = list->head;
        list->head=temp->next;
        list->head->prev=list->tail;
        list->tail->next=list->head;
        free(temp);
    }
}

void delFromEnd(struct LinkedList* list){
    if(list->head==NULL){
        printf("List is empty!");
    }
    else{
        struct node* temp = list->tail;
        list->tail=temp->prev;
        list->tail->next=list->head;
        list->head->prev=list->tail;
        free(temp);
    }
}

void delFromPos(struct LinkedList* list){
    if(list->head==NULL){
        printf("List is empty!");
        return;
    }
    int ind;
    printf("Enter index: ");
    scanf("%d", &ind);
    if(ind<0){
        printf("Invalid index!");
        return;
    }
    if(ind==0){
        delFromBeg(list);
        return;
    }
    int count = 0;
    struct node* temp = list->head;
    while(count<ind){
        temp=temp->next;
    }
    if(temp->next==list->head){
        delFromEnd(list);
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    
}

void print(struct LinkedList* list){
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = list->head;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=list->head);
    printf("\n");
}

int main(){
    int option;
    struct LinkedList* list = createLinkedList();  
    do{
        printf("\nSelect the operation to be performed on linked list: ");
        printf("\n1.\tDisplay list \n2.\tInsertion at beginning. \n3.\tInsertion at end. \n4.\tInsertion at specific position. \n5.\tDelete from beginning. \n6.\tDelete from end. \n7.\tDelete from specific index. \n8.\tExit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1 : print(list);
            break;
        case 2 : insertAtBeg(list);
            break;
        case 3 : insertAtEnd(list);
            break;
        case 4 : insertAt(list);
            break;
        case 5 : delFromBeg(list);
            break;
        case 6 : delFromEnd(list);
            break;
        case 7 : delFromPos(list);
            break;
        case 8 : return 0;
            break;
        
        default: printf("Invalid option: ");
            break;
        }
    }
    while(1);
    return 0;
}