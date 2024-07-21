#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long sort[3];

	while (1) {
		scanf("%lld %lld %lld", &sort[0], &sort[1], &sort[2]);
		if (sort[0] == 0 && sort[1] == 0 && sort[2] == 0)
			return 0;

		for (int i = 2; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (sort[j] > sort[j + 1]) {
					int temp = sort[j + 1];
					sort[j + 1] = sort[j];
					sort[j] = temp;
				}
			}
		}
		if (sort[0] * sort[0] + sort[1] * sort[1] == sort[2] * sort[2])
			printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}