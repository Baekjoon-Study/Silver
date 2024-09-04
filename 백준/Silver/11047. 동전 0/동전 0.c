#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N, K, count = 0, coin[10];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    for (int i = N - 1; i >= 0; i--) {  // 큰 단위 동전부터 탐색
        if (coin[i] <= K) {              // 현재 동전으로 줄일 수 있으면
            count += K / coin[i];        // 사용할 동전 개수를 더함
            K %= coin[i];                // 남은 금액 갱신
        }
    }

    printf("%d", count);              
    return 0;
}