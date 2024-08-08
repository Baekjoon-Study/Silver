#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// i에서 버튼이 하나라도 망가져있으면 0 리턴, 그렇지 않으면 길이 리턴
int length(int i, int array[]) {
	if (i == 0) {
		if (array[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (i) {
		if (array[i % 10]) {
			return 0;
		}
		i /= 10;
		len++;
	}
	return len;
}
int main() {
	int N, M, broken_btn;
	int broken_btn_array[10] = { 0 };
	scanf("%d", &N);
	scanf("%d", &M);

	// 부서진 버튼 입력
	for (int i = 0; i < M; i++) {
		scanf("%d", &broken_btn);
		broken_btn_array[broken_btn] = 1;
	}

	// (+, -만 누른 횟수)와 (숫자로 누른 횟수, +, -를 눌러 맞춘 횟수의 합) 중 최솟값을 탐색
	int min = abs(N - 100); // +, -만 눌러 채널을 맞춘 횟수
	for (int i = 0; i < 1000000; i++) { // 누를 수 있는 버튼은 999999까지
		int len = length(i, broken_btn_array); // 숫자로 채널을 맞춘 횟수(채널 숫자의 길이)
		if (len > 0) {
			int tmp = len + abs(N - i);
			if (min > tmp) min = tmp;
		}
	}
	printf("%d", min);
	return 0;
}