#include <stdio.h>

float calc(float x, float y);

int main(void)
{
    float x, y;

    printf("Enter float x: ");
    scanf("%f", &x);
    printf("Enter float y: ");
    scanf("%f", &y);
    printf("(x - y)/(x * y): %f\n", calc(x, y));

    return 0;
}

float calc(float x, float y)
{
    return (x - y)/(x * y);
}
