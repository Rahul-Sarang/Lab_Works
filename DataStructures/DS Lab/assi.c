#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeAlternate(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* res = a;
    while (a && b) {
        struct Node* temp = b->next;
        b->next = a->next;
        a->next = b;
        a = b->next;
        b = temp;
    }
    return res;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *a = NULL, *b = NULL, *temp;
    int i, arr1[] = {1, 2, 3, 4}, arr2[] = {5, 6, 7};

    for (i = 3; i >= 0; i--) {
        temp = malloc(sizeof(struct Node));
        temp->data = arr1[i];
        temp->next = a;
        a = temp;
    }

    for (i = 2; i >= 0; i--) {
        temp = malloc(sizeof(struct Node));
        temp->data = arr2[i];
        temp->next = b;
        b = temp;
    }

    printf("List 1: ");
    printList(a);
    printf("List 2: ");
    printList(b);

    a = mergeAlternate(a, b);

    printf("Merged List: ");
    printList(a);

    return 0;
}