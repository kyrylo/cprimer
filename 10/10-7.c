#include <stdio.h>
#define SIZE 7
#define SMALL 3

void show_array(int n, const int ar[n]);
void copy_arr(const int orig_ar[], int dest_ar[], int n);

int main(void)
{
    int source[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    int small[SMALL];

    printf("Array: ");
    show_array(SIZE, source);

    copy_arr(source+2, small, SMALL);
    printf("Small array: ");
    show_array(SMALL, small);

    return 0;
}

void copy_arr(const int orig_ar[], int dest_ar[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest_ar[i] = orig_ar[i];
}

void show_array(int n, const int ar[n])
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);

    putchar('\n');
}
