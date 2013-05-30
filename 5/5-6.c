#include <stdio.h>
int main(void)
{
	int count, sum, until;

	count = 0;
	sum = 0;

	printf("How far?\n> ");
	scanf("%d", &until);

	while (count++ < until)
		sum = count * count;
	printf("sum = %d\n", sum);

	return 0;
}
