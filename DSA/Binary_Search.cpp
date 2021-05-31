#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Search
{
    int a[10],i,Data1,first,No,last,middle;
public:
    void Data();
    void Display();
    int Find();
};
void Search::Data()
{
    cout<<"Enter No. of Elements to Enter:";
    cin>>No;
    for(i=0;i<No;i++)
    {
        cout<<"Enter Element "<<i+1<<":";
        cin>>a[i];
    }
}
void Search::Display()
{
    cout<<"Elements are:\n";
    for(i=0;i<No;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
int Search::Find()
{
    cout<<"Enter Data to Search:";
    cin>>Data1;
    first=0;
    last=No;
    middle=(first+last)/2;
    while(first<=last)
    {
        if(a[middle]<Data1)
        {
            first=middle+1;
        }
        else if(a[middle]==Data1)
        {
            cout<<Data1<<" Found at position "<<middle+1<<endl;
            break;
        }
        else
        {
            last=middle-1;
        }
        middle=(first+last)/2;
    }
    if(first>last)
    {
        cout<<Data1<<" not Found"<<endl;
    }
    return 0;
}
int main()
{
    Search S;
    int choice,key,data;
    cout << "1. Insert"<<endl;
    cout << "2. Find"<<endl;
    cout << "3. Exit"<<endl<<endl;
    while(choice!=3)
    {
        S.Display();
        cout << "-----------------------\n";
        cout <<"Choice:";
        cin >>choice;
        switch(choice)
        {
            case 1:
                S.Data();
                break;
            case 2:
                S.Find();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice"<<endl;
        }
    }
}
