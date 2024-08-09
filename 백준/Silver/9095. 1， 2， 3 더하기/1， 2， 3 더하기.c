#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T, n;
	int res[11];
	res[0] = 1;
	res[1] = 2;
	res[2] = 4;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		for (int j = 3; j < n; j++) {
			res[j] = res[j - 3] + res[j - 2] + res[j - 1];
		}
		printf("%d\n", res[n - 1]);
	}
	return 0;
}