#include "pe12-2a.h"
#include <stdio.h>

#define METRIC 0
#define US 1

static int mode, distance;
static float fuel_consumed;

void set_mode(int new_mode)
{
	extern int mode;

	switch (new_mode) {
	case METRIC:
	case US:
		mode = new_mode;
		break;
	default:
		printf("Invalid mode specified. ");
		switch (mode) {
		case METRIC:
			printf("Mode %d(METRIC) used.", mode);
			break;
		case US:
			printf("Mode %d(US) used.", mode);
			break;
		}
		putchar('\n');
	}
}

void get_info(void)
{
	extern int mode, distance;
	extern float fuel_consumed;

	switch (mode) {
	case METRIC:
		printf("Enter distance traveled in kilometers: ");
		scanf("%d", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%f", &fuel_consumed);
		break;
	case US:
		printf("Enter distance traveled in miles: ");
		scanf("%d", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%f", &fuel_consumed);
		break;

	}
}

void show_info(void)
{
	extern int mode, distance;
	extern float fuel_consumed;

	float consumption;

	switch (mode) {
	case METRIC:
		consumption = fuel_consumed / distance * 100;
		printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
		break;
	case US:
		consumption = distance / fuel_consumed;
		printf("Fuel consumption is %.2f miles per gallon.\n", consumption);
		break;
	}
}
