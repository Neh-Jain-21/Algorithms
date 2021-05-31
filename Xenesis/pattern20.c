#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j,k,l=0;
    for(i=1;i<=L;i++)
    {
        for(k=L;k>=i;k--)
        {
            printf("*");
        }
        for(j=1;j<=i;j++)
        {
            printf("  ");
        }
        for(k=L;k>=i;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=L;i>=1;i--)
    {
        for(k=i;k<=L;k++)
        {
            printf("*");
        }
        for(j=i;j>=1;j--)
        {
            printf("  ");
        }
        for(k=i;k<=L;k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void main()
{
    Pattern(5);
}
/*output
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
*/
