#include <stdio.h>

void jolly_good(void);
void nobody_can_deny(void);

int main(void)
{
	jolly_good();
	jolly_good();
	jolly_good();
	nobody_can_deny();
	return 0;
}

void jolly_good(void)
{
	printf("For he's a jolly good fellow!\n");
}

void nobody_can_deny(void)
{
	printf("Which nobody can deny!\n");
}
