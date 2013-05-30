#include <stdio.h>

/*int main(void)*/
/*{*/
    /*float lim, x, sum;*/
    /*int i;*/

    /*printf("Enter the limit: ");*/
    /*scanf("%f", &lim);*/

    /*for (i = 0; i < 20; i++, x *= 2.0) {*/
        /*sum += 1.0/x;*/
        /*printf("sum = %f when terms = %d.\n", sum, i);*/
    /*}*/
    /*return 0;*/
/*}*/

/* zeno.c -- series sum */
int main(void)
{
    int t_ct;
    double time, x;
    int limit;

    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);

    for (time=0, x=1, t_ct=1; t_ct <= limit; t_ct++, x *= 2.0)
    {
        time += 1.0/x;
        printf("time = %f when terms = %d.\n", time, t_ct);
    }
    return 0;
}
