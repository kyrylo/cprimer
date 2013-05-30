#include <math.h>
#include <stdio.h>

int main(void)
{
    int llim, ulim, i;

    printf("I'm going to print the table. What's the lower limit: ");
    scanf("%d", &llim);
    printf("What's the upper limit: ");
    scanf("%d", &ulim);

    for (i = llim; i <= ulim; i++) {
        printf("%d: %-3d  ", i, (int) pow(i, 2));
        printf("%-3d\t", (int) pow(i, 3));
        printf("\n");
    }
    return 0;
}
