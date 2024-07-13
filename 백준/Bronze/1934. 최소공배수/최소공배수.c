#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	int count, num1, num2;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d %d", &num1, &num2);
		printf("%d\n", lcm(num1, num2));
	}
	return 0;
}