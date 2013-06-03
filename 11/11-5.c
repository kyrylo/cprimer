#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LIM 81

bool is_within(int c, char *str);

int main(void)
{
	char str[LIM];

	while (1) {
		printf("Enter a string:\n");
		fgets(str, LIM, stdin);
		
		printf("Search for:\n");
		
		if (is_within(getchar(), str)) {
			puts("TRUE");
		} else {
			puts("FALSE");
		}
	}
	
	return 0;
}

bool is_within(int c, char *str)
{
	if (strchr(str, c)) {
		return true;
	} else {
		return false;
	}
}
