#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Search
{
    int No,a[10],i,Data1;
public:
    void Data();
    void Display();
    void Find();
};
void Search::Data()
{
    cout<<"Enter No. of Elements to Enter:";
    cin>>No;
    for(i=1;i<=No;i++)
    {
        cout<<"Enter Element "<<i<<":";
        cin>>a[i];
    }
}
void Search::Display()
{
    cout<<"Elements are:\n";
    for(i=1;i<=No;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
void Search::Find()
{
    i=1;
    cout<<"Enter Data to Search:";
    cin>>Data1;
    while(a[i]!=Data1)
    {
        i++;
    }
    if(i<=No)
    {
        cout<<"Key is at:"<<i<<endl;
    }
    else
    {
        cout<<"Key not Found"<<endl;
    }
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
