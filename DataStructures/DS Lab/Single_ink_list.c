#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}
void InsertBegin(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->link = *head;
    *head = new_node;
    printf("Node %d inserted at the beginning\n", data);
}
void Delete1st(struct Node** head) {
    if (*head) {
        struct Node* temp = *head;
        *head = (*head)->link;
        printf("Node %d deleted from the front\n", temp->data);
        free(temp);
    }
}
void InsertEnd(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (!*head) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->link) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
    printf("Node %d inserted at the end\n", data);
}
void DeleteEnd(struct Node** head) {
    if (*head) {
        if (!(*head)->link) {
            printf("Node %d deleted from the end\n", (*head)->data);
            free(*head);
            *head = NULL;
        } else {
            struct Node* temp = *head;
            while (temp->link->link) {
                temp = temp->link;
            }
            printf("Node %d deleted from the end\n", temp->link->data);
            free(temp->link);
            temp->link = NULL;
        }
    }
}
void InsertAny(struct Node** head, int data, int position) {
    struct Node* new_node = create_node(data);
    if (position == 0) {
        new_node->link = *head;
        *head = new_node;
    } else {
        struct Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            if (!temp->link) break;
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
    printf("Node %d inserted at position %d\n", data, position);
}
void DeleteAny(struct Node** head, int position) {
    if (*head) {
        if (position == 0) {
            struct Node* temp = *head;
            *head = (*head)->link;
            printf("Node %d deleted at position %d\n", temp->data, position);
            free(temp);
        } else {
            struct Node* temp = *head;
            for (int i = 0; i < position - 1; i++) {
                if (!temp->link) return;
                temp = temp->link;
            }
            struct Node* node_to_delete = temp->link;
            if (node_to_delete) {
                temp->link = node_to_delete->link;
                printf("Node %d deleted at position %d\n", node_to_delete->data, position);
                free(node_to_delete);
            }
        }
    }
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, position;
  while (1) {
        printf("\nLinked List Menu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertBegin(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                InsertAny(&head, data, position);
                break;
            case 4:
                Delete1st(&head);
                break;
            case 5:
                DeleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                DeleteAny(&head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
