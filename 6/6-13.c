#include <stdio.h>

const int SIZE = 8;

int main(void)
{
    double origs[SIZE], totals[SIZE];
    double sum;
    int i, j;

    printf("Fill up the original array.\n");
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%lf", &origs[i]);

        sum = 0;
        for (j = i; j >= 0; j--) {
            sum += origs[j];
        }
        totals[i] = sum;
    }

    printf("Original: ");
    for (i = 0; i < SIZE; i++)
        printf("%6.2lf ", origs[i]);

    printf("\n  Totals: ");
    for (i = 0; i < SIZE; i++)
        printf("%6.2f ", totals[i]);

    printf("\n");
    return 0;
}
