#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int count, n;
	int x1, y1, x2, y2, cx, cy, r;

	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		int res = 0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			scanf("%d %d %d", &cx, &cy, &r);
			double d1 = sqrt(pow((x1 - cx), 2) + pow((y1 - cy), 2));
			double d2 = sqrt(pow((x2 - cx), 2) + pow((y2 - cy), 2));

			if (d1 < r && d2 > r) {
				res++;
			}
			else if (d1 > r && d2 < r) {
				res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}