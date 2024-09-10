#include<iostream>
#include<conio.h>
using namespace std;

void TOH(int n,char source,char auxilliary,char destination)
{
    if(n>=1)
    {
       TOH(n-1,source,destination,auxilliary);
       cout<<"move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
       TOH(n-1,auxilliary,source,destination);
    }
}
int main()
{
    cout<<"Enter no. of Disks=";
    int no;
    cin>>no;
    TOH(no,'s','a','d');
    getch;
    return 0;
}
