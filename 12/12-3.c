#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
	int cur_mode, mode, metric, us;

	metric = 0;
	us = 1;
	cur_mode = -1;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		if (mode == metric) {
			metric_mode_quiz();
		} else if (mode == us) {
			us_mode_quiz();
		} else {
			invalid_mode_msg(cur_mode);
		}

		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		cur_mode = mode;
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}
