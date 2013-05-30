#include <stdio.h>

int main(void)
{
    char pbasis;
    int row, col, r;

    printf("Enter the fucking uppercase letter: ");
    scanf("%c", &pbasis);

    for (row = pbasis - 'A', col = row; row >= 0; row--) {
        r = pbasis - row - 'A';
        while (col-- > 0)
            printf(" ");

        for (col = 0; col <= r; r++) {
            printf("%c", 'A' + r);
        }

        while (r-- > 0)
            printf("%c", 'A' + r);


        printf("\n");
    }
    return 0;
}
