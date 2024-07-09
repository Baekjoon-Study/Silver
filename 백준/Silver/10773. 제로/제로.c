#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100001];
int top = -1;

int main() {
	int count;
	scanf("%d", &count);
	getchar();
	int num;

	for (int i = 0; i < count; i++) {
		scanf("%d", &num);
		if (num == 0) {
			top--;
		}
		else {
			stack[++top] = num;
		}
	}
	int sum = 0;
	for (int i = 0; i <= top; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
	return 0;
}