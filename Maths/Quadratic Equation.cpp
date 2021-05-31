#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a,b,c,root;
    cout<<"Enter a=";
    cin>>a;
    cout<<"Enter b=";
    cin>>b;
    cout<<"Enter c=";
    cin>>c;
    cout<<"Quadratic Equation="<<a<<"(x^2)+"<<"("<<b<<"x)+"<<"("<<c<<")"<<endl;
    double discrminant=(b*b)-(4*a*c);
    if(discrminant<0)
    {
        cout<<"No Real Roots";
    }
    else if(discrminant==0)
    {
        cout<<"One Root Exists"<<endl;
        root=(-(b)/(2*a));
        cout<<"Root="<<root;
    }
    else
    {
        cout<<"Two Root Exists"<<endl;
        root=((-(b)+pow(discrminant,0.5))/(2*a));
        cout<<"Root1="<<root<<endl;
        root=((-(b)-pow(discrminant,0.5))/(2*a));
        cout<<"Root2="<<root<<endl;
    }
}
