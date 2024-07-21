#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	while (N != 1) {
		if (N == 2 || N == 3) {
			printf("%d", N);
			N = 1;
		}
		else{
			for (int i = 2; i <= N / 2; i++) {
				if (N % i == 0) {
					printf("%d\n", i);
					N = N / i;
					break;
				}
				if (i == N / 2 && N % i != 0) {
					printf("%d\n", N);
					N = 1;
				}
			}
		}
		
	}
}