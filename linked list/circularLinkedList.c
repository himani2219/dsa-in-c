#include <stdio.h>
#include <stdlib.h>

//creating node data structure
struct node
{
    int data;
    struct node* next;
};

// create linked list structure
struct LinkedList
{
    struct node* head;
    struct node* tail;
};


//function for creation of node
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

// function for creating circular linked list
struct LinkedList* createLinkedList(){
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    return list;
}

//insertion at beginning
void insertAtBeg(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        list->head=newnode;
        list->tail=newnode;
    }
    else{
        newnode->next=list->head;
        list->tail->next=newnode;
        list->head=newnode;
    }
}

//insertion at end
void insertAtEnd(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        list->head=newnode;
        list->tail=newnode;
    }
    else{
        list->tail->next=newnode;
        newnode->next=list->head;
        list->tail=newnode;
    }
}