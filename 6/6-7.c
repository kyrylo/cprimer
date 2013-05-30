#include <stdio.h>

int main(void)
{
    float x, y;

    printf("Enter float x: ");
    scanf("%f", &x);
    printf("Enter float y: ");
    scanf("%f", &y);
    printf("(x - y)/(x * y): %f\n", (x - y)/(x * y));

    return 0;
}
