#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char string[30];
	int N;

	scanf("%s", string);
	scanf("%d", &N);
	int len = strlen(string);
	long long res = 0;
	for (int i = 0; i < len; i++) {
		if ('A' <= string[i] && string[i] <= 'Z') {
			res = res + (long long)pow(N, len - 1 - i) * (long long)(string[i] - 55);
		}
		else {
			res = res + (long long)pow(N, len - 1 - i) * (long long)(string[i] - 48);
		}
	}
	printf("%lld", res);
	return 0;
}