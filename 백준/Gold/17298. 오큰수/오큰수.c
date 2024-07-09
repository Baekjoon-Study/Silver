#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 1000001
int array[MAX_STACK_SIZE];
int res[MAX_STACK_SIZE];
int stack[MAX_STACK_SIZE];
int top = -1;

int main() {
	int size;
	scanf("%d", &size);
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}

	// 가장 오른쪽에 있는 수부터 시작
	stack[++top] = array[size - 1];
	res[size - 1] = -1;

	for (int i = size - 2; i > -1; i--) {
		// 오른쪽의 숫자가 왼쪽 숫자보다 큰 경우
		if (stack[top] > array[i]) {
			res[i] = stack[top];
			stack[++top] = array[i];
		}
		// 왼쪽의 숫자가 오른쪽 숫자보다 큰 경우
		else {
			while (top != -1) {
				top--;
				// 오큰수가 없는 경우 (오른쪽의 숫자들이 모두 자신보다 작을 때)
				if (top == -1) {
					stack[++top] = array[i];
					res[i] = -1;
					break;
				}
				// 다음 오른쪽 수가 더 큰 경우 오큰수
				else if (stack[top] > array[i]) {
					res[i] = stack[top];
					stack[++top] = array[i];
					break;
				}
			}
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}