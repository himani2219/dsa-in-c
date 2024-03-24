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
void insertAtBeg(struct node** head, int data){
    struct node* newnode = createNode(data);
    newnode->next=*head;
    *head = newnode;
}

//function for inserting node at end
void insertAtEnd(struct node** head, int data){
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
void insertAt(struct node* head, int data, int ind){
    if(ind<=0){
        printf("Invalid position!");
        return;
    }
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
   struct node* head = NULL;
   insertAtBeg(&head,10);
   insertAtBeg(&head,1);
   insertAtBeg(&head,90);
   insertAtBeg(&head,16);

   print(head);

    return 0;
}

