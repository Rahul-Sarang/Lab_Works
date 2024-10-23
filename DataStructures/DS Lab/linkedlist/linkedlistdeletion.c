#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

// Print list
void  Traversal(struct Node* ptr){
    while (ptr!= NULL)
    {
    printf("%d->",ptr->data);
    ptr = ptr->next;
    }
    printf("NULL\n");

}
// Insertion at begnning
struct Node* InsertAtFirst(struct Node* head,int data)
{
   struct Node* ptr=(struct Node*)malloc(sizeof(struct Node)); 
   ptr->next=head;
   ptr->data=data;
   return ptr;
}
// insertion at end
struct Node* InsertAtEnd(struct Node* head,int data)
{
   struct Node* ptr=(struct Node*)malloc(sizeof(struct Node)); 
   ptr->data=data;
   struct Node * temp =head;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=ptr;
   ptr->next=NULL;
   return head;

}
// insertion between 
struct Node* InsertAnywhere(struct Node* head,int data, int postion)
{
   struct Node* ptr=(struct Node*)malloc(sizeof(struct Node)); 
   struct Node* temp=head;
   int i=0;
   while(i!=postion-1){
    temp=temp->next;
    i++;
   }
   ptr->data=data;
   ptr->next=temp->next;
   temp->next=ptr;

}

struct Node* DeletFirst(struct Node* head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
}

struct Node* DeletBtW(struct Node* head){
    struct Node* ptr=head;
    int i=0;
  

}
 
int main(){
    // Memory allocation
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));

    // Link first and second node
    head -> data =7;
    head-> next=second;
    // Link second and third node
    second -> data =10;
    second-> next=third;
   // Link  third fourth node
    third -> data =15;
    third-> next= fourth;
     // Terminate list at fourth node
    fourth -> data =17;
    fourth-> next= NULL;

    printf("Link list before insertion\n");
    Traversal(head);
    //head=InsertAtFirst(head,14);
    // head=InsertAnywhere(head,14,1);
     head=InsertAtEnd(head,89);

    printf("Link list after insertion\n");
    Traversal(head);

    return 0;
}