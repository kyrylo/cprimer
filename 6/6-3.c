#include <stdio.h>

int main(void)
{
    int upper, lower;
    int row;

    for (row = 5; row >= 0; row--) {
        for (upper = 'F', lower = 'A'; upper-row >= lower; upper--)
            printf("%c", upper);
        printf("\n");
    }
    return 0;
}
