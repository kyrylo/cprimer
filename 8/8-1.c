#include <stdio.h>

int main(void)
{
    int chars = 0;

    while (getchar() != EOF)
        chars++;
    printf("Quantity of chars: %d\n", chars);

    return 0;
}
