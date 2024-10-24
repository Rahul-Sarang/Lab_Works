#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int visited[MAX];  // Array to track visited vertices
int queue[MAX];    // Queue to store vertices
int front = -1, rear = -1;  // Queue front and rear pointers

// Graph node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to enqueue an element
void insertq(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = v;
}

// Function to dequeue an element
int deleteq() {
    if (front == -1) {
        return -1;
    }
    int item = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return item;
}

// BFS function
void bfs(int start, struct Node* adjList[]) {
    insertq(start);
    visited[start] = 1;
    printf("%d ", start);

    while (front != -1) {
        int v = deleteq();

        struct Node* temp = adjList[v];
        while (temp != NULL) {
            int w = temp->data;
            if (visited[w] == 0) {
                insertq(w);
                visited[w] = 1;
                printf("%d ", w);
            }
            temp = temp->next;
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
    printf("Enter the start vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS
    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    bfs(startVertex, adjList);

    return 0;
}
