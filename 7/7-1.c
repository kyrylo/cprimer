#include <stdio.h>

int main(void)
{
    int sp, nl, c;
    char ch;

    sp = nl = c = 0;

    printf("Type something (# to quit):\n");
    while ((ch = getchar()) != '#') {
        switch (ch) {
        case ' ':
            sp++;
            break;
        case '\n':
            nl++;
            break;
        default:
            c++;
        }
    }

    printf("%d spaces, %d newlines, %d other characters\n", sp, nl, c);

    return 0;
}
