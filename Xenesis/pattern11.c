#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,s=1;
    for(i=0;i<=n;i++)
    {
        for(j=n;j>i;j--)
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
    s=s-4;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf(" ");
        }
        printf("*");
        for(k=1;k<=s;k++)
        {
            printf(" ");
        }
        s=s-2;
        if(i!=n-1)
        {
            printf ("*");
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
   *   *
  *     *
 *       *
*         *
 *       *
  *     *
   *   *
    * *
     *
*/


