#include <stdio.h>
#include <stdlib.h>

//creating node data structure
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

//create structure for doubly linked list
struct LinkedList {
    struct node* head;
    struct node* tail;
};

//function for creation of node
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

//function for creating linked list
struct LinkedList* createLinkedList(){
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    return list;
}

// function for inserting node at beginning of list
void insertAtBeg(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
      list->head=newnode;
      list->tail=newnode;
      return;
      }
    newnode->next=list->head;
    list->head->prev = newnode;
    list->head = newnode;
}

//function for inserting node at end
void insertAtEnd(struct LinkedList* list){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        list->head = newnode;
        list->tail = newnode;
    }
    else{
        list->tail->next=newnode;
        newnode->prev=list->tail;
        list->tail=newnode;
    }
}

//function to insert node at specific index
void insertAt(struct LinkedList* list){
    int ind;
    printf("Enter index: ");
    scanf("%d", &ind);
    if(ind<0){
        printf("Invalid index!");
        return;
    }
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(ind == 0){
        if(list->head==NULL){
        list->head = newnode;
        list->tail = newnode;
    }
    else{
        list->tail->next=newnode;
        newnode->prev=list->tail;
        list->tail=newnode;
    }
    return;
    }
    int count=0;
    struct node* temp = list->head;
    while(temp!=NULL && count < ind-1){
        temp = temp->next;
        count++;
    }
    if(temp==NULL){
        printf("invalid position");
        return;
    }
    newnode->next=temp->next;
    if(temp->next==NULL){
        list->tail=newnode;
    }
    else{
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

//function to delete node from beginning
void delFromBeg(struct LinkedList* list){
    if(list->head==NULL){
        printf("List is empty!");
    }
    else if(list->head==list->tail){
        struct node* temp = list->head;
        list->head=NULL;
        list->tail=NULL;
        free(temp);
    }
    else{
        struct node* temp = list->head;
        list->head=temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
}

//function to delete node from end of list
void delFromEnd(struct LinkedList* list){
    if(list->head==NULL){
        printf("List is empty!");
    }
    else if(list->head==list->tail){
        struct node* temp = list->head;
        list->head=NULL;
        list->tail=NULL;
        free(temp);
    }
    else{
        struct node* temp = list->tail;
        list->tail=temp->prev;
        list->tail->next=NULL;
        free(temp);
    }
}

//delete from specific index
void delFromPos(struct LinkedList* list){
    int ind;
    int count=0;
    struct node* temp = list->head;
    if(list->head == NULL){
        printf("List is Empty!");
        return;
    }
    printf("Enter index of element: ");
    scanf("%d", &ind);
    if(ind<0){
        printf("Invalid index!");
    }
    else if(ind==0){
        if(list->head==list->tail){
            struct node* temp = list->head;
            list->head=NULL;
            list->tail=NULL;
            free(temp);
        }
        else{
            struct node* temp = list->head;
            list->head=temp->next;
            temp->next->prev = NULL;
            free(temp);
        }
    }
    else{
        while(temp!=NULL && count < ind){
            temp = temp->next;
            count++;
        }
        if(temp==NULL){
            printf("invalid position");
            return;
        }
        if(temp==list->tail){
            list->tail=temp->prev;
            temp->prev->next=NULL;
            free(temp);
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}

// traverse list
void print(struct LinkedList* list){
    struct node* temp = list->head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int option;
    struct LinkedList* list = createLinkedList();
    // insertAt(list);   
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
