#include <stdio.h>
#define SIZE 5

int max_i(int len, const double ar[*]);
void show_array(int len, const double ar[*]);

int main(void)
{
    double source[SIZE] = {4.3, 1.1, 4.3, 5.9, -20.5};

    printf("Array: ");
    show_array(SIZE, source);

    printf("Index of max: %d\n", max_i(SIZE, source));

    return 0;
}

int max_i(int len, const double ar[])
{
    int i, m;

    m = 0;

    for (i = 0; i < len; i++)
        if (ar[i] > m)
            m = i;

    return m;
}

void show_array(int len, const double ar[])
{
    int i;

    for (i = 0; i < len; i++)
        printf("%.1f ", ar[i]);
    putchar('\n');
}
