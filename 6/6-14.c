#include <stdio.h>

const int SIZE = 255;

int main(void)
{
    char string[SIZE];
    int i;

    printf("Enter a string (no longer than 255 characters, w/o spaces):\n");
    scanf("%s", string);

    printf("Original: ");
    for (i = 0; string[i] != '\0'; i++)
        printf("%c", string[i]);

    printf("\nReversed: ");
    while (i-- > 0)
        printf("%c", string[i]);

    printf("\n");

    return 0;
}
