#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j;
    for(i=1;i<=L;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",j);
        }
        printf("\n");
    }
}
int main()
{
    Pattern(5);
}
/*output
1
1 2
1 2 3
1 2 3 4*/

