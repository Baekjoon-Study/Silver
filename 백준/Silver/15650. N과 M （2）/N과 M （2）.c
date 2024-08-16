#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 9

int N, M;
int arr[MAX]; // 현재 dfs로 거쳐온 정점들 기록하는 배열

void dfs(int depth, int start) {
    // 출력하고자 하는 조합의 길이와 dfs 깊이가 같다면 출력
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    // start부터 시작하여 중복을 피하고 오름차순 조합을 만듦
    for (int i = start; i <= N; i++) {
        arr[depth] = i; // arr에 현재 숫자 삽입
        dfs(depth + 1, i + 1); // 다음 깊이로 들어가며, 다음 숫자부터 시작
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0, 1); // 깊이 0, 시작 숫자 1부터 dfs 시작
    return 0;
}