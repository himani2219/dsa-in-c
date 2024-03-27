#include <stdio.h>
#include <stdlib.h>

//creating node data structure
struct node
{
    int data;
    struct node* next;
};

//function for creation of node
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//function for inserting node at Beginning
void insertAtBeg(struct node** head){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    newnode->next=*head;
    *head = newnode;
}

//function for inserting node at end
void insertAtEnd(struct node** head){
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    if(*head==NULL){
        *head = newnode;
    }
    else{
        struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=newnode;
    }
}

//function for inserting node at a specific position
void insertAt(struct node* head){
    int ind;
    printf("Enter index: ");
    scanf("%d", &ind);
    if(ind<=0){
        printf("Invalid position!");
        return;
    }
    int data;
    printf("Enter element to be inserted: ");
    scanf("%d", &data);
    struct node* newnode = createNode(data);
    struct node* temp = head;
    int count=0;
    while(temp!=NULL && count < ind-1){
        temp = temp->next;
        count++;
    }
    if(temp==NULL){
        printf("Invalid position!");
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

//function for deletion from beginning
void delFromBeg(struct node** head){
    struct node* temp = *head;
    if(*head == NULL){
        printf("List is Empty!");
        return;
    }
    *head=temp->next;
    free(temp);
}

//function for deletion from end
void delFromEnd(struct node** head){
    struct node* temp = head;
    if(*head == NULL){
        printf("List is Empty!");
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

//function for deletion from specific position
void delFromPos(struct node** head){
    int ind, count;
    struct node* temp = *head;
    if(*head == NULL){
        printf("List is Empty!");
        return;
    }
    printf("Enter index of element: ");
    scanf("%d", &ind);
    if(ind==0){
        *head=temp->next;
        free(temp);
    }
    else{
        while (temp!=NULL && count<ind-1)
        {
            temp=temp->next;
            count++;
        }
        if(temp==NULL || temp->next==NULL){
            printf("Invalid position!");
        }
        else{
            struct node* nodeToDelete = temp->next;
            temp->next=nodeToDelete->next;
            free(nodeToDelete);
        }
    }
}

//function to print linked list
void print(struct node* head){
    while(head!=NULL){
        printf("%d ", head->data);
        head=head->next;
    }
    printf("\n");
}

//main function
int main(){
    int option;
   struct node* head = NULL;

    do{
        printf("\nSelect the operation to be performed on linked list: ");
        printf("\n1.\tDisplay list \n2.\tInsertion at beginning. \n3.\tInsertion at end. \n4.\tInsertion at specific position. \n5.\tDelete from beginning. \n6.\tDelete from end. \n7.\tDelete from specific index. \n8.\tExit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1 : print(head);
            break;
        case 2 : insertAtBeg(&head);
            break;
        case 3 : insertAtEnd(&head);
            break;
        case 4 : insertAt(head);
            break;
        case 5 : delFromBeg(&head);
            break;
        case 6 : delFromEnd(&head);
            break;
        case 7 : delFromPos(&head);
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

