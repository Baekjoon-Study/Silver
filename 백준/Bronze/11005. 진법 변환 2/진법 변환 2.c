#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	char res[30];
	long long input;
	int N;

	scanf("%lld", &input);
	scanf("%d", &N);

	int len = 1;
	while (pow(N, len) < input) {
		len++;
	}
	if (pow(N, len) != input) len--;

	for (int i = 0; i <= len; i++) {
		long long div = input / (long long)pow(N, len - i);
		input = input - (div * (long long)pow(N, len - i));
		if (div > 9) res[i] = (div + 55);
		else res[i] = (div + 48);
	}

	for (int i = 0; i <= len; i++) {
		printf("%c", res[i]);
	}
	return 0;
}