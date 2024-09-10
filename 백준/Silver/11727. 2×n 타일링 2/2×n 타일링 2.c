#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int dp[1001];
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}

	printf("%d", dp[n]);
	return 0;
}