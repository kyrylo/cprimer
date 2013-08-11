#include <stdio.h>
#include "14-5.h"

int main(void)
{
	int i, m;
	float avg_grade, class_avg;
	struct student *student;
	struct student students[CSIZE] = {
		{.name.first = "Andrew", .name.surname = "Smith"},
		{.name.first = "John", .name.surname = "Willis"},
		{.name.first = "Mike", .name.surname = "Stallone"},
		{.name.first = "Alex", .name.surname = "Terry"}
	};

	printf("Hello! Enter %d students and their grades.\n", CSIZE);
	puts("Let's start with student 1");
	for (i = 0; i < CSIZE; i++) {
		student = &students[i];
		avg_grade = 0.0;

		printf("Enter %d grades for %s %s (separated by a space):\n",
		       GRADES, student->name.first, students->name.surname);
		for (m = 0; m < GRADES; m++) {
			while (scanf("%f", &student->grades[m]) != 1) {
				printf("Error reading grade number %d of %c.%s.",
				       m + 1, student->name.first[0],
				       student->name.surname);
				puts(" Try again");
				clear();
			}
			avg_grade += student->grades[m];
		}
		student->avg = avg_grade / GRADES;
		clear();
	}

	class_avg = 0.0;
	for (i = 0; i < CSIZE; i++) {
		student = &students[i];
		class_avg += student->avg;
		printf("%s %s has an average grade %.2f (%.2f %.2f %.2f)\n",
		       student->name.first, student->name.surname,
		       student->avg, student->grades[0], student->grades[1],
		       student->grades[2]);
	}
	printf("The class average is %.2f\n", class_avg / CSIZE);

	return 0;
}

void clear(void)
{
	while (getchar() != '\n')
		continue;
}
