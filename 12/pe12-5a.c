#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pe12-5a.h"

void seed_random_nums(int nums[], int upto)
{
	srand((unsigned int) time(0));
	for (int i = 0; i < upto; i++)
		nums[i] = rand() % 999 + 1;
}

void show_array(int len, const int nums[len])
{
	for (int i = 0; i < len; i++) {
		if (i % 10 == 0)
			putchar('\n');
		printf("%3.d ", nums[i]);
	}

	putchar('\n');
}

void sort_nums(int len, int nums[len])
{
	int key, i, j;

	for (j = 1; j < len; j++) {
		key = nums[j];
		for (i = j - 1; i >= 0 && nums[i] <= key; i--)
			nums[i + 1] = nums[i];
		nums[i + 1] = key;
	}
}
