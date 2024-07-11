#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int count;
	int a, b;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%d %d", &a, &b);
		getchar();

		b = b % 4 + 4;
		int res = 1;
		for (int j = 0; j < b; j++) {
			res = (res * a) % 10;
		}
		if (res == 0) printf("10\n");
		else printf("%d\n", res);
	}
	return 0;
}