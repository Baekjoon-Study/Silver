#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10001
typedef int element;
typedef struct DequeType {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

// ť �ʱ�ȭ �Լ�
void init(DequeType *q) {
	q->front = q->rear = 0;
}

// ������� ���� �Լ�
int is_empty(DequeType* q) {
	if (q->front == q->rear) return 1;
	return 0;
}

// ��ȭ���� ���� �Լ�
int is_full(DequeType* q) {
	// front�� ó�� �ε���, rear�� ������ �ε����� ��� ���
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) return 1;
	return 0;
}

// rear�� ������ ����(ť������ enqueue�� ����)
int add_rear(DequeType* q, element item) {
	if (is_full(q)) return -1;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	return 0;
}

// front���� ������ ��ȯ �� ����(ť������ dequeue�� ����)
element delete_front(DequeType* q) {
	if (is_empty(q)) return -1;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int add_front(DequeType* q, element item) {
	if (is_full(q)) return -1;
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return 0;
}

element delete_rear(DequeType* q) {
	if (is_empty(q)) return -1;
	element val = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return val;
}

// ť�� ����ִ� ������ ���� ��ȯ �Լ�
int Size(DequeType* q) {
	if (q->rear >= q->front) return q->rear - q->front;
	else return MAX_QUEUE_SIZE - (q->front - q->rear);
}

element front(DequeType* q) {
	if (is_empty(q)) return -1;
	else return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element rear(DequeType* q) {
	if (is_empty(q)) return -1;
	else return q->data[q->rear];
}

int main() {
	DequeType q;
	init(&q);
	int count, item;
	char string[11];

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%s", string);

		if (!strcmp(string, "push_front")) {
			scanf("%d", &item);
			add_front(&q, item);
		}

		else if (!strcmp(string, "push_back")) {
			scanf("%d", &item);
			add_rear(&q, item);
		}

		else if (!strcmp(string, "pop_front")) {
			printf("%d\n", delete_front(&q));
		}

		else if (!strcmp(string, "pop_back")) {
			printf("%d\n", delete_rear(&q));
		}

		else if (!strcmp(string, "size")) {
			printf("%d\n", Size(&q));
		}

		else if (!strcmp(string, "empty")) {
			printf("%d\n", is_empty(&q));
		}

		else if (!strcmp(string, "front")) {
			printf("%d\n", front(&q));
		}
		
		else if (!strcmp(string, "back")) {
			printf("%d\n", rear(&q));
		}
	}

	return 0;
}