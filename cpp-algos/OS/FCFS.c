#include<stdio.h>
#include<conio.h>

struct Process
{
    int pr,a,p;
};
int main()
{
    int no,i,k=0,j;
    float at,aw,tp,att=0,awt=0;
    printf("Enter No. of Processes=");
    scanf("%d",&no);
    struct Process arr[no];
    struct Process temp;
    int tt[no],wt[no];
    printf("\n");
    for(i=0;i<no;i++)
    {
        arr[i].pr=i+1;
        printf("[ Process %d ]\n",arr[i].pr);
        printf("Enter Arrival Time=");
        scanf("%d",&arr[i].a);
        printf("Enter Process Time=");
        scanf("%d",&arr[i].p);
        printf("\n");
    }
    //Bubble Sort
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(arr[j].a>arr[j+1].a)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    //Question Table
    printf("\n");
    printf("---------------------- Table --------------------");
    printf("\n");
    printf("|-----------------------------------------------|");
    printf("\n");
    printf("|    Process    | Arrival Time  |Processing Time|");
    printf("\n");
    printf("|-----------------------------------------------|");
    printf("\n");
    for(i=0;i<no;i++)
    {
        printf("|\tP%d\t|\t%d\t|\t%d\t|",arr[i].pr,arr[i].a,arr[i].p);
        printf("\n");
    }
    printf("|-----------------------------------------------|");
    printf("\n");
    printf("\n");
    //gannt Chart
    printf("------------------ Gantt Chart ------------------ ");
    printf("\n");
    for(i=0;i<no;i++)
    {
        printf(" -------");
    }
    printf("\n");
    for(i=0;i<no;i++)
    {
        printf("|  P %d  ",arr[i].pr);
    }
    printf("|\n");
    for(i=0;i<no;i++)
    {
        printf(" -------");
    }
    printf("\n");
    printf("0     \t");
    for(i=0;i<no;i++)
    {
        k=k+arr[i].p;
        printf("%d\t",k);
    }
    //main Table
    printf("\n");
    printf("\n");
    printf("----------------------------- FCFS Process Table --------------------------------");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|Completion Time|Process Completed|Processing Time|Turnaround Time|Waiting Time |");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|       0         |       -       |      0        |      0        |     0       |");
    printf("\n");
    k=0;
    for(i=0;i<no;i++)
    {
        k=k+arr[i].p;
        tt[i]=k-arr[i].a;
        wt[i]=tt[i]-arr[i].p;
        printf("| \t%d\t  |\t  P%d\t  | \t %d\t  |\t %d\t  |\t%d\t|",k,arr[i].pr,arr[i].p,tt[i],wt[i]);
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
    printf("CPU Utilization=100 Percent");
    printf("\n");
    printf("Average Throughtput=%f process/sec",tp);
    printf("\n");
}
