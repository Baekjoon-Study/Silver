#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int count;
	int x, y;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		scanf("%d %d", &x, &y);
		int distance = y - x;
		int root = (int)sqrt(distance);
		if (distance < 4) printf("%d\n", distance);

		else if (distance == root * root) printf("%d\n", (2 * root) - 1);

		else if (root * root < distance && distance <= root * root + root) printf("%d\n", 2 * root);

		else if (root * root + root < distance) printf("%d\n", 2 * root + 1);
	}
	return 0;
}