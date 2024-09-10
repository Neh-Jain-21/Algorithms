#include<iostream>
#include<math.h>
using namespace std;

class Method
{
public:
    double Block(double P,int i)
    {
        double T=P;
        for(int j=1;j<i;j++)
        {
            T=T*(P-j);
        }
        return T;
    }
    double factorial(int i)
    {
        int fact=1;
        for(int j=2;j<=i;j++)
        {
            fact=fact*j;
        }
        return fact;
    }
};
int main()
{
    int x,y,i,j;
    Method M;
    cout<<"Enter No. of X & Y:-";
    cin>>x;
    double X[x],Y[x][x],xx;
    for(i=0;i<x;i++)
    {
        cout<<"Enter X"<<i<<"=";
        cin>>X[i];
    }
    cout<<"\n";
    for(i=0;i<x;i++)
    {
        cout<<"Enter Y"<<i<<"=";
        cin>>Y[i][0];
    }
    for(i=1;i<x;i++)
    {
        for(j=0;j<x-i;j++)
        {
            Y[j][i]=Y[j+1][i-1]-Y[j][i-1];
        }
    }
    cout<<"\n";
    cout<<"Forward Interpolation Table:-"<<endl;
    cout<<"X\tY\t";
    for(i=0;i<x-1;i++)
    {
        cout<<"Y"<<i+1<<"\t";
    }
    cout<<endl;
    for(i=0;i<x;i++)
    {
        cout<<X[i]<<"\t";
        for(j=0;j<x-i;j++)
        {
            cout<<Y[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n";
    cout<<"Enter Value to Find:-";
    cin>>xx;
    double ans=Y[0][0];
    double P=((xx-X[0])/(X[1]-X[0]));
    for(i=1;i<x;i++)
    {
        ans=ans+((M.Block(P,i)*Y[0][i])/(M.factorial(i)));
    }
    cout<<"Answer="<<ans<<endl;
}
