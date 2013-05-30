#include <stdio.h>
#include <ctype.h>

int letter_pos(char ch);

const int ALPHABASE = 64;

int main(void)
{
    int ch, pos;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
        pos = letter_pos(ch);

        if (pos > 0)
            printf("(%d),", pos);
    }
    printf("Bye.\n");

    return 0;
}

int letter_pos(char ch)
{
    int pos = -1;

    if (isalpha(ch))
        pos = toupper(ch) - ALPHABASE;

    return pos;
}
