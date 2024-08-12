#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate(int A[], int N) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        sum += abs(A[i] - A[i + 1]);
    }
    return sum;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 순열생성
void permute(int A[], int l, int r, int* max_val, int N) {
    if (l == r) {
        // 현재 순열에 대해 식의 값을 계산
        int current_val = calculate(A, N);
        // 최대값을 갱신
        if (current_val > *max_val) {
            *max_val = current_val;
        }
    }
    else {
        for (int i = l; i <= r; i++) {
            swap(&A[l], &A[i]);
            permute(A, l + 1, r, max_val, N);
            swap(&A[l], &A[i]); // 백트래킹을 위해 원래 상태로 되돌림
        }
    }
}

int main() {
    int N;
    int A[9];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]); 
    }

    int max_val = 0;
    permute(A, 0, N - 1, &max_val, N);
    printf("%d\n", max_val);

    return 0;
}