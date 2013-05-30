#include <stdio.h>
#include <string.h>

int main(void)
{
	char first_name[10], last_name[10];
	short fn_len, ln_len;

	printf("Enter your first name:\n");
	scanf("%s", first_name);
	printf("Enter your last name:\n");
	scanf("%s", last_name);

	fn_len = strlen(first_name);
	ln_len = strlen(last_name);

	printf("%s %s\n", first_name, last_name);
	printf("%*d %*d\n", fn_len, fn_len, ln_len, ln_len);

	printf("%-s %-s\n", first_name, last_name);
	printf("%-*d %-*d\n", fn_len, fn_len, ln_len, ln_len);

	return 0;
}
