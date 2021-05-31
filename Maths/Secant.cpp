#include<iostream>
#include<math.h>
using namespace std;

class Method
{
public:
    double equation(double x)
    {
        double f=pow(x,2)-(4*x)-10;
        return f;
    }
    double formula(double a,double b)
    {
        double F=b-((equation(b)*(b-a))/(equation(b)-(equation(a))));
        return F;
    }
};
int main()
{
    double x,x1,x2,i,j,f,stage;
    Method M;
    cout<<"Enter Initial Estimate:-"<<endl;
    cout<<"Enter x1=";
    cin>>x2;
    cout<<"Enter x2=";
    cin>>x1;
    cout<<"Enter Stage=";
    cin>>stage;
    for(i=1;i<=stage;i++)
    {
        x=M.formula(x1,x2);
        x2=x1;
        x1=x;
    }
    cout<<"Estimated root="<<x;
}

