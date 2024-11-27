#include<stdio.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX], front=0, rear=0;

void bfs(int startNode, int totalNodes){
    for(int i=0;i<totalNodes;i++){
        visited[i]=0;
    }
    
    visited[startNode]=1;
    queue[rear++]=startNode;
    
    while(front!=rear){
        int current=queue[front++];
        printf("%d ", current);
    
        for(int i=0;i<MAX;i++){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}
int main(){
    int totalNodes,startNode,u,v, edges;
    printf("Enter number of nodes: ");
    scanf("%d", &totalNodes);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    for(int i=0;i<totalNodes;i++){
        for(int j=0;j<totalNodes;j++){
            graph[i][j]=0;
        }
    }
    
    printf("Enter the edges (u v): \n");
    for(int i=0;i<edges;i++){
        scanf("%d %d", &u,&v);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    
    printf("Enter start node: ");
    scanf("%d", &startNode);
    
    printf("BFS traversal: ");
    bfs(startNode, totalNodes);
    return 0;
}
