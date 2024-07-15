#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

double stack[100];
int top = -1;

int main() {
	int count;
	char string[100];
	int operand[26];
	scanf("%d", &count);
	getchar();
	scanf("%s", string);
	getchar();
	int len = strlen(string);
	int count_string_len = 0;
	int count_operand = 0;

	for (int i = 0; i < count; i++) {
		scanf("%d", &operand[i]);
		getchar();
	}

	while (count_string_len < len) {
		switch (string[count_string_len]) {
		case '+':
			stack[top - 1] = stack[top] + stack[top - 1];
			top--;
			count_string_len++;
			break;
		case '-':
			stack[top - 1] = stack[top - 1] - stack[top];
			top--;
			count_string_len++;
			break;
		case '*':
			stack[top - 1] = stack[top] * stack[top - 1];
			top--;
			count_string_len++;
			break;
		case '/':
			stack[top - 1] = stack[top - 1] / stack[top];
			top--;
			count_string_len++;
			break;
		default:
			stack[++top] = (double)operand[(int)string[count_string_len] - 65];
			count_operand++;
			count_string_len++;
			break;
		}
	}
	printf("%.2lf", stack[top]);
	return 0;
}