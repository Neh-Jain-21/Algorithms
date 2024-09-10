#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,s=1;
    for(i=0;i<=n-2;i++)
    {
        for(j=n;j>i+1;j--)
        {
            printf(" ");
        }
        printf("*");
        if (i>0)
        {
            for(k=1;k<=s;k++)
            {
                printf(" ");
            }
            s=s+2;
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=n-1;i++)
    {
        printf("* ");
    }
}
void main()
{
    Pattern(5);
}
/*output
     *
    * *
   *   *
  *     *
 *       *
* * * * * *
*/
