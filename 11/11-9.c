#include <stdio.h>
#include <string.h>

#define LIM 100

void remove_spaces(char *str);

int main(void)
{
	char str[LIM];

	while (1) {
		printf("Enter a sentence: ");
		fgets(str, LIM + 1, stdin);

		remove_spaces(str);
		printf("Result: %s", str);
	}

	return 0;
}

void remove_spaces(char *str)
{
	int i, j;
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == ' ') {
			for (j = i + 1; str[j] != '\0'; j++)
				str[j - 1] = str[j];
			str[j] = '\0';
		}
}
