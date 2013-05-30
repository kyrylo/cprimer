#include <stdio.h>

int main(void)
{
    const int SIZE = 26;
    int i;
    int ary[SIZE-1];

    for (i = 0; i < SIZE; i++)
        ary[i] = 'A' + i;

    for (i = 0; i < SIZE; i++)
        printf("%c ", ary[i]);
    printf("\n");
}
