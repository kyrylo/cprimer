#include <stdio.h>
#include <stdlib.h>

char get_first(void);
int correct_guess(int guess, int prev_guess);

int main(void)
{
    int ch, prev_guess, guess, g;

    prev_guess = 0;
    guess = 50;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((ch = get_first()) != 'y')
        if (ch == 'n') {
            printf("g: %d, p: %d\n", guess, prev_guess);
            printf("Is it lower or higher than %d?\n", guess);

            g = guess;
            guess = correct_guess(g, prev_guess);
            prev_guess = g;

            printf("Well, then, is it %d?\n", guess);
        } else {
            printf("Type n or y only!\n");
        }

    printf("I knew I could do it!\n");

    return 0;
}

char get_first(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;
}

int correct_guess(int guess, int prev_guess)
{
    int corrected = 0;

    while (!corrected)
        switch (get_first()) {
            case 'l':
                if (!prev_guess) {
                    guess /= 2;
                } else {
                    guess -= abs((prev_guess - guess) / 2);
                    if (guess <= 3)
                        guess = 1;
                }
                corrected = 1;
                break;

            case 'h':
                if (!prev_guess) {
                    guess += guess / 2;
                } else {
                    guess += abs((prev_guess - guess) / 2);
                    if (guess >= 97)
                        guess = 100;
                }
                corrected = 1;
                break;

            default:
                corrected = 0;
        }

    return guess;
}
