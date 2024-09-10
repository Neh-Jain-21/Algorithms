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
        printf("1");
        if (i>0)
        {
            for(k=1;k<=s;k++)
            {
                printf(" ");
            }
            s=s+2;
            printf("%d",i+1);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",i);
    }
}
void main()
{
    Pattern(5);
}
/*output
    1
   1 2
  1   3
 1     4
1 2 3 4 5
*/
