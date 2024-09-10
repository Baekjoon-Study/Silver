#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int visited[1001];
int graph[1001][1001];

void DFS(int start) {
	visited[start] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[start][i] && !visited[i]) {
			DFS(i);
		}
	}
}

int main() {
	int start, end;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		graph[start][end] = 1;
		graph[end][start] = 1;
	}

	int component = 0;
	for (int i = 1; i <= N; i++) { // 모든 정점에서 DFS 실행, DFS가 실행되는 connected component마다 component 개수 + 1
		if (!visited[i]) {
			DFS(i);
			component++;
		}
	}
	printf("%d", component);
	return 0;
}