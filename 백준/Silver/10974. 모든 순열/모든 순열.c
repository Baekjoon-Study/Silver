#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int N;
int arr[9]; // 현재 dfs로 거쳐온 정점들 기록하는 배열
bool visited[9]; // 정점마다 dfs로 방문했는지 기록하는 배열

void dfs(int depth) {
    // 출력하고자 하는 순열의 길이와 dfs 깊이가 같다면 출력
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    // 사전순으로 출력하도록 1부터 시작
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) { // 정점 i를 방문하지 않았다면
            visited[i] = true; // 방문했다고 표시
            arr[depth] = i; // arr에 현재 정점삽입
            dfs(depth + 1);
            visited[i] = false; // 다른 순열의 dfs를 위해 원상복구
        }
    }
}

int main() {
    scanf("%d", &N);

    dfs(0);

    return 0;
}