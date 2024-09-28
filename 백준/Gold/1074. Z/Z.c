#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int res = 0;
void find(int N, int r, int c) {
	if (N >= 0) {
		int width = pow(2, N);
		int size = pow(width, 2);

		if (r < width) {
			if (c < width) {
				find(N - 1, r, c);
			}
			else {
				res += size;
				find(N - 1, r, c - width);
			}
		}
		else {
			if (c < width) {
				res += 2 * size;
				find(N - 1, r - width, c);
			}
			else {
				res += 3 * size;
				find(N - 1, r - width, c - width);
			}
		}
	}
}

int main() {
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	find(N, r, c);
	printf("%d", res);
	return 0;
}
