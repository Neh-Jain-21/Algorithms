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
        int ch='A';
        for (j=i;j>1;j--)
        {
            printf("%c ",ch);
            ch++;
        }
        for (j=1;j<=i;j++)
        {
            printf("%c ",ch);
            ch--;
        }
        printf("\n");
    }
}
void main()
{
    Pattern(6);
}
/*output
          A
        A B A
      A B C B A
    A B C D C B A
  A B C D E D C B A
A B C D E F E D C B A
*/
