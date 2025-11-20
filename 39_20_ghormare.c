#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjList;
    int* visited;
};

struct Stack {
    int items[SIZE];
    int top;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

struct Stack* createStack() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

void topologicalSortUtil(struct Graph* graph, int v, struct Stack* stack) {
    graph->visited[v] = 1;
    struct Node* temp = graph->adjList[v];
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            topologicalSortUtil(graph, temp->vertex, stack);
        }
        temp = temp->next;
    }
    push(stack, v);
}

void topologicalSort(struct Graph* graph) {
    struct Stack* stack = createStack();
    for (int i = 0; i < graph->vertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i, stack);
        }
    }
    while (stack->top != -1) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(SIZE);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);
    return 0;
}
