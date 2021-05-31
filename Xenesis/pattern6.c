#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j;
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=L-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
void main()
{
    Pattern(5);
}
/*output
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*
*/

