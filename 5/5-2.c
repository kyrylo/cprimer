#include <stdio.h>

int const STEP = 10;

int main(void)
{
	int n, end_point;
	printf("Enter an integer: ");
	scanf("%d", &n);
	end_point = n + STEP;
	printf("%d  ", n);
	while (n++ < end_point)
		printf("%d  ", n);
	printf("\nThe End!\n");
	return 0;
}
