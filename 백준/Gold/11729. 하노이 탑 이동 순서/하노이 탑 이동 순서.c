#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int tmp, int to)
{
    if (n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else {
        hanoi(n - 1, from, to, tmp);
        printf("%d %d\n", from, to);
        hanoi(n - 1, tmp, from, to);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int res = pow(2, N) - 1;
    printf("%d\n", res);
    hanoi(N, 1, 2, 3);

    return 0;
}