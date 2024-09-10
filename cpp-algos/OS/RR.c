#include<stdio.h>
#include<conio.h>

struct Process{
    int pr,p;
};
int main()
{
    int m,no,i,k=0,q;
    float at,aw,tp,att=0,awt=0;
    printf("Enter No. of Processes=");
    scanf("%d",&no);
    printf("Enter Quantum=");
    scanf("%d",&q);
    struct Process arr[no];
    struct Process temp;
    int tt[no],wt[no],j[no],a[no];
    printf("\n");
    for(i=0;i<no;i++)
    {
        arr[i].pr=i+1;
        printf("[ Process %d ]\n",arr[i].pr);
        printf("Enter Process Time=");
        scanf("%d",&arr[i].p);
        printf("\n");
    }
    //Question Table
    printf("\n");
    printf("-------------- Table ------------");
    printf("\n");
    printf("|-------------------------------|");
    printf("\n");
    printf("|    Process    |Processing Time|");
    printf("\n");
    printf("|-------------------------------|");
    printf("\n");
    for(i=0;i<no;i++)
    {
        printf("|\tP%d\t|\t%d\t|",arr[i].pr,arr[i].p);
        printf("\n");
    }
    printf("|-------------------------------|");
    printf("\n");
    printf("\n");
    //gannt Chart
    printf("---------- Gantt Chart ---------- ");
    printf("\n");
    //line up
    k=0;
    for(i=0;i<no;i++)
    {
        j[i]=arr[i].p;
    }
    start3:
    for(i=0;i<no;i++)
    {
        if(j[i]<=0)
        {
            goto end3;
        }
        if(j[i]>q)
        {
            k=k+q;
        }
        else
        {
            k=k+j[i];
        }
        j[i]=j[i]-q;
        printf(" -------");
        end3:
        {

        }
    }
    for(i=0;i<no;i++)
    {
        if(j[i]>0)
        {
            goto start3;
        }
    }
    //process
    k=0;
    printf("\n");
    for(i=0;i<no;i++)
    {
        j[i]=arr[i].p;
    }
    start:
    for(i=0;i<no;i++)
    {
        if(j[i]<=0)
        {
            goto end;
        }
        if(j[i]>q)
        {
            k=k+q;
        }
        else
        {
            k=k+j[i];
        }
        j[i]=j[i]-q;
        printf("|  P %d  ",arr[i].pr);
        end:
        {

        }
    }
    for(i=0;i<no;i++)
    {
        if(j[i]>0)
        {
            goto start;
        }
    }
    printf("|\n");
    //line down
    k=0;
    for(i=0;i<no;i++)
    {
        j[i]=arr[i].p;
    }
    start2:
    for(i=0;i<no;i++)
    {
        if(j[i]<=0)
        {
            goto end2;
        }
        if(j[i]>q)
        {
            k=k+q;
        }
        else
        {
            k=k+j[i];
        }
        j[i]=j[i]-q;
        printf(" -------");
        end2:
        {

        }
    }
    for(i=0;i<no;i++)
    {
        if(j[i]>0)
        {
            goto start2;
        }
    }
    printf("\n");
    printf("0     \t");
    //value
    k=0;
    for(i=0;i<no;i++)
    {
        j[i]=arr[i].p;
    }
    start1:
    for(i=0;i<no;i++)
    {
        if(j[i]<=0)
        {
            goto end1;
        }
        if(j[i]>q)
        {
            k=k+q;
        }
        else
        {
            k=k+j[i];
        }
        j[i]=j[i]-q;
        printf("%d\t",k);
        a[i]=k;
        end1:
        {

        }
    }
    for(i=0;i<no;i++)
    {
        if(j[i]>0)
        {
            goto start1;
        }
    }
    //main Table
    printf("\n");
    printf("\n");
    printf("------------------------------ RR Process Table ---------------------------------");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|Completion Time|Process Completed|Processing Time|Turnaround Time|Waiting Time |");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|       0       |         -       |      0        |      0        |     0       |");
    printf("\n");
    for(i=0;i<no;i++)
    {
        tt[i]=a[i]-0;
        wt[i]=tt[i]-arr[i].p;
        printf("| \t%d\t|\t P%d\t  | \t %d\t  |\t %d\t  |\t%d\t|",a[i],arr[i].pr,arr[i].p,tt[i],wt[i]);
        printf("\n");
        att=att+tt[i];
        awt=awt+wt[i];
    }
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("\n");
    at=att/no;
    aw=awt/no;
    tp=no/(float)k;
    printf("Average Waiting Time=%f ms",aw);
    printf("\n");
    printf("Average Turnaround Time=%f ms",at);
    printf("\n");
    printf("CPU Utilization=100 %%");
    printf("\n");
    printf("Average Throughtput=%f process/sec",tp);
    printf("\n");
}
