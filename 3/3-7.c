#include <stdio.h>

int main(void)
{
	short centimeters;
	printf("Enter your height in centimeters: ");
	scanf("%hd", &centimeters);
	printf("Your height (%hdcm) is %.2f inches\n", centimeters,
							centimeters / 2.54);
	return 0;
}
