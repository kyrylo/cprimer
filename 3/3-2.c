#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter an ASCII code: ");
	scanf("%d", &ch);
	printf("The code %d corresponds to the ASCII character %c.\n", ch, ch);

	return 0;
}
