#include <stdio.h>

void reporter(void);

int main(void)
{
	int input;

	printf("Enter 1 to call the reporter() function: ");
	scanf("%d", &input);
	while (input == 1) {
		reporter();
		printf("Enter 1 to call the reporter() function: ");
		scanf("%d", &input);
	}
	return 0;
}

void reporter(void)
{
	static int i = 0;
	printf("reporter() has been called %d times.\n", ++i);
}
