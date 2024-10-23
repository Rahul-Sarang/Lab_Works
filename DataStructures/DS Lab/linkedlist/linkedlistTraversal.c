#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void  Traversal(struct Node* ptr){
    while (ptr!= NULL)
    {
    printf("%d->",ptr->data);
    ptr = ptr->next;
    }
    printf("NULL\n");

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

    Traversal(head);

    return 0;
}