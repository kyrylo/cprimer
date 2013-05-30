#include <stdio.h>

int main(void)
{
	short quarts;
	printf("Enter amount of water in quarts: ");
	scanf("%hd", &quarts);
	printf("The number of water molecules is %e.\n", quarts * 950 / 3.0e-23);
	return 0;
}
