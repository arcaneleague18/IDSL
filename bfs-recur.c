#include <stdio.h>

#define MAX 100 

int graph[MAX][MAX]; 
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void bfsHelper() {
    if (front==rear)
        return;

    int current = queue[front++]; 
    printf("%d ", current);  

    for (int i = 0; i < MAX; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            visited[i] = 1;
            queue[rear++]=i;
        }
    }

    bfsHelper();
}

void bfs(int startNode, int totalNodes) {
    for (int i = 0; i < totalNodes; i++) {
        visited[i] = 0;
    }

    visited[startNode] = 1;
    queue[rear++]=startNode;
    bfsHelper();
}

int main() {
    int totalNodes, edges, u, v, startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &totalNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        graph[v][u] = 1; 
    }

    printf("Enter the start node: ");
    scanf("%d", &startNode);

    printf("BFS Traversal: ");
    bfs(startNode, totalNodes);
    printf("\n");

    return 0;
}