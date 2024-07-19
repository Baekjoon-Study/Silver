#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int div[50];
	long long res;

	scanf("%d", &N);
	scanf("%d", &div[0]);
	int min = div[0];
	int max = div[0];

	for (int i = 1; i < N; i++) {
		scanf("%d", &div[i]);
		if (min > div[i]) min = div[i];
		if (max < div[i]) max = div[i];
	}
	res = max * min;
	printf("%lld", res);
	return 0;
}