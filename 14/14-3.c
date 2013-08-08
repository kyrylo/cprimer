#include <stdio.h>
#include <string.h>
#include "14-3.h"

int main(void)
{
	book library[MAXBKS];
	int count = 0;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && gets(library[count].title) != NULL
	       && library[count].title[0] != '\0') {
		printf("Now enter the author.\n");
		gets(library[count].author);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;          /* clear input line         */
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0) {
		puts("Here is the list of your books:");
		print_delim();
		print_library(library, count);

		puts("\nSorted alphabetically:");
		print_delim();
		sort(library, count, alphabetically);
		print_library(library, count);

		puts("\nSorted by value:");
		print_delim();
		sort(library, count, by_value);
		print_library(library, count);
	} else
		printf("No books? Too bad.\n");

	return 0;
}

void print_library(const book *library, int count)
{
	for (int index = 0; index < count; index++)
		printf("%s by %s: $%.2f\n", library[index].title,
		       library[index].author, library[index].value);
}

void print_delim(void)
{
	puts("---");
}

void
sort(book *library, int count, sm sorting_method)
{
	book temp;

	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			(*sorting_method)(library, temp, i, j);

}

void alphabetically(book *library, book temp, int i, int j)
{
	if (strcmp(library[i].title, library[j].title) > 0) {
		temp = library[i];
		library[i] = library[j];
		library[j] = temp;
	}
}

void by_value(book *library, book temp, int i, int j)
{
	if (fltcmp(library[i].value, library[j].value) > 0) {
		temp = library[i];
		library[i] = library[j];
		library[j] = temp;
	}
}

int fltcmp(const float a, const float b)
{
	return (a > b) - (a < b);
}
