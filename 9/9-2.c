/*#include <stdio.h>*/

/*int main(void)*/
/*{*/
    /*return 0;*/
/*}*/

#include<stdio.h>
 
void chline(char ch,int i,int j)
{
    int count;
    char space = ' ';
    printf("%*c", i, space);
    for(count = 1 ; count <= ( j - i ) ; count++)
        putchar(ch);
}
 
int main(void)
{
    char ch;     /* 一個字元 */
    int i, j;     /* 第 i 個位置開始，第 j 個位置結束 */
 
    printf("請輸入你要的字元：");
    ch =  getchar();
    printf("請輸入開始的位置：");
    scanf("%d",&i);
    printf("還有要停止的位置：");
    scanf("%d",&j);
    putchar('\n');
 
    chline(ch, i, j);
 
    return 0;
}
