#include <stdio.h>

int main(void)
{
	float n;

	printf("Enter a floating-point number: ");
	scanf("%f", &n);
	printf("The input is %f or %e\n", n, n);

	return 0;
}
