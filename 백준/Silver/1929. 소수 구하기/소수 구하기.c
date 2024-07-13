#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int M, N;
	int PrimeNumArray[1000001];
	for (int i = 0; i < 1000001; i++) {
		PrimeNumArray[i] = i;
	}
	PrimeNumArray[1] = 0;

	for (int i = 2; i < 500000; i++) {
		int j = 2;
		while (i * j < 1000001) {
			if (PrimeNumArray[i * j] != 0) {
				PrimeNumArray[i * j] = 0;
			}
			j++;
		}
	}
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++) {
		if (PrimeNumArray[i] != 0) {
			printf("%d\n", PrimeNumArray[i]);
		}
	}
	return 0;
}