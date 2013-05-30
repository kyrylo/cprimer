#include <stdio.h>

void alter(int * pa, int * pb);

int main(void)
{
    int x, y;

    x = 10;
    y = 5;

    printf("Before: x = %d, y = %d\n", x, y);
    alter(&x, &y);
    printf("After:  x = %d, y = %d\n", x, y);

    return 0;
}

void alter(int * pa, int * pb)
{
    int temp;

    temp = *pa;
    *pa += *pb;
    *pb = temp - *pb;
}
