#include <stdio.h>

int main(void)
{
    const int SIZE = 8;
    int array[SIZE];
    int i, j;

    printf("Enter 8 integers.\n");
    for (i = 0; i < SIZE; i++) {
        printf("Enter int %d: ", i+1);
        scanf("%d", &j);
        array[i] = j;
    }

    printf("--\nYou entered the following sequence:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("This is the reversed sequence:\n");
    for (i = sizeof(array)/sizeof(array[0])-1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
