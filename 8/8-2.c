#include <stdio.h>

int main(void)
{
    int i = 1;
    char ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            printf("\\n,%d | ", ch);
        } else if (ch == '\t') {
            printf("\\t,%d |", ch);
        } else if (ch < ' ') {
            printf("^%c,%d |", ch + 64, ch);
        } else {
            printf("%c,%d | ", ch, ch);
        }
        if (i % 10 == 0) {
            printf("\n");
            i = 1;
        } else {
            i++;
        }
    }
    return 0;
}
