#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    printf("%c\n", get_first());

    return 0;
}

char get_first(void)
{
    int ch;

    while (isblank(ch = getchar()))
        continue;

    while (getchar() != '\n')
        continue;

    return ch;
}
