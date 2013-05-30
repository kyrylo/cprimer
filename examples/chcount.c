#include <stdio.h>

int main(void)
{
    const char PERIOD = '.';
    int ch;
    int charcount = 0;

    while ((ch = getchar()) != PERIOD) {
        if (ch != '"' && ch != '\'')
            charcount++;
    }

    printf("There are %d non-quote characters.\n", charcount);

    return 0;
}
