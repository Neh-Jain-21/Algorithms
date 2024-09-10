/*AIM: Implementation of  Best-Fit Memory Allocation Algorithm

Algorithm

1. 	Declare  structures  hole  and  process  to  hold  information  about  set of holes  and processes respectively.
2.  Get number of holes, say nh.
3.  Get the size of each hole
4.  Get number of processes, say np.
5.  Get the memory requirements for each process.
6.  Allocate processes to holes, by examining each hole as follows:
a.  Sort the holes according to their sizes in ascending order b.  If hole size > process size then
i.  Mark process as allocated to that hole. ii.   Decrement hole size by process size.
c.  Otherwise check the next from the set of sorted hole
7.  Print the list of process and their allocated holes or unallocated status.
8.  Print the list of holes, their actual and current availability.
9.  Stop

Result

Thus processes were allocated memory using best fit method.


Program

Best fit allocation - bfit.c */

#include<stdio.h>
#include<conio.h>

struct process
{
    int size;
    int flag;
    int holeid;
};
struct hole
{
    int hid;
    int size;
    int actual;
};

int main()
{
    int i,np,nh,j,sum1=0,sum2=0,sum3=0;
    void bsort(struct hole[],int);
    printf("Enter No. of Holes=");
    scanf("%d",&nh);
    struct hole h[nh];
    for(i=0;i<nh;i++)
    {
        printf("Enter Size of Hole H%d=",i);
        scanf("%d",&h[i].size);
        h[i].actual=h[i].size;
        h[i].hid=i;
    }
    for(i=0;i<nh;i++)
    {
        sum1=sum1+h[i].size;
    }
    printf("\nEnter No. of Process=");
    scanf("%d",&np);
    struct process p[np];
    for(i=0;i<np;i++)
    {
        printf("Enter Size of process P%d=",i);
        scanf("%d",&p[i].size);
        p[i].flag=0;
    }
    for(i=0;i<np;i++)
    {
        sum2=sum2+p[i].size;
    }
    for(i=0;i<np;i++)
    {
        bsort(h,nh);
        for(j=0; j<nh; j++)
        {
            if(p[i].flag!=1)
            {
                if(p[i].size<=h[j].size)
                {
                    p[i].flag = 1;
                    p[i].holeid = h[j].hid;
                    h[j].size=h[j].size-p[i].size;
                }
            }
        }
    }
    printf("\n--------Best Fit--------\n");
    printf("|----------------------|");
    printf("\n|Process| PSize\t| Hole |");
    printf("\n|----------------------|");
    for(i=0;i<np;i++)
    {
        if(p[i].flag!=1)
        {
            printf("\n| P%d\t| %d\t|  NA  |",i,p[i].size);
        }
        else
        {
            printf("\n| P%d\t| %d\t|  H%d  |",i,p[i].size,p[i].holeid);
        }
    }
    printf("\n|----------------------|\n");
    printf("\n-------Process Table-------");
    printf("\n|-------------------------|");
    printf("\n|  Hole\t| Actual|Available|");
    printf("\n|-------------------------|");
    for(i=0;i<nh;i++)
    {
        printf("\n|   H%d\t|  %d\t|  %d\t  |", h[i].hid, h[i].actual, h[i].size);
    }
    printf("\n|-------------------------|");
    for(i=0;i<nh;i++)
    {
        sum3=sum3+h[i].size;
    }
    printf("\n");
    printf("\nTotal Hole Size:-%d",sum1);
    printf("\nTotal Process Size:-%d",sum2);
    printf("\nTotal Wastage of Memory:-%d",sum3);
}
void bsort(struct hole bh[],int n)
{
    struct hole temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bh[i].size>bh[j].size)
            {
                temp=bh[i];
                bh[i]=bh[j];
                bh[j]=temp;
            }
        }
    }
}
