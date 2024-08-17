#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int arr[8];

void DFS(int depth) {
    int i;
    if (depth == M) {
        for (i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else {
        for (i = 1; i <= N; i++) {
            arr[depth] = i;
            DFS(depth + 1);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    DFS(0);
    return 0;
}
