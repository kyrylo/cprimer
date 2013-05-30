#include <stdio.h>

int main(void) {
    char ch, prev_ch;
    int occ;

    occ = 0;

    printf("Enter any text (# to quit):\n");
    while ((ch = getchar()) != '#') {
        if (prev_ch == 'e' && ch == 'i')
            occ++;
        prev_ch = ch;
    }
    printf("The 'ei' sequence is used %d times\n", occ);

    return 0;
}
