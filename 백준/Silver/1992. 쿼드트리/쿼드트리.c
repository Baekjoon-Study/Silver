#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pixel[64][64];

void quad(int x, int y, int N) {
    int ans = pixel[y][x];  

    if (N == 1) {
        printf("%d", ans);
        return;
    }

    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (pixel[i][j] != ans) {
                printf("(");
                quad(x, y, N / 2);        
                quad(x + N / 2, y, N / 2);     
                quad(x, y + N / 2, N / 2);     
                quad(x + N / 2, y + N / 2, N / 2); 
                printf(")");
                return;
            }
        }
    }

    printf("%d", ans);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &pixel[i][j]);
        }
    }

    quad(0, 0, N);

    return 0;
}
