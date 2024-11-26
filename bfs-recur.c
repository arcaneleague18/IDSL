#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1)
        return -1;
    int v = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return v;
}

int isEmpty() {
    return front == -1;
}

void BFS_recursive() {
    if (isEmpty())
        return;

    int v = dequeue();
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            enqueue(i);
            visited[i] = 1;
        }
    }

    BFS_recursive();
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;
    BFS_recursive();
}

int main() {
    int edges, v1, v2, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1; // Assuming undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    BFS(start);

    return 0;
}
