#include <stdio.h>
#define SIZE 4

void count_sums(int len, int ar[*], int other[*], int dest[*]);
void show_array(int len, int ar[*]);

int main(void)
{

    int a1[SIZE] = {2, 4, 5, 8};
    int a2[SIZE] = {1, 0, 4, 6};
    int sums[SIZE];

    printf("a1:\n");
    show_array(SIZE, a1);
    printf("a2:\n");
    show_array(SIZE, a1);

    count_sums(SIZE, a1, a2, sums);

    printf("sums:\n");
    show_array(SIZE, sums);

    return 0;
}

void count_sums(int len, int ar[len], int other[len], int dest[len])
{
    int i;

    for (i = 0; i < len; i++)
        dest[i] = ar[i] + other[i];

}

void show_array(int len, int ar[len])
{
    int i;

    for (i = 0; i < len; i++)
        printf("%d ", ar[i]);

    putchar('\n');
}
