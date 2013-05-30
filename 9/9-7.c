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

    double pow = 1;
    int i;

    for (i = 1; i <= abs(p); i++)
        pow *= n;

    if (p < 0)
        return 1 / pow;
    else
        return pow;
}
