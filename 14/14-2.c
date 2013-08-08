#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "14-2.h"

int main(void)
{
	char input_mon[16];
	unsigned short i, day, year, total_days;
	const MONTH *pmon;

	MONTH months[12] = {
		{1, "January", "Jan", 31},
		{2, "February", "Feb", 28},
		{3, "March", "Mar", 31},
		{4, "April", "Apr", 30},
		{5, "May", "May", 31},
		{6, "June", "Jun", 30},
		{7, "July", "Jul", 31},
		{8, "August", "Aug", 31},
		{9, "September", "Sep", 30},
		{10, "October", "Oct", 31},
		{11, "November", "Nov", 30},
		{12, "December", "Dec", 31}
	};

	get_day(&day);
	pmon = get_month(input_mon, months);
	get_year(&year);

	for (i = total_days = 0; i < pmon->id - 1; i++)
		total_days += months[i].days;
	total_days += day;

	printf("\n---\nTotal number of days in %d up to %s %d is %d\n",
	       year, pmon->name, day, total_days);

	return 0;
}

void clear(void)
{
	while (getchar() != '\n')
		continue;
}

void get_day(unsigned short *day)
{
	puts("Enter day:");
	while ((scanf("%hu", day) == 0) || *day < 1 || *day > 31) {
		clear();
		puts("Wrong! Try again.");
	}
}

const MONTH *get_month(char *input_mon, const MONTH months[12])
{
	unsigned short n;
	const MONTH *pmon;

	while (1) {
		clear();
		puts("Enter month:");
		scanf("%s", input_mon);

		if ((n = atoi(input_mon)) == 0)
			pmon = strfind_mon(input_mon, months);
		else
			if (n < 1 || n > 12) {
				puts("Wrong month! (1-12)");
				continue;
			} else
				pmon = &months[n - 1];
		if (pmon)
			return pmon;
		puts("Wrong month!");
	}
}


void get_year(unsigned short *year)
{
	puts("Enter year:");
	while ((scanf("%hu", year) == 0) || *year < 1900 || *year > 3000) {
		clear();
		puts("Wrong! Try again.");
	}

}


const MONTH *strfind_mon(const char *substr, const MONTH months[12])
{
	for (int i = 0; i < 12; i++)
		if (strncmp(substr, months[i].name, 3) == 0)
			return &months[i];
	return NULL;
}
