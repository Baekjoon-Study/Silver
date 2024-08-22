#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, s;
int arr[20];
int count = 0;

void DFS(int depth, int sum) {
	if (depth == n) {
		if (sum == s) count++;
		return;
	}
	DFS(depth + 1, sum);
	DFS(depth + 1, sum + arr[depth]);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	DFS(0, 0);
	if (s == 0) count--;
	printf("%d", count);
	return 0;
}