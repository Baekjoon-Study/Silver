#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int count;
    int stack[500000]; 
    int top = -1; 
    int towers[500000]; 
    int res[500000]; 

    // 타워 높이 입력
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &towers[i]);
    }
    // 스택을 이용해 수신받을 타워 인덱스를 res에 삽입
    for (int i = 0; i < count; i++) {
        // 스택에 담겨있는 타워 중 자기 자신보다 크고 가장 가까운 타워 탐색
        while (top != -1 && towers[stack[top]] < towers[i]) {
            top--;
        }
        // 수신받을 타워가 없을 때(자기 자신이 제일 큰 타워일 때)
        if (top == -1) {
            res[i] = 0;
        }
        // 수신받을 타워가 있을 때
        else {
            res[i] = stack[top] + 1;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}