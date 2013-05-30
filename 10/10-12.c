#include <stdio.h>

void fill_array(int rows, int cols, double ar[rows][cols]);
void show_2d_array(int rows, int cols, double ar[rows][cols]);
void array_avg_rows(int rows, int cols, double ar[rows][cols]);
double array_avg_row(int cols, double ar[cols]);
double array_avg(int rows, int cols, double ar[rows][cols]);
double max(int rows, int cols, double ar[rows][cols]);

int main(void)
{
    int rs = 3;
    int cs = 5;
    double junk[rs][cs];

    printf("Enter three sets of five double numbers:\n");
    fill_array(rs, cs, junk);

    printf("\nThe information has been stored:\n");
    show_2d_array(rs, cs, junk);

    printf("\nAverage of each set of five values:\n");
    array_avg_rows(rs, cs, junk);

    printf("\nAverage of all the values:\n");
    printf("%.1lf\n", array_avg(rs, cs, junk));

    printf("\nThe largest value of the 15 values:\n");
    printf("%.1lf\n", max(rs, cs, junk));

    return 0;
}

void fill_array(int rows, int cols, double ar[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++) {
        printf("Set %d:\n", i + 1);
        for (j = 0; j < cols; j++)
            while (scanf("%lf", &ar[i][j]) != 1) {
                scanf("%*s");
                printf("Incorrect number. Enter a valid double number\n");
            }
    }
}

void show_2d_array(int rows, int cols, double ar[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%.1lf ", ar[i][j]);
        putchar('\n');
    }
}

void array_avg_rows(int rows, int cols, double ar[rows][cols])
{
    int i;

    for (i = 0; i < rows; i++) {
        printf("Set %d: ", i + 1);
        printf("%.1lf\n", array_avg_row(cols, ar[i]));
    }
}

double array_avg_row(int cols, double ar[cols])
{
    int i;
    double sum = 0.0;

    for (i = 0; i < cols; i++)
        sum += ar[i];

    return sum / cols;
}

double array_avg(int rows, int cols, double ar[rows][cols])
{
    int i, j;
    double avg = 0.0;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            avg += ar[i][j];

    return avg / (cols * rows);
}

double max(int rows, int cols, double ar[rows][cols])
{
    int i, j;
    double m;

    m = ar[0][0];

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (ar[i][j] > m)
                m = ar[i][j];

    return m;
}
