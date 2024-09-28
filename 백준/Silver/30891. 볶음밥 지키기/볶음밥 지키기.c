#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_N 100
#define MAX_R 100

typedef struct {
    int x;
    int y;
} Rice;

int main() {
    int N, R;
    Rice rice[MAX_N];

    // 입력 받기
    scanf("%d %d", &N, &R);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &rice[i].x, &rice[i].y);
    }

    int max_count = 0;
    int best_x = 0, best_y = 0;

    // 가능한 모든 중심 좌표 (X, Y) 탐색
    for (int X = -100; X <= 100; X++) {
        for (int Y = -100; Y <= 100; Y++) {
            int count = 0;

            // 현재 중심 (X, Y)에서 지킬 수 있는 밥알 수 세기
            for (int i = 0; i < N; i++) {
                if (sqrt((X - rice[i].x) * (X - rice[i].x) + (Y - rice[i].y) * (Y - rice[i].y)) <= R) {
                    count++;
                }
            }

            // 최대 밥알 수 업데이트
            if (count > max_count) {
                max_count = count;
                best_x = X;
                best_y = Y;
            }
        }
    }

    // 결과 출력
    printf("%d %d\n", best_x, best_y);
    return 0;
}
