#include <stdio.h>

int const DAYS_IN_WEEK = 7;

int main(void)
{
	int days;
	printf("Convert days to weeks and days!\n");
	printf("Enter days (<=0 to exit):\n");
	scanf("%d", &days);
	while (days > 0) {
		printf("%d days is %d weeks and %d days.\n", days,
			days / DAYS_IN_WEEK, days % DAYS_IN_WEEK);

		printf("Try one more time (<=0 to exit):\n");
		scanf("%d", &days);
	}
	printf("Terminating...\n");
	return 0;
}
