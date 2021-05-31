#include<iostream>
#include<conio.h>
using namespace std;

class Sort
{
    int a[10],No,i,j,k,Min;
public:
    void getdata();
    void Sortdata();
    void displaydata();
};
void Sort::getdata()
{
    cout<<"Enter No. of Elements to Enter:";
    cin>>No;
    for(i=1;i<=No;i++)
    {
        cout<<"Enter Element "<<i<<":";
        cin>>a[i];
    }
}
void Sort::Sortdata()
{
    for(i=1;i<=No;i++)
    {
        Min=i;
        for(j=i+1;j<=No;j++)
        {
            if(a[j]<a[Min])
            {
                Min=j;
            }
        }
        if(Min!=i)
        {
            int temp;
            temp=a[Min];
            a[Min]=a[i];
            a[i]=temp;
        }
    }
}
void Sort::displaydata()
{
    cout<<"Elements are:\n";
    for(i=1;i<=No;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int main()
{
    Sort g;
    g.getdata();
    g.Sortdata();
    g.displaydata();
}

