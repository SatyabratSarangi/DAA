#include <stdio.h>
#define V 5
#define INF 9999

int find(int parent[], int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[yset] = xset;
}

void kruskal(int graph[V][V]) {
    int parent[V];
    int edges = 0, min, a, b;
    printf("Edge\tWeight\n");

    for(int i = 0; i < V; i++)
        parent[i] = i;

    while(edges < V - 1) {
        min = INF;
        a = -1;
        b = -1;

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(graph[i][j] < min && graph[i][j] != 0) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int x = find(parent, a);
        int y = find(parent, b);

        if(x != y) {
            printf("%d - %d\t%d\n", a, b, min);
            unionSet(parent, x, y);
            edges++;
        }

        graph[a][b] = graph[b][a] = INF;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    kruskal(graph);
    return 0;
}
