#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, sides, sets;
	int i;

	srand((unsigned int) time(0));
	printf("Enter the number of sets; enter q to stop\n");
	while (scanf("%d", &sets) == 1 && sides != 0)
	{
		printf("How many sides and how many dice?\n");
		scanf("%d %d", &sides, &dice);

		int rolls[sets];
		for (i = 0; i < sets; i++)
			rolls[i] = roll_n_dice(dice, sides, sets);

		printf("Here are %d sets of %d %d-sided dice.\n",
		       sets, dice, sides);
		for (i = 0; i < sets; i++)
			printf("%d ", rolls[i]);
		putchar('\n');

		printf("Enter the number of sets; enter q to stop\n");
	}
	printf("The rollem() function was called %d times.\n", roll_count);

	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}
