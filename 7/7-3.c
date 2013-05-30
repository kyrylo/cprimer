#include <stdio.h>

int main(void)
{
    int num;
    int evens, even_sum, odds, odd_sum;
    even_sum = odd_sum = odds = evens = 0;

    printf("Enter a number and press enter:\n");
    while (scanf("%d", &num) == 1 && num != 0) {
        printf("Enter another one (0 to quit):\n");
        if (num % 2 == 0) {
            even_sum += num;
            evens++;
        } else {
            odd_sum += num;
            odds++;
        }
    }

    printf("Evens sum: %d, evens avg.: %d; Odds sum: %d, odds avg.: %d\n",
            even_sum, even_sum / evens, odd_sum, odd_sum / odds);

    return 0;
}
