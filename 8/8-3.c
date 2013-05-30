#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;
    unsigned short capitals, smalls;

    capitals = smalls = 0;

    while ((ch = getchar()) != EOF)
        if (isupper(ch))
            capitals++;
        else if (islower(ch))
            smalls++;
    printf("Capitals: %d, smalls: %d\n", capitals, smalls);

    return 0;
}
