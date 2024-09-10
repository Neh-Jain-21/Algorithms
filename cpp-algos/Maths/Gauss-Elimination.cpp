#include<iostream>
#include<math.h>
using namespace std;

class Method
{
public:
    double e=0.01;
    double equation1(double y,double z)
    {
        double x=(((5*y)+(2*z)+3)/10);
        return x;
    }
    double equation2(double x,double z)
    {
        double y=(((4*x)+(3*z)+3)/10);
        return y;
    }
    double equation3(double x,double y)
    {
        double z=(((-x)+(-6*y)-3)/10);
        return z;
    }
};
int main()
{
    double x,y,z,x1,y1,z1;
    Method M;
    x1=M.equation1(0,0);
    y1=M.equation2(0,0);
    z1=M.equation3(0,0);
    do
    {
        x=M.equation1(y1,z1);
        y=M.equation2(x1,z1);
        z=M.equation3(x1,y1);
        x1=x;
        y1=y;
        z1=z;
    }
    while(x1-x>=M.e && y1-y>=M.e && z1-z>=M.e);
    cout<<"Roots of Equation is:-"<<endl;
    cout<<"x="<<x1<<endl;
    cout<<"y="<<y1<<endl;
    cout<<"z="<<z1<<endl;
}
