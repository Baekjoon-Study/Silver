#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100001

// 스택 선언
int stack[MAX_STACK_SIZE];
int top = -1;
int oper_index = 0;
int seq_index = 0;

// pop, push 연산의 순서를 담을 배열
char oper[2 * MAX_STACK_SIZE];

int main() {
	int count;
	int seq[MAX_STACK_SIZE]; // 수열을 담을 배열
	scanf("%d", &count);

	// 배열에 수열 저장
	for (int i = 0; i < count; i++) {
		scanf("%d", &seq[i]);
	}

	// 1부터 수열의 길이까지 스택에 push
	int push_count = 0;
	while (push_count < count) {
		// 스택의 top 요소와 수열의 요소가 일치하면 pop
		if (stack[top] == seq[seq_index]) {
			top--;
			seq_index++;
			oper[oper_index++] = '-';
		}
		// 일치하지 않으면 push
		else{
			stack[++top] = push_count+1;
			oper[oper_index++] = '+';
			push_count++;
		}
	}

	// pop되지 않은 수열의 요소들이 오름차순으로 정렬돼있지 않으면 NO 출력
	for(int i = seq_index; i < count-1; i++) {
		if (seq[i] < seq[i+1]) {
			printf("NO");
			return 0;
		}
		oper[oper_index] = '-';
		oper_index++;
	}
	oper[oper_index] = '-';


	for (int i = 0; i <= oper_index; i++) {
		printf("%c\n", oper[i]);
	}
	return 0;
}

