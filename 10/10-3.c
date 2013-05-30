#include <stdio.h>

int max(int len, const int ar[*]);
void show_array(int len, const int ar[*]);

int main(void)
{
    int source[9] = {4, 124, 5, 1, 56, 7, 1, 299, 77};

    printf("Source: ");
    show_array(9, source);

    printf("Max: %d\n", max(9, source));

    return 0;
}

int max(int len, const int ar[])
{
    int i, m;

    m = 0;

    for (i = 0; i < len; i++)
        if (ar[i] > m)
            m = ar[i];

    return m;
}

void show_array(int len, const int ar[])
{
    int i;

    for (i = 0; i < len; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}
