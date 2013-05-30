#include <stdio.h>

#define RS 3
#define CS 5

void show_array(int len, const double ar[]);
void show_2d_array(int rows, int cols, double ar[*][*]);
void copy_2d_array(int rows, int cols, double orig_ar[*][*], double dest_ar[*][*]);

int main(void)
{
    double source[RS][CS] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.0, 10.10},
        {11.11, 12.12, 13.13, 14.14, 15.15}
    };
    double source_copy[RS][CS];

    printf("Array 3x5:\n");
    show_2d_array(RS, CS, source);
    putchar('\n');

    copy_2d_array(RS, CS, source, source_copy);
    printf("Copied array 3x5:\n");
    show_2d_array(RS, CS, source_copy);

    return 0;
}

void show_2d_array(int rows, int cols, double ar[rows][cols])
{
    int i;

    for (i = 0; i < rows; i++)
        show_array(cols, ar[i]);
}

void show_array(int len, const double ar[len])
{
    int i;

    for (i = 0; i < len; i++)
        printf("%.1f ", ar[i]);

    putchar('\n');
}

void copy_2d_array(int rows, int cols, double orig_ar[rows][cols], double dest_ar[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            dest_ar[i][j] = orig_ar[i][j];
}
