#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int len, res_array_count = 1;
	int stack[1001], input_array[1001], res_array[1001] = { 0 };
	int index = 1;
	int top = -1;

	// 현재 줄 서있는 곳 인원의 배열 생성
	scanf("%d", &len);
	for (int i = 1; i <= len; i++) {
		scanf("%d", &input_array[i]);
	}

	// 현재 줄 서있는 곳과 스택에서 간식받을 차례인 사람이 있는지 확인, 없으면 줄에서 스택으로 push
	while (index <= len) {
		if (input_array[index] == res_array_count) {
			res_array_count++;
			index++;
		}
		else if (res_array_count == stack[top] && top != -1) {
			res_array_count++;
			top--;
		}
		else {
			stack[++top] = input_array[index];
			index++;
		}
	}

	// 스택에서 pop하면서 순서가 맞지 않다면 Sad, 맞다면 Nice 출력
	while (top != -1) {
		if (stack[top] != res_array_count) {
			printf("Sad");
			return 0;
		}
		res_array_count++;
		top--;
	}
	printf("Nice");
	return 0;
}