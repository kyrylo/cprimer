#include <stdio.h>
#include <ctype.h>

char get_choice(void);
char get_first(void);
float get_float(void);
float calculate(char ch, float f_num, float s_num);
float add(float f_addend, float s_addend);
float subtract(float minuend, float subtrahend);
float multiply(float multiplicand, float multiplier);
float divide(float dividend, float divisor);

int main(void)
{
    int choice;
    float f_num, s_num;

    while ((choice = get_choice()) != 'q') {
        printf("Enter first number: ");
        f_num = get_float();

        printf("Enter second number: ");
        s_num = get_float();

        printf(" = %.1f\n", calculate(choice, f_num, s_num));
    }
    printf("Bye.\n");

    return 0;
}

char get_choice(void)
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add         s. subtract\n");
    printf("m. multiply    d. divide\n");
    printf("q. quit\n");

    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q') {
        printf("Respond with a, s, m, d or q\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    int ch;

    while (isblank(ch = getchar()))
        continue;

    while (getchar() != '\n')
        continue;

    return ch;
}

float get_float(void)
{
    float input;
    char ch;

    while (scanf("%f", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a float.\nEnter a number, such as 2.5, -1.78E8, or 3: ");
    }

    while (getchar() != '\n')
        continue;

    return input;
}

float calculate(char ch, float f_num, float s_num)
{
    float res;

    switch (ch) {
        case 'a': res = add(f_num, s_num);
                  break;
        case 's': res = subtract(f_num, s_num);
                  break;
        case 'm': res = multiply(f_num, s_num);
                  break;
        case 'd': res = divide(f_num, s_num);
                  break;
    }

    return res;
}

float add(float f_addend, float s_addend)
{
    printf("%.1f + %.1f", f_addend, s_addend);
    return f_addend + s_addend;
}

float subtract(float minuend, float subtrahend)
{
    printf("%.1f - %.1f", minuend, subtrahend);
    return minuend - subtrahend;
}

float multiply(float multiplicand, float multiplier)
{
    printf("%.1f * %.1f", multiplicand, multiplier);
    return multiplicand * multiplier;
}

float divide(float dividend, float divisor)
{
    while (divisor == 0) {
        printf("Enter a number other than 0: ");
        divisor = get_float();
    }

    printf("%.1f / %.1f", dividend, divisor);
    return dividend / divisor;
}
