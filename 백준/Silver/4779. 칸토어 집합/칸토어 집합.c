#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void print_line(int N) {
	if (N == 0) {
		printf("-");
		return;
	}
	int num = pow(3, N - 1);

	print_line(N - 1);
	for (int i = 0; i < num; i++) {
		printf(" ");
	}
	print_line(N - 1);
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		print_line(N);
		printf("\n");
	}
	return 0;
}