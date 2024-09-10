#include<stdio.h>
#include<conio.h>

void main()
{
    int len,nf,i,j,k,l,temp,hitcount=0,faultcount;
    float faultratio,hitratio;
    printf("Enter Length of Page Reference String=");
    scanf("%d",&len);
    printf("Enter No. of Page Frames=");
    scanf("%d", &nf);
    int count,rs[len],statuscount[len],fs[nf],frame[nf],found[nf];
    printf("Enter Page Reference String :-\n");
    for(i=0; i<len; i++)
    {
        printf("[Reference String %d]=",i+1);
        scanf("%d", &rs[i]);
        statuscount[i]=0;
    }
    int max,index,flag1=0,flag2=0,pf=0,frsize=3;
    for(i=0;i<nf;i++)
    {
        frame[i]=-1;
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
    for(i=0;i<=nf;i++)
	{
	    printf("\n|    %4d        |", rs[i]);
	    for(j=0;j<nf;j++)
        {
            if(frame[j]==rs[i])
            {
                hitcount++;
                statuscount[i]=1;
                goto END2;
            }
            else
            {
                if(frame[j]==-1)
                {
                    frame[j]=rs[i];
                    goto END2;
                }
            }
        }
        END2:
        //print
        for(j=0;j<nf;j++)
        {
            if(frame[j]==-1)
            {
                printf("   -");
            }
            else
            {
                printf("%4d",frame[j]);
            }
        }
        if(statuscount[i]==1)
        {
            printf(" |    HIT      |");
        }
        else
        {
            printf(" |    MISS     |");
        }
    }
    count=0;
    for(i=nf+1;i<len;i++)
    {
        printf("\n|    %4d        |", rs[i]);
        for(j=0;j<nf;j++)
        {
            if(frame[j]==rs[i])
            {
                hitcount++;
                statuscount[i]=1;
                goto END;
            }
        }
        for(j=0;j<nf;j++)
        {
            found[j]=0;
        }
        for(j=i;j<len;j++)
        {
            for(k=0;k<nf;k++)
            {
                if(rs[j]==frame[k])
                {
                    found[k]=1;
                }
                for(l=0;l<nf;l++)
                {
                    temp=temp+found[l];
                }
                if(temp==3)
                {
                    goto ENDA;
                }
                else
                {
                    goto ENDB;
                }
            }
        }
        ENDA:
        for(j=0;j<nf;j++)
        {
            if(found[j]==0)
            {
                frame[j]=rs[i];
                goto END;
            }
        }
        ENDB:
        frame[count]=rs[i];
        count++;
        END:
        //print
        for(j=0;j<nf;j++)
        {
            if(frame[j]==-1)
            {
                printf("   -");
            }
            else
            {
                printf("%4d",frame[j]);
            }
        }
        if(statuscount[i]==1)
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
    faultcount=len-hitcount;
	printf("\n\nTotal Page Fault=%d",faultcount);
	faultratio=(float)faultcount/(float)len;
    printf("\nPage Fault Ratio=%f",faultratio);
    hitratio=(float)hitcount/(float)len;
    printf("\nPage Hit Ratio=%f",hitratio);
    getch();
}
