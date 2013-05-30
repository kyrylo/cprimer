#include <stdio.h>

long Fibonacci(int n)
{
    int temp, i, cur, last;

    last = 0;

    for (i = cur = 1; i < n; i++) {
        temp = cur;
        cur += last;
        last = temp;
    }

    return cur;
}

int main(void)
{
    int n;

    while (scanf("%d", &n) != 1) {
        scanf("%*s");
        printf("!!!\n");
    }

    printf("The %dth Fibonacci number is %ld\n", n, Fibonacci(n));

    return 0;
}
