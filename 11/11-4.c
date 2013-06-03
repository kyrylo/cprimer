#include <stdio.h>
#include <string.h>

#define LIM 81

char * search(char seek[], int c);

int main(void)
{
	char text[LIM];
	char *find;
	
	while (1) {
		printf("Enter text:\n");
		fgets(text, LIM, stdin);
	
		printf("Search for: ");
		find = search(text, getchar());

		if (find) {
			puts(find);
		} else {
			puts("No occurrences...");
		}
	}

	return 0;
}

char * search(char seek[], int c)
{
	return strchr(seek, c);
}
