#include <stdio.h>

int main(void)
{
	short age;
	printf("Enter your age: ");
	scanf("%hd", &age);
	printf("You are %e seconds old.\n", age * 3.156e7);
	return 0;
}
