#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int K, N, res;
    long long mid, top, low, sum = 0;
    int len_array[10000];

    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) {
        scanf("%d", &len_array[i]);
        sum += len_array[i];
    }

    low = 1;
    top = sum / N; 

    while (low <= top) {
        mid = (low + top) / 2;
        res = 0;

        for (int i = 0; i < K; i++) {
            res += len_array[i] / mid;
        }

        if (res >= N) {
            low = mid + 1;
        }
        else {
            top = mid - 1;
        }
    }

    printf("%lld\n", top); 

    return 0;
}