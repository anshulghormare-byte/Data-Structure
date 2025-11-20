#include <stdio.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[SIZE];

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < SIZE; i++) {
        if (graph[v][i] && !visited[i]) dfs(i);
    }
}

void bfs(int v) {
    int queue[SIZE], front = 0, rear = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < SIZE; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) visited[i] = 0;
    dfs(0);
    printf("\n");
    for (int i = 0; i < SIZE; i++) visited[i] = 0;
    bfs(0);
    printf("\n");
    return 0;
}
