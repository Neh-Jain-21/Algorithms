#include <stdio.h>
#include <string.h>

main()
{
    int i,j,l,rs[50],frame[10],nf,k,avail,count=0;
    float faultratio,hitratio;
    printf("Enter Length of Page Reference String=");
    scanf("%d",&l);
    printf("Enter No. of Page Frames=");
    scanf("%d", &nf);
    printf("Enter Page Reference String :-\n");
    for(i=1; i<=l; i++)
    {
        printf("[Reference String %d]=",i);
        scanf("%d", &rs[i]);
    }
    for(i=0; i<nf; i++)
    {
        frame[i] = -1;
    }
    j = 0;
    //table
    //main heading
    printf("\n");
    for(i=0;i<nf;i++)
    {
        printf("   ");
    }
    printf("FIFO Page Replacement Table");
    //line up
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
    //middle line
    printf("\n|Reference String|");
    for(i=0;i<nf;i++)
    {
        printf("%4d",i);
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
    for(i=1; i<=l; i++)
    {
        printf("\n|    %4d        |", rs[i]);
        avail = 0;
        for(k=0; k<nf; k++)
        {
            if(frame[k] == rs[i])
            {
                avail = 1;
            }
        }
        if(avail == 0)
        {
            frame[j] = rs[i];
            j = (j+1) % nf;
            count++;
            for(k=0; k<nf; k++)
            {
                if(frame[k]==-1)
                {
                    printf("   -");
                }
                else
                {
                    printf("%4d",frame[k]);
                }
            }
            printf(" |    MISS     |");
        }
        else
        {
            for(k=0; k<nf; k++)
            {
                printf("%4d",frame[k]);
            }
            printf(" |    HIT      |");
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
    printf("\n\nTotal Page Fault=%d",count);
    faultratio=(float)count/(float)l;
    printf("\nPage Fault Ratio=%f",faultratio);
    hitratio=((float)(l-count)/(float)l);
    printf("\nPage Hit Ratio=%f",hitratio);
    getch();
}
