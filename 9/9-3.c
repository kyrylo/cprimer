#include <stdio.h>

void magic_print(char ch, int a, int b)
{
    int i, j;

    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++)
            putchar(ch);
        printf("\n");
    }
}

int main(void)
{
    char ch;
    int a, b;

    while (scanf("%c %d %d", &ch, &a, &b) != 3)
    {
        scanf("%*s");
        printf("!!!\n");
    }
    magic_print(ch, a, b);

    return 0;
}
