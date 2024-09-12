#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char paper[128][128];
int blue = 0, white = 0;

void cut(int x, int y, int length) {
	char color = paper[x][y];
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (paper[i][j] != color) {
				cut(x, y, length / 2);
				cut(x + length / 2, y, length / 2);
				cut(x, y + length / 2, length / 2);
				cut(x + length / 2, y + length / 2, length / 2);
				return;
			}
		}
	}

	if (color == '0') white++;
	else if (color == '1') blue++;

}

int main() {
	int length;
	scanf("%d", &length);
	getchar();

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			scanf("%c", &paper[i][j]);
			getchar();
		}
	}
	cut(0, 0, length);
	printf("%d\n%d", white, blue);
	return 0;
}