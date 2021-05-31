#include<stdio.h>
#include<conio.h>

struct Process{
    int pr,pt,p;
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
        printf("Enter Process Time=");
        scanf("%d",&arr[i].pt);
        printf("Enter Priority No.=");
        scanf("%d",&arr[i].p);
        printf("\n");
    }
    //Bubble Sort
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(arr[j].p>arr[j+1].p)
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
    printf("|   Process id  |Processing Time|    Priority   |");
    printf("\n");
    printf("|-----------------------------------------------|");
    printf("\n");
    for(i=0;i<no;i++)
    {
        printf("|\tP%d\t|\t%d\t|\t%d\t|",arr[i].pr,arr[i].pt,arr[i].p);
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
        k=k+arr[i].pt;
        printf("%d\t",k);
    }
    //main Table
    printf("\n");
    printf("\n");
    printf("------------------------------ PB Process Table ---------------------------------");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|Completion Time|Process Completed|Processing Time|Turnaround Time|Waiting Time |");
    printf("\n");
    printf("|-------------------------------------------------------------------------------|");
    printf("\n");
    printf("|       0       |         -       |      0        |      0        |     0       |");
    printf("\n");
    k=0;
    for(i=0;i<no;i++)
    {
        k=k+arr[i].pt;
        tt[i]=k;
        wt[i]=tt[i]-arr[i].pt;
        printf("| \t%d\t|\t  P%d\t  | \t %d\t  |\t %d\t  |\t%d\t|",k,arr[i].pr,arr[i].pt,tt[i],wt[i]);
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

