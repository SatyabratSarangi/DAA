#include <stdio.h>

int graph[20][20], visited[20];

void dfs(int start, int n) {
    int i;
    visited[start] = 1;
    printf("%d ", start);

    for (i = 1; i <= n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
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

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(start, n);

    printf("\n");
    return 0;
}
