#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int res[8];
int num[8];

void DFS(int depth, int start) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < N; i++) {
		res[depth] = num[i];
		DFS(depth + 1, i);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	// 사전순 출력을 위해 배열 정렬
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	DFS(0, 0);
	return 0;
}