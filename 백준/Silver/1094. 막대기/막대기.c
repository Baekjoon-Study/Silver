#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, count = 0;
	scanf("%d", &x);

	while (x > 0) {
		if (x % 2 == 1) {
			count++;
		}
		x = x / 2;
	}
	printf("%d", count);
	return 0;
}