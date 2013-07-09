#include <stdio.h>

void critic(int *ptr);

int main(void)
{
	int units = 0;
	int *ptr = &units;

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(ptr);
	printf("You must have looked it up!\n");

	return 0;
}

void critic(int *ptr)
{
	/* optional redeclaration omitted */
	printf("No luck, chummy. Try again.\n");
	scanf("%d", ptr);
}
