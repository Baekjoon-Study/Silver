#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int People = 0;
	int time[1000];
	int sum = 0;
	scanf("%d", &People);

	for (int i = 0; i < People; i++)
	{
		scanf("%d", &time[i]);
	}

	// 정렬
	for (int j = 0; j < People; j++)
	{
		for (int i = 0; i < People - 1; i++)
		{
			if (time[i] > time[i + 1])
			{
				int tmp = time[i];
				time[i] = time[i + 1];
				time[i + 1] = tmp;
			}
		}
	}

	// 합산
	for (int i = 0; i < People; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum = sum + time[j];
		}
		if (i == People - 1)
			printf("%d", sum);
	}
}