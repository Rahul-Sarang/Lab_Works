#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int n; 


void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
        printf("Added: %d\n", x);
    } else if ((rear + 1) % n == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % n;
        queue[rear] = x;
        printf("Added: %d\n", x);
        
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Removed: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Removed: %d\n", queue[front]);
        front = (front + 1) % n; 
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
          for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = front; i < n; i++) {
                printf("%d ", queue[i]);
            }
          
        }
        printf("\n");
    }
}

void main() {
    printf("Enter the size of the queue :");
    scanf("%d", &n);
    int choice, item;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
