#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, M, res = 0;
	int pack[50];
	int one[50];
	scanf("%d %d", &N, &M);
	scanf("%d %d", &pack[0], &one[0]);
	int min_pack = pack[0];
	int min_one = one[0];

	// 패키지, 낱개 가격 배열에서 최솟값 탐색
	for (int i = 1; i < M; i++) {
		scanf("%d %d", &pack[i], &one[i]);
		if (pack[i] < min_pack) min_pack = pack[i];
		if (one[i] < min_one) min_one = one[i];
	}

	// 낱개 가격이 가장 낮은 경우
	if (6 * min_one < min_pack) {
		printf("%d", min_one * N);
	}

	else {
		while (N >= 6) {
			N = N - 6;
			res = res + min_pack;
		}

		// 남은 낱개의 가격이 패키지 가격보다 비싼 경우
		if (min_one * N > min_pack) {
			res = res + min_pack;
		}
		else {
			res = res + min_one * N;
		}
		printf("%d", res);
	}
	return 0;
}