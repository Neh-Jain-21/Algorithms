#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,s=1;
    for(i=0;i<=n-1;i++)
    {
        if(i==0)
        {
            for(k=1;k<=n;k++)
            {
                printf("* ");
            }
            printf("\n");
        }
        else if(i==n-1)
        {
            for(k=1;k<=n;k++)
            {
                printf("* ");
            }
        }
        else
        {
            printf("* ");
            for(k=3;k<=n;k++)
            {
                printf("  ");
            }
            printf("*");
            printf("\n");
        }
    }
}
void main()
{
    int n;
    Pattern(5);
}
/*output
* * * * *
*       *
*       *
*       *
* * * * *
*/
