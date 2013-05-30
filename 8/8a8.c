#include <stdio.h>

int largest(int a, int b, int c);

int main(void)
{
    int a, b, c;

    a = 10;
    b = 4;
    c = 3;

    printf("largest(%d, %d, %d) = %d\n", a, b, c, largest(a, b, c));

    return 0;
}

int largest(int a, int b, int c)
{
    if (a > b && a > c) {
        return a;
    } else {
        if (b > c)
            return b;
        else
            return c;
    }
}
