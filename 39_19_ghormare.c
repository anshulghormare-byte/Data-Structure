#include <stdio.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[SIZE], disc[SIZE], low[SIZE], parent[SIZE], time = 0;

int dfs(int u) {
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    for (int v = 0; v < SIZE; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                if (!dfs(v)) return 0;
                low[u] = low[u] < low[v] ? low[u] : low[v];
                if (parent[u] == -1 && children > 1) return 0;
                if (parent[u] != -1 && low[v] >= disc[u]) return 0;
            } else if (v != parent[u]) {
                low[u] = low[u] < disc[v] ? low[u] : disc[v];
            }
        }
    }
    return 1;
}

int isBiconnected() {
    for (int i = 0; i < SIZE; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    return dfs(0);
}

int main() {
    printf("%s\n", isBiconnected() ? "Bi-connected" : "Not Bi-connected");
    return 0;
}
