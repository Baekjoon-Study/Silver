#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

int main() {
	char stack[100];
	int top = -1;
	char string[100];

	scanf("%s", string);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
		char ch = string[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (top != -1 && prec(ch) <= prec(stack[top])) {
				printf("%c", stack[top--]);
			}
			stack[++top] = ch;
			break;
		case '(':
			stack[++top] = ch;
			break;
		case ')':
			while (stack[top] != '(') {
				printf("%c", stack[top--]);
			}
			top--;
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (top != -1) {
		printf("%c", stack[top--]);
	}
	return 0;
}