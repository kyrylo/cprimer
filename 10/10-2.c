#include <stdio.h>
#define SIZE 5

void copy_arr(const double orig_ar[], double dest_ar[], int n);
void copy_ptr(const double * orig_ar, double * dest_ar, int n);
void show_array(int n, const double ar[n]);

int main(void)
{
    double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[SIZE];
    double target2[SIZE];

    printf("Original array: ");
    show_array(SIZE, source);

    copy_arr(source, target1, SIZE);
    printf("Copied array: ");
    show_array(SIZE, target1);

    copy_ptr(source, target2, SIZE);
    printf("Copied array: ");
    show_array(SIZE, target2);

    return 0;
}

void copy_arr(const double orig_ar[], double dest_ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest_ar[i] = orig_ar[i];
}

void copy_ptr(const double orig_ar[], double dest_ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        *(dest_ar + i) = *(orig_ar + i);
}

void show_array(int n, const double ar[n])
{
    int i;

    for (i = 0; i < n; i++)
        printf("%.1f ", ar[i]);

    putchar('\n');
}
