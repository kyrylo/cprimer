#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int div, num;
    bool isPrime;


    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime numbers %d>0: ", num);
    do {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
            if (num % div == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            printf("%d ", num);
    } while (num-- > 2);

    printf("\n");
    return 0;
}
