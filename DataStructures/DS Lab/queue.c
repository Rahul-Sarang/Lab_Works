#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int n;  
void enqueue(int x) {
    if (rear == n - 1) {
        printf("Queue full\n");
    } else {
        if (front == -1 && rear == -1) { 
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = x;
        printf("Added: %d\n", x);
    }
}


void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue empty\n");
    } else {
        printf("Removed: %d\n", queue[front]);
        if (front == rear) { 
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {
    printf("Enter size of queue :");
    scanf("%d", &n);
    int choice, item;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display \n4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Existing....\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

