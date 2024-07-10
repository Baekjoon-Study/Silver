#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int x1, y1, x2, y2, r1, r2;
	int count;
	scanf("%d", &count);
	getchar();

	for (int i = 0; i < count; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		getchar();

		// 만나는 점이 무한대인 경우
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			printf("-1\n");
			continue;
		}

		double r = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

		if (r < r1 || r < r2) {
			if (r < abs(r2 - r1)) {
				printf("0\n");
			}
			else if (abs(r2 - r1) == r) {
				printf("1\n");
			}
			else {
				printf("2\n");
			}
		}
		else {
			if (r > abs(r1 + r2)) {
				printf("0\n");
			}
			else if (r == abs(r1 + r2)) {
				printf("1\n");
			}
			else {
				printf("2\n");
			}
		}
	}
	return 0;
}