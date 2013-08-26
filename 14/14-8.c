#include <stdio.h>
#include <string.h>
#include "14-8.h"

int main(void)
{
	seat plane[PLANESZ] = { { .is_assigned = 0 } };
	char choice;
	FILE *fp;
	const char *file = "plane.dat";
	void (*pfun)(size_t size, seat plane[size]);

	if ((fp = fopen(file, "rb")) != NULL) {
		fread(plane, sizeof(plane), 1, fp);
		fclose(fp);
		printf("Loaded the plane data from %s\n", file);
	}

	display_menu();
	while ((choice = getchar()) != 'f') {
		eatline();
		switch (choice) {
		case 'a': pfun = show_empty_seats_num; break;
		case 'b': pfun = show_empty_seats; break;
		case 'c': pfun = show_seats_sorted_alphabetically; break;
		case 'd': pfun = assign_customer; break;
		case 'e': pfun = delete_reservation; break;
		}
		(*pfun)(PLANESZ, plane);
		display_menu();
	}

	if ((fp = fopen(file, "wb")) != NULL) {
		fwrite(plane, sizeof(plane), 1, fp);
		fclose(fp);
		printf("Stored the plane data to %s.\n", file);
	}

	puts("Bye.");

	return 0;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void display_menu(void)
{
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");
}

void show_empty_seats_num(size_t size, seat plane[size])
{
	printf("The number of empty seats is %zu.\n",
	       count_empty_seats(size, plane));
}

void show_empty_seats(size_t size, seat plane[size])
{
	for (int i = 0; i < size; i++)
		if (!plane[i].is_assigned)
			printf("  seat #%d\n", i + 1);
}

void show_seats_sorted_alphabetically(size_t size, seat plane[size])
{
	int i, j, temp_id;
	int occupied_ids[size];
	int occupied_num = 0;
	seat *ps, *ps_seek;

	puts("Seats sorted alphabetically");

	// Find the ids of occupied seats and store them in a new array.
	for (i = 0; i < size; i++)
		if (plane[i].is_assigned)
			occupied_ids[occupied_num++] = i;

	// Sort the ids of occupied seats. The original array is untouched.
	for (i = 0; i < occupied_num - 1; i++)
		for (j = i + 1; j < occupied_num; j++) {
			ps = &plane[occupied_ids[i]];
			ps_seek = &plane[occupied_ids[j]];
			if (strcmp(ps->holder_name, ps_seek->holder_name) > 0) {
				temp_id = occupied_ids[j];
				occupied_ids[j] = occupied_ids[i];
				occupied_ids[i] = temp_id;
			}
		}

	for (i = 0; i < occupied_num; i++) {
		ps = &plane[occupied_ids[i]];
		printf("  %s %s - seat #%d\n",
		       ps->holder_name, ps->holder_surname, ps->id);
	}
}

void assign_customer(size_t size, seat plane[size])
{
	int choice;
	char name[NAMESZ];
	char surname[NAMESZ];
	char yesno = 'n';

	puts("Which seat would you like to reserve?");
	puts("Here's the list of available seats:");
	show_empty_seats(size, plane);

	while (yesno != 'y') {
		printf("Enter the id: ");
		while ((scanf("%d", &choice) != 1) ||
		       (choice < 1 || choice > PLANESZ) ||
		       plane[choice - 1].is_assigned)
		{
			eatline();
			puts("Sorry, try again!");
			printf("Enter the id: ");
		}

		printf("Enter your name: ");
		scanf("%s", name);
		eatline();

		printf("Enter your surname: ");
		scanf("%s", surname);
		eatline();

		printf("You are %s %s and you want to take seat #%d?\n",
		       name, surname, choice);
		printf("(y/n) ");
		scanf("%c", &yesno);
		eatline();

		if (yesno == 'n')
			puts("OK, let's try again.");
	}

	init_seat(&plane[choice - 1], choice, name, surname);

	puts("Thanks! Enjoy your seat.");
}

void delete_reservation(size_t size, seat plane[size])
{
	int id;

	if (count_empty_seats(size, plane) == PLANESZ) {
		puts("No seats were reserved. Nothing to delete.");
		return;
	}

	puts("Which seat you want to delete?");
	puts("Enter an empty line to cancel.");
	show_seats_sorted_alphabetically(size, plane);
	puts("Enter its id:");

	while ((scanf("%d", &id) != 1) || (id < 1 || id > PLANESZ) ||
	       !plane[id - 1].is_assigned)
	{
		eatline();
		puts("Sorry, try again!");
		printf("Enter the id: ");
	}
	eatline();

	refresh_seat(&plane[id - 1]);
}

void init_seat(seat *s, int id, char *name, char *surname)
{
	s->id = id;
	s->is_assigned = 1;
	strncpy(s->holder_name, name, NAMESZ);
	strncpy(s->holder_surname, surname, NAMESZ);
}

void refresh_seat(seat *s)
{
	s->id = 0;
	s->is_assigned = 0;
	*s->holder_name = '\0';
	*s->holder_surname = '\0';
}

size_t count_empty_seats(size_t size, seat plane[size])
{
	int i;
	size_t empty_seats_ct = 0;

	for (i = 0; i < size; i++)
		if (!plane[i].is_assigned)
			empty_seats_ct++;

	return empty_seats_ct;
}
