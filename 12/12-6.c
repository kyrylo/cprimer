#include <stdio.h>
#include "pe12-6a.h"

int main(void)
{
	static const int len = 1000;
	int nums[len];

	seed_random_nums(nums, len);
	report_stats(len, nums);

	return 0;
}
