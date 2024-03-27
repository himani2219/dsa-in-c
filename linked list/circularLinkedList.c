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
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(list->head==NULL){
        list->head=newnode;
        list->tail=newnode;
        newnode->next=NULL;
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
    scanf("%d", &data);
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

// insertion at specific index
void insertAt(struct LinkedList* list){
    int data, ind;
    printf("Enter index: ");
    scanf("%d", &ind);

    if(ind<0){
        printf("Invalid index!");
        return;
    }

    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);

    if(ind==0){        
        if(list->head==NULL){
            list->head=newnode;
            list->tail=newnode;
        }
        else{
            newnode->next=list->head;
            list->tail->next=newnode;
            list->head=newnode;
        }
        return;
    }

    int count =0;
    struct node* temp = list->head;
    while(temp!=NULL && count<ind-1){
        temp=temp->next;
        count++;
    }

    if(temp==NULL){
        printf("Invalid position!");
        return;
    }

    if(temp->next==NULL){
        list->tail->next=newnode;
        newnode->next=list->head;
        list->tail=newnode;
    }

    else{
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

//traverse list
void print(struct LinkedList* list){
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = list->head;
    printf("%d", temp->data);
    temp=temp->next;
    while(temp!=list->head){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
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
        // case 5 : delFromBeg(list);
        //     break;
        // case 6 : delFromEnd(list);
        //     break;
        // case 7 : delFromPos(list);
        //     break;
        case 8 : return 0;
            break;
        
        default: printf("Invalid option: ");
            break;
        }
    }
    while(1);
    return 0;
}
