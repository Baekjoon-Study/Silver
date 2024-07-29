#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1000001
typedef int element;
typedef struct DequeType {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

// 덱 초기화 함수
void init(DequeType* q) {
	q->front = q->rear = 0;
}

// 공백상태 검출 함수
int is_empty(DequeType* q) {
	if (q->front == q->rear) return 1;
	return 0;
}

// 포화상태 검출 함수
int is_full(DequeType* q) {
	// front가 처음 인덱스, rear가 마지막 인덱스인 경우 고려
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) return 1;
	return 0;
}

// rear에 데이터 삽입(큐에서는 enqueue와 같음)
int add_rear(DequeType* q, element item) {
	if (is_full(q)) return -1;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	return 0;
}

// front에서 데이터 반환 및 삭제(큐에서는 dequeue와 같음)
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

// 덱에 들어있는 데이터 개수 반환 함수
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
	int command;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d", &command);

		if (command == 1) {
			scanf("%d", &item);
			add_front(&q, item);
		}

		else if (command == 2) {
			scanf("%d", &item);
			add_rear(&q, item);
		}

		else if (command == 3) {
			printf("%d\n", delete_front(&q));
		}

		else if (command == 4) {
			printf("%d\n", delete_rear(&q));
		}

		else if (command == 5) {
			printf("%d\n", Size(&q));
		}

		else if (command == 6) {
			printf("%d\n", is_empty(&q));
		}

		else if (command == 7) {
			printf("%d\n", front(&q));
		}

		else if (command == 8) {
			printf("%d\n", rear(&q));
		}
	}

	return 0;
}