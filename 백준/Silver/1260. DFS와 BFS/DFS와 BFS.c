#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int N, M;

int visited[1001] = { 0 };
int graph[1001][1001] = { 0 }; 
int queue[1001];

void dfs(int v) { 
	visited[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] && !visited[i]) 
			dfs(i);
	}
}

void bfs(int v) { 
	int front = 0;
	int rear = 1;
	int dequeue;

	visited[v] = true;
	printf("%d ", v);
	queue[0] = v;
	while (front < rear) { 
		dequeue = queue[front++]; 
		for (int i = 1; i <= N; i++) {
			if (graph[dequeue][i] && !visited[i]) {
				visited[i] = true;
				printf("%d ", i);
				queue[rear++] = i; 
			}
		}
	}
}

int main() {
	int V;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x][y] = 1; 
		graph[y][x] = 1;
	}

	visited[V] = true;
	dfs(V);

	for (int i = 1; i <= N; i++) 
		visited[i] = false;
	visited[V] = true;
	printf("\n");
	bfs(V);

	return 0;
}