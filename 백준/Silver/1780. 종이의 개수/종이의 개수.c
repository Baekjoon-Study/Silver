#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int paper[2200][2200];
int zero = 0, one = 0, minus = 0;

void count(int x, int y, int N) {
	if (N == 1) {
		if (paper[y][x] == 1) one++;
		else if (paper[y][x] == 0) zero++;
		else minus++;
		return;
	}

	
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (paper[i][j] != paper[y][x]) {
				count(x, y, N / 3);
				count(x + N / 3, y, N / 3);
				count(x + 2 * N / 3, y, N / 3); // 1행
				count(x, y + N / 3, N / 3);
				count(x + N / 3, y + N / 3, N / 3);
				count(x + 2 * N / 3, y + N / 3, N / 3); // 2행
				count(x, y + 2 * N / 3, N / 3);
				count(x + N / 3, y + 2 * N / 3, N / 3);
				count(x + 2 * N / 3, y + 2 * N / 3, N / 3); // 3행
				return;
			}
		}
	}

	if (paper[y][x] == 1) one++;
	else if (paper[y][x] == 0) zero++;
	else minus++;
	return;
	
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	count(0, 0, N);
	printf("%d\n%d\n%d\n", minus, zero, one);
}