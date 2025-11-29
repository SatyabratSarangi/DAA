#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int front = 0, rear = -1;

void bfs(int start, int n) {
    int i;
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (i = 1; i <= n; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}
