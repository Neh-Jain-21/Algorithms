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
                printf("%d ",j);
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
                printf("%d ",j);
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
1 *
1 * 3
1 * 3 *
1 * 3 * 5
1 * 3 *
1 * 3
1 *
1
*/

