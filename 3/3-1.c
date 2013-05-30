#include <stdio.h>

int main(void)
{
	int i = 1000000000;
	float f = 9999999999999999999999.99;
	float u = .000000000000000000000000000000000000000000000001 / 2.0;

	printf("overflow int: %Ld\n", i + 99999999999998);
	printf("overflow float: %f\n", f + 99999999999999.99);
	printf("underflow: %f\n", u);

	return 0;
}
