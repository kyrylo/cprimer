#include <stdio.h>
#include <string.h>

int main(void)
{
    const int SIZE = 10;
    char word[SIZE];
    int i;

    printf("Enter a single word: ");
    scanf("%s", word);

    for (i = strlen(word); i >= 0; i--)
        printf("%c", word[i]);
    printf("\n");

    return 0;
}
