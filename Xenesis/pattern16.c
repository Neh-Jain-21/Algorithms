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
            printf("%c ",ch);
        }
        ch++;
        printf("\n");
    }
}
void main()
{
    Pattern(5);
}
/*output
    A
   B B
  C C C
 D D D D
E E E E E
*/


