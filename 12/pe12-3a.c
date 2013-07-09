#include <stdio.h>
#include "pe12-3a.h"

void metric_mode_quiz(void)
{
	int distance;
	float fuel_consumed, consumption;

	printf("Enter distance traveled in kilometers: ");
	scanf("%d", &distance);

	printf("Enter fuel consumed in liters: ");
	scanf("%f", &fuel_consumed);

	consumption = fuel_consumed / distance * 100;
	printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
}

void us_mode_quiz(void)
{
	int distance;
	float fuel_consumed, consumption;

	printf("Enter distance traveled in miles: ");
	scanf("%d", &distance);

	printf("Enter fuel consumed in gallons: ");
	scanf("%f", &fuel_consumed);

	consumption = distance / fuel_consumed;
	printf("Fuel consumption is %.2f miles per gallon.\n", consumption);

}

void invalid_mode_msg(unsigned cur_mode)
{
	printf("Invalid mode specified. ");

	if (cur_mode == 0) {
		printf("Mode %d(METRIC) used.\n", cur_mode);
		metric_mode_quiz();
	} else if (cur_mode == 1) {
		printf("Mode %d(US) used.\n", cur_mode);
		us_mode_quiz();
	}
}
