#include <stdio.h>

int annual_income(int account);
int withdraw(int account);

int main(void)
{
    int account = 1000000LL;
    short years;

    for (years = 1; account > 0; years++) {
        printf("Year %2hu, Chuckie's account has $%d\n", years, account);
        account = annual_income(account);
        account = withdraw(account);
    }

    printf("Chuckie Lucky is bankrupt!\n");
    return 0;
}

int annual_income(int account)
{
    return account + (account * 8 / 100);
}

int withdraw(int account)
{
    return account - 100000LL;
}
