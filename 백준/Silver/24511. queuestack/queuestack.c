#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char A[100001];
int B[100001];
int C[100001];

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c", &A[i]);
		getchar();
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}
	int M, num;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &C[i]);
	}
	for (int i = N - 1; M != 0 && i >= 0; i--) {
		if (A[i] == '0') {
			printf("%d ", B[i]);
			M--;
		}
	}
	for (int i = 0; i < M; i++) {
		printf("%d ", C[i]);
	}
	return 0;
}