#include <stdio.h>
#include <string.h>

#define LIM 15

char *string_in(const char *str, const char *substr);

int main(void)
{
	char str[LIM], substr[LIM];
	char *substr_ptr;

	while (1) {
		printf("Enter str(%d): ", LIM);
		fgets(str, LIM + 1, stdin);

		printf("Enter substr(%d): ", LIM);
		fgets(substr, LIM + 1, stdin);
		
		if ((substr_ptr = string_in(str, substr))) {
			printf("Result: ");
			puts(substr_ptr);
		} else {
			puts("No result, try again :-{");
		}
	}
	
	return 0;
}

char *string_in(const char *str, const char *substr)
{
	return strstr(str, substr);
}
