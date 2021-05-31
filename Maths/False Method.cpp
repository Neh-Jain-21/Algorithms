#include<iostream>
#include<math.h>
using namespace std;

class Method
{
public:
    double e=0.002;
    double equation(double x)
    {
        double f=pow(x,3)-(3*x)+4;
        return f;
    }
    double formula(double a,double b)
    {
        double F=(((a*equation(b))-(b*equation(a)))/(equation(b)-equation(a)));
        return F;
    }
};
int main()
{
    double x,x1,x2,i,j,f;
    Method M;
    start:
    cout<<"Enter A=";
    cin>>x1;
    cout<<"Enter B=";
    cin>>x2;
    double f1=M.equation(x1);
    double f2=M.equation(x2);
    if(f1*f2>=0)
    {
        cout<<"Enter correct A & B"<<endl;
        goto start;
    }
    else
    {
        do
        {
            x=M.formula(x1,x2);
            f=M.equation(x);
            if(f>0)
            {
                x1=x;
            }
            else
            {
                x2=x;
            }
        }
        while((x2-x1)>M.e);
        cout<<"Root of Equation="<<x;
    }
}

