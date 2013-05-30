#include <stdio.h>

void show_2d_array(int rows, int cols, int ar[rows][cols]);
void double_array(int rows, int cols, int ar[rows][cols]);

int main(void)
{
    int i, j;

    int rs = 3;
    int cs = 5;
    int junk[rs][cs];

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++) {
            printf("%d:%d> ", i, j);
            scanf("%d", &junk[i][j]);
        }

    putchar('\n');

    printf("Your array:\n");
    show_2d_array(rs, cs, junk);

    putchar('\n');

    double_array(rs, cs, junk);
    printf("Doubled values:\n");
    show_2d_array(rs, cs, junk);

    return 0;
}

void show_2d_array(int rows, int cols, int ar[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", ar[i][j]);
        putchar('\n');
    }
}

void double_array(int rows, int cols, int ar[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            ar[i][j] *= 2;
}
