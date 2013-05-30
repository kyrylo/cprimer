#include <stdio.h>

int main(void)
{
	char name[10];
	float height_cm;

	printf("Enter your name:\n");
	scanf("%s", name);

	printf("Enter your height (cm):\n");
	scanf("%f", &height_cm);

	printf("%s, you are %.3f meters tall.\n", name, height_cm / 100);
	return 0;
}
