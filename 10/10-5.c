#include <stdio.h>
#define SIZE 5

void show_array(int len, const double ar[*]);
double max(int len, const double ar[*]);
double min(int len, const double ar[*]);

int main(void)
{
    double source[SIZE] = {4.3, 11.5, 9.9, 8.4, 0.5};

    printf("Array: ");
    show_array(SIZE, source);

    printf("The diff between the largest and the smallest elements: %.1f\n",
            max(SIZE, source) - min(SIZE, source));

    return 0;
}

void show_array(int len, const double ar[])
{
    int i;

    for (i = 0; i < len; i++)
        printf("%.1f ", ar[i]);
    putchar('\n');
}

double max(int len, const double ar[])
{
    int i, m;

    i = 0;
    m = ar[i];

    while(++i < len)
        if (ar[i] > m)
            m = ar[i];

    return m;
}

double min(int len, const double ar[])
{
    int i, m;

    i = 0;
    m = ar[i];

    while (++i < len)
        if (ar[i] < m)
            m = ar[i];

    return m;
}
