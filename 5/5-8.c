#include <stdio.h>

const double CELSIUS1 = 1.8;
const double CELSIUS2 = 32.0;
const double KELVIN1 = 273.15;

void Temperatures(double fahr);

int main(void)
{
	double fahr;
	printf("Enter Fahrenheit temperature: ");

	while (scanf("%lf", &fahr) == 1) {
		Temperatures(fahr);
		printf("Enter Fahrenheit temperature: ");
	}
	printf("bye\n");
	return 0;
}

void Temperatures(double fahr)
{
	double celcius = fahr * CELSIUS1 + CELSIUS2;
	printf("Fahrenheit %.2lf, Celcius %.2lf, Kelvin %.2lf\n",
		fahr, celcius, celcius + KELVIN1);
}
