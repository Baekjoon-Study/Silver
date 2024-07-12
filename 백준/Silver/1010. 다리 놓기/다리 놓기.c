#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int count;
	int N, M;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &N, &M);
		long res = 1;

		if (N == M) {
			printf("1\n"); 
			continue;
		}
		for (int j = N + 1; j <= M; j++) {
			res = (res * j) / (j - N);
		}
		printf("%d\n", res);
	}
	return 0;
}