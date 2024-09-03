#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(x, y) x > y ? x : y

int main() {
    int level;
    int level_weight[10000] = { 0 };
    int dp[301] = { 0 };

    scanf("%d", &level);
    for (int i = 1; i <= level; i++) {
        scanf("%d", &level_weight[i]);  
    }

    dp[1] = level_weight[1];
    dp[2] = level_weight[1] + level_weight[2];

    for (int i = 3; i <= level; i++) {
        dp[i] = max(dp[i - 2] + level_weight[i], dp[i - 3] + level_weight[i - 1] + level_weight[i]);
    }

    printf("%d", dp[level]);

    return 0;
}