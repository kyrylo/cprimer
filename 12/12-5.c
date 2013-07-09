#include <stdio.h>
#include "pe12-5a.h"

int main(void)
{
	static const int len = 100;
	int nums[len];

	seed_random_nums(nums, len);

	puts("Unsorted array:");
	show_array(len, nums);

	putchar('\n');

	sort_nums(len, nums);
	puts("Sorted array:");
	show_array(len, nums);

	return 0;
}
