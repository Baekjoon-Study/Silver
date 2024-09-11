#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int visited[101];
int graph[101][101];
int count = 0;

void DFS(int start) {
	count++;
	visited[start] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[start][i] && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	int start, end;
	scanf("%d", &N); // 정점의 수
	scanf("%d", &M); // 간선의 수

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		graph[start][end] = 1;
		graph[end][start] = 1;
	}
	DFS(1);
	printf("%d", count - 1);
	return 0;
}