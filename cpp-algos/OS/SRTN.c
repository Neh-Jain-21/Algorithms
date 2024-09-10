#include<stdio.h>
#include<conio.h>

struct Process
{
    int pr,a,p;
};
struct Temporary
{
    int t,K,tpr,tKr,atKr,atp;
};
int main()
{
    int no,i,k=0,j;
    float at,aw,tp,att=0,awt=0;
    printf("Enter No. of Processes=");
    scanf("%d",&no);
    struct Process arr[10];
    struct Temporary tem[10];
    struct Process temp;
    struct Temporary tempo;
    int tt[no],wt[no],t[no],m[no],K[no];
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
    //line up
    for(i=0;i<no;i++)
    {
        tem[i].t=arr[i].p;
    }
    for(i=0;i<no;i++)
    {
        if(i==0)
        {
            tem[i].t=tem[i].t-arr[i+1].a;
            printf(" -------");
        }
        if(i==no-1)
        {
            printf(" -------");
            tem[i].t=0;
        }
        if(i>=1 && i<=no-2)
        {
            if(tem[i].t<tem[i-1].t)
            {
                tem[i].t=tem[i].t-arr[i+1].a+arr[i].a;
                printf(" -------");
            }
            else
            {
                tem[i-1].t=tem[i-1].t-arr[i+1].a+arr[i].a;
                printf(" -------");
            }
        }
    }
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(tem[j].t>tem[j+1].t)
            {
                tempo=tem[j];
                tem[j]=tem[j+1];
                tem[j+1]=tempo;
            }
        }
    }
    for(i=0;i<no;i++)
    {
        if(tem[i].t!=0)
        {
            printf(" -------");
            tem[i].t=0;
        }
    }
    printf("\n");
    //main logic
    for(i=0;i<no;i++)
    {
        tem[i].t=arr[i].p;
        tem[i].tpr=arr[i].pr;
    }
    for(i=0;i<no;i++)
    {
        if(i==0)
        {
            tem[i].t=tem[i].t-arr[i+1].a;
            printf("|  P %d  ",arr[i].pr);
        }
        if(i==no-1)
        {
            printf("|  P %d  ",arr[i].pr);
            tem[i].t=0;
        }
        if(i>=1 && i<=no-2)
        {
            if(tem[i].t<tem[i-1].t)
            {
                tem[i].t=tem[i].t-arr[i+1].a+arr[i].a;
                printf("|  P %d  ",arr[i].pr);
            }
            else
            {
                tem[i-1].t=tem[i-1].t-arr[i+1].a+arr[i].a;
                printf("|  P %d  ",arr[i-1].pr);
            }
        }
    }
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(tem[j].t>tem[j+1].t)
            {
                tempo=tem[j];
                tem[j]=tem[j+1];
                tem[j+1]=tempo;
            }
        }
    }
    for(i=0;i<no;i++)
    {
        if(tem[i].t!=0)
        {
            printf("|  P %d  ",tem[i].tpr);
            tem[i].t=0;
        }
    }
    printf("|\n");
    //line down
    for(i=0;i<no;i++)
    {
        tem[i].t=arr[i].p;
    }
    for(i=0;i<no;i++)
    {
        if(i==0)
        {
            tem[i].t=tem[i].t-arr[i+1].a;
            printf(" -------");
        }
        if(i==no-1)
        {
            printf(" -------");
            tem[i].t=0;
        }
        if(i>=1 && i<=no-2)
        {
            if(tem[i].t<tem[i-1].t)
            {
                tem[i].t=tem[i].t-arr[i+1].a+arr[i].a;
                printf(" -------");
            }
            else
            {
                tem[i-1].t=tem[i-1].t-arr[i+1].a+arr[i].a;
                printf(" -------");
            }
        }
    }
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(tem[j].t>tem[j+1].t)
            {
                tempo=tem[j];
                tem[j]=tem[j+1];
                tem[j+1]=tempo;
            }
        }
    }
    for(i=0;i<no;i++)
    {
        if(tem[i].t!=0)
        {
            printf(" -------");
            tem[i].t=0;
        }
    }
    printf("\n");
    k=0;
    //Gantt Number
    printf("0     \t");
    for(i=0;i<no;i++)
    {
        tem[i].t=arr[i].p;
        tem[i].atKr=arr[i].p;
        tem[i].atp=arr[i].a;
    }
    for(i=0;i<no;i++)
    {
        if(i==0)
        {
            tem[i].t=tem[i].t-arr[i+1].a;
            k=k+arr[i+1].a-arr[i].a;
            if(tem[i].t==0)
            {
                tem[i].K=k;
                tem[i].tKr=i+1;
            }
            printf("%d\t",k);
        }
        if(i==no-1)
        {
            k=k+arr[i].p;
            tem[i].K=k;
            tem[i].tKr=i+1;
            printf("%d\t",k);
            tem[i].t=0;
        }
        if(i>=1 && i<=no-2)
        {
            if(tem[i].t<tem[i-1].t)
            {
                tem[i].t=tem[i].t-arr[i+1].a+arr[i].a;
                k=k+arr[i+1].a-arr[i].a;
                if(tem[i].t==0)
                {
                    tem[i].K=k;
                    tem[i].tKr=i+1;
                }
                printf("%d\t",k);
            }
            else
            {
                tem[i-1].t=tem[i-1].t-arr[i+1].a+arr[i].a;
                k=k+arr[i+1].a-arr[i].a;
                if(tem[i-1].t==0)
                {
                    tem[i-1].K=k;
                    tem[i-1].tKr=i;
                }
                printf("%d\t",k);
            }
        }
    }
    for(i=1;i<no;i++)
    {
        for(j=0;j<no-i;j++)
        {
            if(tem[j].t>tem[j+1].t)
            {
                tempo=tem[j];
                tem[j]=tem[j+1];
                tem[j+1]=tempo;
            }
        }
    }
    for(i=0;i<no;i++)
    {
        if(tem[i].t!=0)
        {
            k=k+tem[i].t;
            tem[i].K=k;
            tem[i].tKr=i;
            printf("%d\t",k);
            tem[i].t=0;
        }
    }
    printf("\n");
    //main Table
    printf("\n");
    printf("\n");
    printf("----------------------------- SRTN Process Table --------------------------------");
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
        tt[i]=tem[i].K-tem[i].atp;
        wt[i]=tt[i]-tem[i].atKr;
        printf("| \t%d\t|\t  P%d\t  | \t %d\t  |\t %d\t  |\t%d\t |",tem[i].K,tem[i].tKr,tem[i].atKr,tt[i],wt[i]);
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
