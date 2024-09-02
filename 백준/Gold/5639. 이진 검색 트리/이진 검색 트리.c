#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 전위순회는 루트노드를 기준으로 왼쪽은 작은 값, 오른쪽은 큰 값임.
// 이를 이용해 왼쪽 서브트리에서 후위순회, 오른쪽 서브트리에서 후위순회
void postorder(int pre[], int start, int end) {
	int root = pre[start];
	int index = start + 1;

	if (start > end) return;
	while (index <= end && pre[index] < root) {
		index++;
	}

	postorder(pre, start + 1, index - 1);
	postorder(pre, index, end);
	printf("%d\n", root);

}

int main() {
	int pre[10001];
	int count = 0;

	// 입력을 안할때까지 계속 입력받음
	while (scanf("%d", &pre[count]) != EOF) {
		count++;
	}

	postorder(pre, 0, count - 1);
	return 0;
}