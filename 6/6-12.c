#include <stdio.h>
#include <math.h>

const int SIZE = 8;
int main(void)
{
    int ary[SIZE];
    int i;

    for (i = 0; i < SIZE; i++)
        ary[i] = pow(i+1, 2);

    i = 0;
    do {
        printf("%d ", ary[i]);
    } while (++i < SIZE);

    printf("\n");


    return 0;
}
