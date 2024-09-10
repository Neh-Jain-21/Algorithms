#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,l=0;
    char ch='A';
    for (i = 1; i <= 2*n; i=i+2)
    {
        for(k=2*n;k>i;k=k-2)
        {
            printf("  ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%c ",ch+l);
            if(j <= i/2)
            {
                l++;
            }
            else
            {
                l--;
            }
        }
        l = 0;
        printf("\n");
    }
}
void main()
{
    Pattern(5);
}
/*output
          A
        A B A
      A B C B A
    A B C D C B A
  A B C D E D C B A
*/


