#include <stdio.h>

int main(void)
{
    int pooh = 2, bah = 2;

    printf("pooh = %d, %p; bah = %d, %p", pooh, &pooh, bah, &bah);

    return 0;
}
