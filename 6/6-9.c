#include <stdio.h>
#include <math.h>

int main(void)
{
    int llim, ulim, i, sum;

    llim = 0;
    ulim = 1;
    sum = 0;

    do {
        printf("Enter lower and upper integer limits: ");
        scanf("%d%d", &llim, &ulim);

        for (i = llim; i <= ulim; i++)
            sum += pow(i, 2);

        printf("The sums of the squares from %d to %d is %d\n",
               (int) pow(llim, 2), (int) pow(ulim, 2), sum);
    } while (llim != ulim);

    printf("Done\n");
    return 0;
}
