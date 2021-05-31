#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j,k;
    char ch='A';
    for(i=1;i<=L;i++)
    {
        for(k=L;k>i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            if(i%2==0)
            {
                printf("%d ",i);
            }
            else
            {
                printf("%c ",ch);
            }
        }
        printf("\n");
        ch++;
    }
}
void main()
{
    Pattern(5);
}
/*output
    A
   2 2
  C C C
 4 4 4 4
E E E E E
*/
