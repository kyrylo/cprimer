#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pe12-6a.h"

void seed_random_nums(int nums[], int upto)
{
	srand((unsigned int) time(0));
	for (int i = 0; i < upto; i++)
		nums[i] = rand() % 10 + 1;
}

void report_stats(int len, const int nums[len])
{
	int *stats = calloc(len, sizeof(int));

	for (int i = 0; i < len; i++)
		*(stats + nums[i]) += 1;
	show_array(len, stats);

	free(stats);
}

void show_array(int len, const int nums[len])
{
	for (int i = 0; i < len; i++)
		if (nums[i] != 0)
			printf("%3d ", nums[i]);
	putchar('\n');
}
