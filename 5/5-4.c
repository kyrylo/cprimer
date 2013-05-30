#include <stdio.h>

float const CENTIMITERS_IN_INCH = 2.54;
float const INCHES_IN_FEET = 12.00;

int main(void)
{
	float centimeters, inches;
	int feet;

	printf("Enter a height in centimeters: ");
	scanf("%f", &centimeters);

	while (centimeters > 0) {
		inches = centimeters / CENTIMITERS_IN_INCH;
		feet = inches / INCHES_IN_FEET;
		printf("%.1f cm = %d feet, %.1f inches\n", centimeters,
			feet, inches - (feet * INCHES_IN_FEET));

		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &centimeters);
	}
	printf("bye\n");
	return 0;
}
