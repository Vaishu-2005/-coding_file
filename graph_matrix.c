#include <stdio.h>
#define V 4

void displayMatrix(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void BFS(int graph[V][V], int start) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < V; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int graph[V][V], int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(int graph[V][V], int start) {
    int visited[V] = {0};
    printf("DFS: ");
    DFSUtil(graph, start, visited);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    printf("Adjacency Matrix:\n");
    displayMatrix(graph);

    BFS(graph, 0);
    DFS(graph, 0);

    return 0;
}
