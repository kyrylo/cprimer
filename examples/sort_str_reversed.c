#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 20
#define HALT ""

void sort_reversed(char * strings[], int n);

int main(void)
{
    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct, k;

    ct = 0;

    printf("Input up to %d lines, and I will sort them in reversed order.\n"
           "To stop, press the Enter key at line's start.\n", LIM);
    while (ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];
        ct++;
    }

    sort_reversed(ptstr, ct);

    puts("\nHere's the sorted list (reversed):\n");

    for (k = 0; k < ct; k++)
        puts(ptstr[k]);

    return 0;
}

void sort_reversed(char * strings[], int n)
{
    char *temp;
    int top, seek;

    for (top = 0; top < n-1; top++)
        for (seek = top + 1; seek < n; seek++)
            if (strcmp(strings[top], strings[seek]) < 0) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}
