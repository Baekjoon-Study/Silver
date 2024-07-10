#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int fib_count[41] = { 0, 1 };
	int count;
	int fib;
	scanf("%d", &count);
	getchar();

	for (int i = 2; i < 41; i++) {
		fib_count[i] = fib_count[i - 1] + fib_count[i - 2];
	}
	for (int i = 0; i < count; i++) {
		scanf("%d", &fib);
		if ( fib == 0) printf("1 0\n");
		else {
			printf("%d %d\n", fib_count[fib - 1], fib_count[fib]);
		}
	}
	return 0;
}