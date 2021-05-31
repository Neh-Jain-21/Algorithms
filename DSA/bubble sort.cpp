#include<iostream>
#include<conio.h>
using namespace std;

class Sort
{
    int a[5],n,i,j,k,Min;
public:
    void getdata();
    void Sortdata();
    void displaydata();
};
void Sort::getdata()
{
    for(i=0;i<5;i++)
    {
        cout<<"enter data "<<i+1<<"=";
        cin>>a[i];
    }
}
void Sort::Sortdata()
{
    for(i=1;i<5;i++)
    {
        for(j=0;j<5-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void Sort::displaydata()
{
    cout<<"sorted data=";
    for(i=0;i<5;i++)
    {
        cout<<a[i];
    }
}
int main()
{
    Sort g;
    g.getdata();
    g.Sortdata();
    g.displaydata();
}

