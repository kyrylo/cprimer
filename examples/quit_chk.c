#include <stdio.h>
#include <string.h>

const int SIZE = 81;
const int LIM = 100;
const char STOP[] = "quit";

int main(void)
{
    char input[LIM][SIZE];
    int ct = 0;

    printf("Enter up to %d lines (type quit to quit):\n", LIM);
    while (ct < LIM && gets(input[ct]) != NULL && strcmp(input[ct], STOP) != 0)
        ct++;
    printf("%d strings entered\n", ct);

    return 0;
}
