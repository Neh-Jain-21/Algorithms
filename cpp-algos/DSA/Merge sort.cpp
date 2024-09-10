#include<iostream>
#include<conio.h>
using namespace std;

class Sort
{
    int i,j,k;
public:
    void Sortdata(int[],int,int,int);
    void Merge(int[],int,int);
};
void Sort::Merge(int a[],int lb,int ub)
{
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        Merge(a,lb,mid);
        Merge(a,mid+1,ub);
        Sortdata(a,lb,ub,mid);
    }
}
void Sort::Sortdata(int a[],int lb,int ub,int mid)
{
    int i,j,k,temp[10];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=ub)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=lb;i<k;i++)
    {
        a[i]=temp[i];
    }
}
int main()
{
    int a[10],No,i,j,k,Min;
    Sort g;
    cout<<"Enter No. of Elements to Enter:";
    cin>>No;
    for(i=0;i<No;i++)
    {
        cout<<"Enter Element "<<i+1<<":";
        cin>>a[i];
    }
    g.Merge(a,0,No-1);

    cout<<"Sorted elements are:\n";
    for(i=0;i<No;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}


