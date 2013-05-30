#include <stdio.h>
#include <float.h>

int main(void)
{
	double d = 1.0 / 3.0;
	float f = 1.0 / 3.0;

	printf("d = %.4f; f = %.4f\n", d, f);
	printf("d = %.12f; f = %.12f\n", d, f);
	printf("d = %.16f; f = %.16f\n", d, f);

	printf("%d\n", FLT_DIG);
	printf("%d\n", DBL_DIG);

	return 0;
}
