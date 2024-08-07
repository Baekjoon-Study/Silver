#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int e, s, m, year = 1;
	scanf("%d %d %d", &e, &s, &m);

	while ((year - e) % 15 != 0 || (year - s) % 28 != 0 || (year - m) % 19 != 0) {
		year++;
	}
	printf("%d", year);
	return 0;
}