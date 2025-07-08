#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int size, int data) {
    if (top == size - 1) {
        printf("Stack overflow\n");
    } else {
        top = top + 1;
        stack[top] = data;
        printf("Element %d added successfully\n",stack[top]);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;  
    } else {
        int value = stack[top];
        top = top - 1;
        printf("Element removed successfully\n");
        return value;
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void main() {
    int choice, data, size;
    
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    while (1) {
        printf("\nSelect Operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(size, data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Deleted element: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
            	  printf("Existing");
                  exit(0);
                
            default:
                printf("Wrong choice\n");
        }
    }
    
}
