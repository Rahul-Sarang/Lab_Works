#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int visited[MAX];  // Array to track visited vertices
int stack[MAX];    // Stack to store vertices
int top = -1;      // Stack top pointer

// Graph node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to push element onto the stack
void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// Function to pop element from the stack
int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

// DFS function
void dfs(int start, struct Node* adjList[]) {
    push(start);

    while (top > -1) {
        int item = pop();

        if (visited[item] == 0) {
            printf("%d ", item);
            visited[item] = 1;

            struct Node* temp = adjList[item];
            while (temp != NULL) {
                if (visited[temp->data] == 0) {
                    push(temp->data);
                }
                temp = temp->next;
            }
        }
    }
}

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adjList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

int main() {
    int vertices, edges, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency list for each vertex
    struct Node* adjList[vertices];
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Add edges to the graph
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
        addEdge(adjList, dest, src); // For undirected graph, add both ways
    }

    // Input start vertex
    printf("Enter the start vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS
    printf("Depth First Search starting from vertex %d:\n", startVertex);
    dfs(startVertex, adjList);

    return 0;
}
