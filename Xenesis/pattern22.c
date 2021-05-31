#include<stdio.h>
#include<conio.h>

void Pattern(int n)
{
    int i,j,k,l=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==n/2 || i-j==n/2 || i+j==n/2)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
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
    *
  *
* * * * *
  *
    *
*/
