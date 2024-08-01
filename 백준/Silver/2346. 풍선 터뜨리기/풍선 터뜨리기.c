#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_QUEUE_SIZE 1002
typedef int element;
typedef struct DequeType {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

// 큐 초기화 함수
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

// front에 데이터 삽입
int add_front(DequeType* q, element item) {
	if (is_full(q)) return -1;
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return 0;
}

//rear에서 데이터 반환 및 삭제
element delete_rear(DequeType* q) {
	if (is_empty(q)) return -1;
	element val = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return val;
}

int main() {
	DequeType q;
	init(&q);
	int N;
	int balloon_num[MAX_QUEUE_SIZE];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		add_rear(&q, i + 1);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &balloon_num[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", q.data[q.front + 1]);
		int val = balloon_num[q.data[q.front + 1] - 1];
		delete_front(&q);

		if (val < 0) {
			for (int j = 0; j < -1 * val; j++) {
				add_front(&q, delete_rear(&q));
			}
		}

		else {
			for (int j = 0; j < val - 1; j++) {
				add_rear(&q, delete_front(&q));
			}
		}
	}
	return 0;
}