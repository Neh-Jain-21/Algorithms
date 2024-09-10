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
* * * * **/

