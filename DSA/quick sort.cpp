#include<iostream>
#include<conio.h>
using namespace std;

class Sort
{
    int i,j,k,Min;
public:
    void Sortdata(int[],int,int);
    int Partition(int[],int,int);
};
int Sort::Partition(int a[],int start,int End)
{
    i=start+1;
    int piv=a[start];
    for(int j=start+1;j<=End;j++)
    {
        if(a[j]<piv)
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[start],a[i-1]);
    return i-1;
}
void Sort::Sortdata(int a[],int start,int End)
{
    if(start<End)
    {
        int pos=Partition(a,start,End);
        Sortdata(a,start,pos-1);
        Sortdata(a,pos+1,End);
    }
}
int main()
{
    int a[5],No,i,j,k,Min;
    Sort g;
    cout<<"Enter No. of Elements to Enter:";
    cin>>No;
    for(i=0;i<No;i++)
    {
        cout<<"Enter Element "<<i+1<<":";
        cin>>a[i];
    }
    g.Sortdata(a,0,No-1);

    cout<<"Sorted elements are:\n";
    for(i=0;i<No;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

