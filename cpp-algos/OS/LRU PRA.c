#include <stdio.h>

struct LRU
{
    int id,frame,usecount,statuscount;
};
main()
{
    int i,j,k,len,nf,hitcount=0,faultcount;
    float faultratio,hitratio;
    printf("Enter Length of Page Reference String=");
    scanf("%d", &len);
    int rs[len];
    struct LRU status[len];
    printf("Enter No. of Page Frames=");
    scanf("%d", &nf);
    struct LRU arr[nf];
    struct LRU temp;
    printf("Enter Page Reference String :-\n");
    for(i=0; i<len; i++)
    {
        printf("[Reference String %d]=",i+1);
        scanf("%d", &rs[i]);
        status[i].statuscount=0;
    }
    for(i=0; i<nf; i++)
    {
        arr[i].id=i;
        arr[i].usecount=0;
        arr[i].frame=-1;
    }
    //table
    //main heading
    printf("\n");
    for(i=0;i<nf;i++)
    {
        printf("   ");
    }
    printf("LRU Page Replacement Table");
    printf("\n|----------------");
    for(i=0;i<nf;i++)
    {
        printf("-----");
    }
    if(nf%2==0)
    {
        printf("------------|");
    }
    else
    {
        printf("-------------|");
    }
    printf("\n|Reference String|");
    for(i=0;i<nf;i++)
    {
        printf("%4d",arr[i].id);
    }
    printf(" | Page Status |");
    //line down
    printf("\n|----------------");
    for(i=0;i<nf;i++)
    {
        printf("-----");
    }
    if(nf%2==0)
    {
        printf("------------|");
    }
    else
    {
        printf("-------------|");
    }
    //main logic
    for(i=0;i<nf;i++)
    {
        printf("\n|    %4d        |",rs[i]);
        //non main logic
        for(j=0;j<nf;j++)
        {
            if(arr[j].frame==rs[i])
            {
                arr[j].usecount++;
                status[i].statuscount=1;
                goto END2;
            }
            else
            {
                if(arr[j].frame==-1)
                {
                    arr[j].frame=rs[i];
                    arr[j].usecount++;
                    goto END2;
                }
            }
        }
        END2:
        //print
        for(j=0; j<nf; j++)
        {
            if(arr[j].frame==-1)
            {
                printf("   -");
            }
            else
            {
                printf("%4d",arr[j].frame);
            }
        }
        if(status[i].statuscount==1)
        {
            printf(" |    HIT      |");
        }
        else
        {
            printf(" |    MISS     |");
        }
    }
    for(i=nf;i<len;i++)
    {
        printf("\n|    %4d        |",rs[i]);
        //bubble sort usecount
        for(j=1;j<nf;j++)
        {
            for(k=0;k<nf-j;k++)
            {
                if(arr[k].usecount>arr[k+1].usecount)
                {
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }
        //non main logic
        for(j=0;j<nf;j++)
        {
            if(arr[j].frame==rs[i])
            {
                arr[j].usecount++;
                status[i].statuscount=1;
                goto END;
            }
        }
        arr[0].frame=rs[i];
        arr[0].usecount++;
        END:
        //bubble sort id
        for(j=1;j<nf;j++)
        {
            for(k=0;k<nf-j;k++)
            {
                if(arr[k].id>arr[k+1].id)
                {
                    temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;
                }
            }
        }
        //print
        for(j=0; j<nf; j++)
        {
            if(arr[j].frame==-1)
            {
                printf("   -");
            }
            else
            {
                printf("%4d",arr[j].frame);
            }
        }
        if(status[i].statuscount==1)
        {
            printf(" |    HIT      |");
        }
        else
        {
            printf(" |    MISS     |");
        }
    }
    //last line
    printf("\n|----------------");
    for(i=0;i<nf;i++)
    {
        printf("-----");
    }
    if(nf%2==0)
    {
        printf("------------|");
    }
    else
    {
        printf("-------------|");
    }
    for(i=0;i<len;i++)
    {
        if(status[i].statuscount==1)
        {
            hitcount++;
        }
    }
    faultcount=len-hitcount;
    printf("\n\nTotal Page Fault=%d",faultcount);
    faultratio=(float)faultcount/(float)len;
    printf("\nPage Fault Ratio=%f",faultratio);
    hitratio=(float)hitcount/(float)len;
    printf("\nPage Hit Ratio=%f",hitratio);
    getch();
}
