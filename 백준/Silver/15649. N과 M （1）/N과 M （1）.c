#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    dfs(0);

    return 0;
}