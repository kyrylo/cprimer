#include <stdio.h>

void to_base_n(unsigned long n, int base)
{
    int r;

    r = n % base;

    if (n > 0) {
        if (n > 1)
           to_base_n(n / base, base);
        putchar('0' + r);
    }
}

int main(void)
{
    to_base_n(129, 8);
    putchar('\n');
    return 0;
}
