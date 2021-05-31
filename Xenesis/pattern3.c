#include<stdio.h>
#include<conio.h>

void Pattern(int L)
{
    int i,j,k;
    printf("\n");
    for(i=L;i>=1;i--)
    {
        for(k=i+1;k<=L;k++)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void main()
{
    Pattern(5);
    getch();
}
/*output
*****
 ****
  ***
   **
    **/
