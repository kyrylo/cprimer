#include <stdio.h>

void larger_of(double *x, double *y)
{
    if (*y > *x)
        *x = *y;
    else
        *y = *x;
}

int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) != 2) {
        scanf("%*c");
        printf("!!!\n");
    }

    printf("x = %.2f, y = %.2f\n", x, y);
    larger_of(&x, &y);
    printf("x = %.2f, y = %.2f\n", x, y);

    return 0;
}
