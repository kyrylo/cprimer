#include <stdio.h>

int const MINUTES_IN_HR = 60;

int main(void)
{
	int minutes;
	printf("Convert minutes to hours and minutes!\n");
	printf("Enter time in minutes (<=0 to exit):\n");
	scanf("%d", &minutes);
	while (minutes > 0) {
		printf("%d minutes is %d hour(s) and %d minute(s).\n", minutes,
			minutes / MINUTES_IN_HR, minutes % MINUTES_IN_HR);

		printf("Try one more time (<=0 to exit):\n");
		scanf("%d", &minutes);
	}
	printf("Terminating...\n");
	return 0;
}
