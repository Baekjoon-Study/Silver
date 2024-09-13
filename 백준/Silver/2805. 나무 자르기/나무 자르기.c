#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tree[1000001];

int main(void) {
    int N, M;
    int max = 0;
    int left, right;
    int result = 0;

    long long total;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
        if (max < tree[i])
            max = tree[i];
    }

    left = 0;
    right = max;

    while (left <= right) {
        int mid = (left + right) / 2;
        total = 0;

        for (int i = 0; i < N; i++) {
            if (tree[i] > mid) {
                total += (long long)(tree[i] - mid);  
            }
        }

        if (total >= M) {
            if (result < mid)
                result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%d\n", result);

    return 0;
}
