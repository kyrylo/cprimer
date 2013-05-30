#include <stdio.h>

const int SIZE = 255;

int main(void)
{
    int i;
    char ch;
    char string[SIZE];

    i = 0;
    while ((ch = getchar()) != '#') {
        string[i] = ch;
        i++;
    }
    string[i] = '\0';

    for (i = 0; string[i] != '\0'; i++) {
        if (i % 8 == 0)
            printf("\n");
        printf("%c", string[i]);
    }
    printf("\n");
    return 0;
}
