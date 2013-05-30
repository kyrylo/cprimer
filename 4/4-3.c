#include <stdio.h>

int main(void)
{
	float n;
	printf("Enter a float number: ");
	scanf("%f", &n);
	printf("Lemme guess, nig! You entered smthn' like %.1f! Or %1.1e?\n",
		n, n);
	printf("Lemme guess, nig! You entered smthn' like %.3f! Or %.3E?\n",
		n, n);
	return 0;
}
