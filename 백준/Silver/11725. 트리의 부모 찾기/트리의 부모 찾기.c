#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100001

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[MAX_NODES];
int parent[MAX_NODES];
bool visited[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void dfs(int node) {
    visited[node] = true;
    Node* current = adjList[node];
    while (current != NULL) {
        int adjNode = current->data;
        if (!visited[adjNode]) {
            parent[adjNode] = node;
            dfs(adjNode);
        }
        current = current->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        adjList[i] = NULL;
        visited[i] = false;
        parent[i] = 0;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}