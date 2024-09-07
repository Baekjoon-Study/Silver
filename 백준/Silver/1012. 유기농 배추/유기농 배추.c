#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int graph[51][51], visit[51][51], M, N, K, count;

void DFS(int x, int y) {
    visit[x][y] = 1;
    if (graph[x + 1][y] && !visit[x + 1][y]) DFS(x + 1, y);
    if (graph[x - 1][y] && !visit[x - 1][y]) DFS(x - 1, y);
    if (graph[x][y + 1] && !visit[x][y + 1]) DFS(x, y + 1);
    if (graph[x][y - 1] && !visit[x][y - 1]) DFS(x, y - 1);
}

int main() {
    int T, x, y;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        count = 0;
        scanf("%d %d %d", &M, &N, &K);
        for (int j = 0; j <= M; j++)
            for (int k = 0; k < N; k++) {
                graph[j][k] = 0;
                visit[j][k] = 0;
            }
        for (int j = 0; j < K; j++) {
            scanf("%d %d", &x, &y);
            graph[x][y] = 1;
        }
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                if (graph[j][k] && !visit[j][k]) {
                    DFS(j, k);
                    count++;
                }
        printf("%d\n", count);
    }
}