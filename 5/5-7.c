#include <stdio.h>

float cube(float n);

int main(void)
{
	float n;
	printf("Enter a number: ");
	scanf("%f", &n);
	printf("Cube of number %.1f is %.1f\n", n, cube(n));
	return 0;
}

float cube(float n)
{
	return n * n * n;
}
