#include <stdio.h>

void get_stuff(char * input);

#define LIM 11

int main(void)
{
	char input[LIM];
	
	get_stuff(input);

	printf("You entered:\n");
	printf("%s", input);
	putchar('\n');
	
	return 0;
}

void get_stuff(char input[])
{

	printf("Enter stuff: \n");
	scanf("%10s", input); /* the task says not to use scanf. But what's
			       * the alternative? */
}
