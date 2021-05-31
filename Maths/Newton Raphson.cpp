#include<iostream>
#include<math.h>
using namespace std;

class Method
{
public:
    double e=0.01;
    double equation(double x)
    {
        double f=(x-cos(x));
        return f;
    }
    double diffequation(double x)
    {
        double f=(1+sin(x));
        return f;
    }
    double formula(double a)
    {
        double F=(a-((equation(a))/diffequation(a)));
        return F;
    }
};
int main()
{
    double x0,x1,x2;
    Method M;
    cout<<"Enter Approx Roots:-";
    cin>>x0;
    do
    {
        x1=M.formula(x0);
        x2=M.formula(x1);
    }
    while((x2-x1)>=M.e);
    cout<<"Root of Equation="<<x2<<endl;
}
