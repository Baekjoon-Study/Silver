#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10001
typedef int element;
typedef struct QueueType {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}QueueType;

// 큐 초기화 함수
void init(QueueType *q) {
	q->front = q->rear = 0;
}

// 공백상태 검출 함수
int is_empty(QueueType* q) {
	if (q->front == q->rear) return 1;
	return 0;
}

// 포화상태 검출 함수
int is_full(QueueType* q) {
	// front가 처음 인덱스, rear가 마지막 인덱스인 경우 고려
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) return 1;
	return 0;
}

// 데이터 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) return -1;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 데이터 반환 및 제거 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) return -1;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 큐에 들어있는 데이터 개수 반환 함수
int size(QueueType* q) {
	if (q->rear >= q->front) return q->rear - q->front;
	else return q->front - q->rear + MAX_QUEUE_SIZE;
}

// 큐에서 가장 앞에 있는 정수 반환
int front(QueueType* q) {
	if (is_empty(q)) return -1;
	return q->data[(q->front) + 1];
}

// 큐에서 가장 뒤에 있는 정수 반환
int rear(QueueType* q) {
	if (is_empty(q)) return -1;
	return q->data[(q->rear)];
}

int main() {
	QueueType q;
	init(&q);
	int count, enqueue_num;
	char string[10];

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%s", string);

		if (strcmp(string, "push") == 0) {
			scanf("%d", &enqueue_num);
			enqueue(&q, enqueue_num);
		}
		else if (strcmp(string, "pop") == 0) {
			printf("%d \n", dequeue(&q));
		}
		else if (strcmp(string, "size") == 0) {
			printf("%d \n", size(&q));
		}
		else if (strcmp(string, "empty") == 0) {
			printf("%d \n", is_empty(&q));
		}
		else if (strcmp(string, "front") == 0) {
			printf("%d \n", front(&q));
		}
		else if (strcmp(string, "back") == 0) {
			printf("%d \n", rear(&q));
		}
	}
	return 0;
}