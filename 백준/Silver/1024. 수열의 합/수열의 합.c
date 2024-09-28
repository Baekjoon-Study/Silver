#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long N;
    int L;

    scanf("%lld %d", &N, &L);

    // 최대 길이 100으로 제한
    for (int length = L; length <= 100; length++) {

        long long sum = (length * (length - 1)) / 2;

        if (N < sum) {
            break; 
        }

        long long a = (N - sum) / length;

        if ((N - sum) % length == 0) {
            for (int i = 0; i < length; i++) {
                printf("%lld ", a + i);
            }
            printf("\n");
            return 0; // 첫 번째로 찾은 수열을 출력하고 종료
        }
    }

    // 조건을 만족하는 수열이 없을 경우
    printf("-1\n");
    return 0;
}
