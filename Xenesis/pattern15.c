#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,m,s=1;
    for(i=n/2;i<=n;i=i+2)
    {
        for(j=1;j<n-i;j=j+2)
        {
            printf("  ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        for(j=1;j<=n-i;j++)
        {
            printf("  ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=n;i>=1;i--)
    {
        for(j=i;j<n;j++)
        {
            printf("  ");
        }
        for(j=1;j<=(i*2)-1;j++)
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
  * *       * *
* * * *   * * * *
* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *
*/
