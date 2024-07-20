#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num1, num2;
	int count;

	scanf("%d", &count);
	int n = 1;
	int pos = n * (n + 1) / 2;
	while (pos < count) {
		n++;
		pos = n * (n + 1) / 2;
	}
	if(n % 2 == 0){
		num1 = n; num2 = 1;
		int dif = pos - count;

		num1 = num1 - dif;
		num2 = num2 + dif;
	}
	else {
		num1 = 1; num2 = n;
		int dif = pos - count;

		num1 = num1 + dif;
		num2 = num2 - dif;
	}
	

	printf("%d/%d", num1, num2);
	return 0;
}