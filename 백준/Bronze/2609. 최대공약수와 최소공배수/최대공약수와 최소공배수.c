#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int num1, int num2) {
	if (num2 > num1) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	while (num1 % num2 != 0) {
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	return num2;
}

int lcm(int num1, int num2) {
	if (num1 > num2) {
		int temp = num2;
		num2 = num1;
		num1 = temp;
	}
	int res = num1;
	while (res % num2 != 0) {
		res += num1;
	}
	return res;
}

int main() {
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	printf("%d\n", gcd(num1, num2));
	printf("%d", lcm(num1, num2));
	return 0;
}