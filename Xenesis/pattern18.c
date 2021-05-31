#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,l=0;
    for (i=1;i<=n;i++)
    {
        for(k=n;k>i;k--)
        {
            printf("  ");
        }
        for (j=i;j>=1;j--)
        {
            printf("%d ",j);
        }
        for (j=2;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}
void main()
{
    Pattern(6);
}
/*output
          1
        2 1 2
      3 2 1 2 3
    4 3 2 1 2 3 4
  5 4 3 2 1 2 3 4 5
6 5 4 3 2 1 2 3 4 5 6
*/
