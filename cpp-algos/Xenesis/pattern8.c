#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j,k;
    for(i=1;i<=L;i++)
    {
        for(k=L;k>i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=L-1;i>=1;i--)
    {
        for(k=i;k<=L-1;k++)
        {
            printf(" ");
        }
        for(j=i;j>=1;j--)
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
