#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch, words, letters;
    bool in_word;

    words = letters = 0;
    in_word = false;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            in_word = true;
            letters++;
        } else {
            if (in_word)
                words++;
            in_word = false;
        }
    }

    printf("words: %d, letters: %d, average: %d\n",
            words, letters, letters / words);

    return 0;
}
