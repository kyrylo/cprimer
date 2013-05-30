#include <stdio.h>
#include <stdlib.h>

double power(double n, int p);

int main(void)
{
    printf("%f\n", power(2, -8));
    return 0;
}


double power(double n, int p)
{
    if (n == 0)
        return 0;
    else if (p == 0)
        return 1;

    if (abs(p) > 1)
        n *= power(n, abs(p) - 1);

    if (p < 0)
        return 1 / n;
    else
        return n;
}
