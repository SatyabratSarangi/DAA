#include <stdio.h>
#define INF 9999
int graph[20][20], dist[20], visited[20];

int findMinVertex(int n) {
    int i, min = INF, index = -1;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int n, int src) {
    int i, j;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (i = 0; i < n - 1; i++) {
        int u = findMinVertex(n);
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (graph[u][j] != 0 && visited[j] == 0 && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printf("\nShortest distances from source %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("To %d -> %d\n", i, dist[i]);
    }
}
int main() {
    int n, i, j, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 means no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(n, src);
    return 0;
}
