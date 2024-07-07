#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int count;
	char string[100001];
	char command;

	// 커서 기준 왼쪽, 오른쪽의 문자들을 담을 스택 선언
	char left_stack[600001];
	int left_top = -1;
	char right_stack[600001];
	int right_top = -1;

	// 문자열 왼쪽 스택에 담기(명령어 입력 전 커서는 가장 오른쪽에 있으므로)
	scanf("%s", string);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		left_stack[++left_top] = string[i];
	}

	scanf("%d", &count);
	getchar();

	
	for (int i = 0; i < count; i++) {
		scanf("%c", &command);
		getchar();

		// 현 커서 위치에 문자 삽입(왼쪽 스택에 삽입)
		if (command == 'P') {
			char ch;
			scanf("%c", &ch);
			getchar();
			left_stack[++left_top] = ch;
		}
		// 커서 오른쪽으로 이동(오른쪽 스택 pop 요소를 왼쪽 스택에 push)
		else if (command == 'D') {
			if (right_top == -1) continue;
			left_stack[++left_top] = right_stack[right_top--];
		}
		// 커서 왼쪽으로 이동(왼쪽 스택 pop 요소를 오른쪽 스택에 push)
		else if (command == 'L') {
			if (left_top == -1) continue;
			right_stack[++right_top] = left_stack[left_top--];
		}
		// 현 커서 위치에서 요소 삭제
		else if (command == 'B') {
			if (left_top == -1) continue;
			left_top--;
		}
	}
	// 왼쪽 스택에 있는 요소들 오른쪽 스택으로 push
	while (left_top != -1) {
		right_stack[++right_top] = left_stack[left_top];
		left_top--;
	}

	while (right_top != -1) {
		printf("%c", right_stack[right_top]);
		right_top--;
	}
	return 0;
}