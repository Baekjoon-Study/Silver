#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int top = -1;
int stack[1000000];

int main() {
	int count;
	int command;
	int num;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			scanf("%d", &num);
			stack[++top] = num;
			break;
		case 2:
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top--]);
			break;
		case 3:
			printf("%d\n", top + 1);
			break;
		case 4:
			if (top == -1) printf("1\n");
			else printf("0\n");
			break;
		case 5:
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
			break;
		}
	}
	return 0;
}