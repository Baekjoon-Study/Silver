#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T, N;
	long long dp[100];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	for (int i = 5; i < 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", dp[N - 1]);
	}
	return 0;
}