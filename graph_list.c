#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adjList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src); // Uncomment for undirected graph
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void displayList(Node* adjList[], int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: ", i);
        Node* temp = adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(Node* adjList[], int start, int V) {
    int visited[V];
    for (int i = 0; i < V; i++) visited[i] = 0;

    int queue[V], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp) {
            if (!visited[temp->vertex]) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFSUtil(Node* adjList[], int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    Node* temp = adjList[start];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFSUtil(adjList, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Node* adjList[], int start, int V) {
    int visited[V];
    for (int i = 0; i < V; i++) visited[i] = 0;

    printf("DFS: ");
    DFSUtil(adjList, start, visited);
    printf("\n");
}

int main() {
    int V = 4;
    Node* adjList[V];
    for (int i = 0; i < V; i++) adjList[i] = NULL;

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);

    printf("Adjacency List:\n");
    displayList(adjList, V);

    BFS(adjList, 0, V);
    DFS(adjList, 0, V);

    return 0;
}