#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 2000001
int queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

int main() {
	int count;
	int element;
	char string[10];
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%s", string);
		if (!strcmp(string, "push")) {
			scanf("%d", &element);
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			queue[rear] = element;
		}
		else if (!strcmp(string, "pop")) {
			if (rear == front) printf("-1\n");
			else {
				printf("%d\n", queue[(front + 1) % MAX_QUEUE_SIZE]);
				front = (front + 1) % MAX_QUEUE_SIZE;
			}
		}
		else if (!strcmp(string, "size")) {
			if (rear >= front) printf("%d\n", rear - front);
			else printf("%d\n", MAX_QUEUE_SIZE - front + rear);
		}
		else if (!strcmp(string, "empty")) {
			if (rear == front) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(string, "front")) {
			if (rear == front) printf("-1\n");
			else printf("%d\n", queue[front+1]);
		}
		else if (!strcmp(string, "back")) {
			if (rear == front) printf("-1\n");
			else printf("%d\n", queue[rear]);
		}
	}
	return 0;
}