#include <stdio.h>

double harmonic_mean(double a, double b)
{
    return 2 / (1/a + 1/b);
}

int main(void)
{
    double a, b;

    while (scanf("%lf %lf", &a, &b) != 2) {
        scanf("%*s");
        printf("!!!\n");
    }

    printf("harmonic_mean(%f, %f) = %f\n", a, b, harmonic_mean(a, b));

    return 0;
}
