#include <stdio.h>

#define NAMELEN 64
typedef struct {
	char fname[NAMELEN];
	char mname[NAMELEN];
	char lname[NAMELEN];
} name;

typedef struct {
	int ssn;
	name nh;
} person;

void clever_print(person people[5]);
void clever_print_ptr(person *people[5]);

int main(void)
{
	person people[5] = {
		{302039823, {"Flossie", "Matthew", "Dribble"}},
		{123456789, {"Dave", "", "Dunno"}},
		{998766823, {"Bill", "Duke", "Sodknowswhat"}},
		{125135233, {"Lucy", "", "Lawful"}},
		{945803292, {"Benjamin", "Susy", "Stanford"}}
	};

	clever_print(people);
	puts("-----------");
	clever_print(people);

	return 0;
}

void clever_print(person people[5])
{
	for (int i = 0; i < 5; i++) {
		printf("%s, %s ", people[i].nh.lname, people[i].nh.fname);
		if (people[i].nh.mname[0])
			printf("%c. ", people[i].nh.mname[0]);
		printf("-- %d\n", people[i].ssn);
	}
}

void clever_print_ptr(person *people[5])
{
	for (int i = 0; i < 5; i++) {
		printf("%s, %s ", people[i]->nh.lname, people[i]->nh.fname);
		if (people[i]->nh.mname[0])
			printf("%c. ", people[i]->nh.mname[0]);
		printf("-- %d\n", people[i]->ssn);
	}

}
