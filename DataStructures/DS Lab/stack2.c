#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>

int stack[100];
int top=-1;
int isFull(int size){if(top ==size-1){return 0;}
                     else{return 1;}return true;}
int isEmpty(int size){ if(top ==size-1){return 0;}
                    else{return 1;}return true;}

void push(int size,int data){
    if(top==size-1){printf("Stack is overflow");return ;}
    else{top=top+1;
    stack[top]=data;
    printf("The Element is added successfully\n");}
}
int pop(){
     if(top==-1){
         printf("Stack underflow\n");
         exit(1);
         }
     int value=stack[top];
     top=top-1;
     printf("The Element is removed successfully\n");
     return value;
}
int peek(){
    if(top==-1) {
         printf("Stack underflow\n");
         exit(1);
    }
     return stack[top];
}
void print(){
    if(top==-1){
         printf("Stack underflow\n");
         return;
    }
    for(int i=top;i>=0;i--){
         printf("%d  ",stack[i]);
    }
     printf("\n");
}
void main()
{
    int choice,data,size;
    printf("Enter the size of stack :");
    scanf("%d",&size);
    while(true){
        printf("\n1 . Push\n2 . Pop\n3 . Print the top element\n4 . Print all elements in the stack\n");
        printf("5 . To check stack is Full\n6 . To check stack is Empty\n7. Quit\n");
        printf("Plese enter your choice :");
        scanf ("%d",&choice);
    
        switch(choice){
            case 1: printf("Enter the Element to be push : ");
                    scanf("%d",&data);
                    push(size,data);
                    break;
            case 2: data=pop();
                    printf("Deleted element from the stack is %d\n",data);
                    break;
            case 3:  printf("The top most element is %d\n",peek());
                     break;
            case 4: print();
                     break;
            case 5: if(isFull(size)==0)
                     {printf("Stack is full");}
                     else{printf("Stack is not full");}
                     break;
            case 6: if(isEmpty(size)==0)
                     {printf("Stack is Empty");}
                     else{printf("Stack is not Empty");}
                     break;
            case 7: exit(0);
            default: printf("wrong choice");
        }
    }
}