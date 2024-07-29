#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 1001

int main() {
	int front = -1;
	int rear = -1;
	int q[MAX_QUEUE_SIZE];

	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	// 1부터 n까지 큐 채우기
	for (int i = 0; i < n; i++) {
		q[++rear] = i + 1;
	}

	printf("<");
	// 큐의 요소로 n-1개만큼 순열 출력
	for (int i = 0; i < n-1; i++) {
		// k번째 횟수에는 dequeue 및 출력, 그 외에는 dequeue & enqueue
		for (int j = 0; j < k; j++) {
			if (j == k-1) {
				printf("%d, ", q[(front + 1) % n]);
				front = (front + 1) % n;

			}
			else {
				rear = (rear + 1) % n;
				q[rear] = q[(front+1) % n];
				front = (front + 1) % n;
			}
		}
	}
	// 마지막 요소 출력
	printf("%d>", q[(front+1) % n]);
	return 0;

}