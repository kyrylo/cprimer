#include <stdio.h>

void interchange(int *a, int *b);

int main(void)
{
    int a, b;

    a = 5;
    b = 10;

    printf("a = %d, &a = %p", a, &a);
    printf("b = %d, &b = %p\n", b, &b);

    printf("Interchanging...\n");
    interchange(&a, &b);

    printf("a = %d, &a = %p", a, &a);
    printf("b = %d, &b = %p\n", b, &b);

    return 0;
}

void interchange(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
