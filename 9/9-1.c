#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) != 2) {
        scanf("%*s");
        printf("!!!\n");
    }
    printf("OK\n");
    printf("%f\n", min(x, y));
    return 0;
}

double min(double x, double y)
{
    return x > y ? x : y;
}
