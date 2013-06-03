#include <stdio.h>
#include <string.h>

#define LIM 15

void reverse_str(char *str);

int main(void)
{
	char str[LIM];

	while (1) {
		printf("Enter a string: ");
		fgets(str, LIM + 1, stdin);

		printf("Reversed string: ");
		reverse_str(str);
		puts(str);
	}
	return 0;
}

void reverse_str(char *str)
{
	char temp;
        char *end = &str[strlen(str) - 1];

        while (end > str)
        {
		temp = *str;
		*str++ = *end;
		*end-- = temp;
        }
}
