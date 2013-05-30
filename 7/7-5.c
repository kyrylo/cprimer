#include <stdio.h>

const int SIZE = 255;

int main(void)
{
    char ch;
    char string[SIZE];
    int i, changes;
    changes = 0;

    printf("Enter a string:\n");
    for (i = 0; (ch = getchar()) != '#'; i++) {
        switch (ch) {
            case '.':
                string[i] = '!';
                changes++;
                break;
            case '!':
                string[i++] = '!';
                string[i] = '!';
                changes++;
                break;
            default:
                string[i] = ch;
        }
    }
    string[i] = '\0';

    printf("OK, here is your string with %d substitutions:\n", changes);
    for (i = 0; string[i] != '\0'; i++)
        printf("%c", string[i]);
    printf("\n");

    return 0;
}
