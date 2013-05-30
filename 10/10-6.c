#include <stdio.h>

void copy_arr(const double orig_ar[], double dest_ar[], int n);
void show_array(int n, const double ar[n]);

int main(void)
{
    int i;

    int rs = 2;
    int cs = 4;
    double ar[rs][cs] = {
        {1.1, 2.2, 3.3, 4.4},
        {5.5, 6.6, 7.7, 8.8}
    };
    double ar_copy[rs][cs];

    for (i = 0; i < rs; i++)
        copy_arr(ar[i], ar_copy[i], cs);

    for (i = 0; i < rs; i++)
        show_array(cs, ar_copy[i]);

    return 0;
}

void copy_arr(const double orig_ar[], double dest_ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest_ar[i] = orig_ar[i];
}

void show_array(int n, const double ar[n])
{
    int i;

    for (i = 0; i < n; i++)
        printf("%.1f ", ar[i]);

    putchar('\n');
}
