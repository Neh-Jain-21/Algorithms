#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j,k;
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(j%2==0)
            {
                printf("* ");
            }
            else
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    for(i=L-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            if(j%2==0)
            {
                printf("* ");
            }
            else
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
void main()
{
    Pattern(5);
}
/*output
1
2 *
3 * 3
4 * 4 *
5 * 5 * 5
4 * 4 *
3 * 3
2 *
1
*/

