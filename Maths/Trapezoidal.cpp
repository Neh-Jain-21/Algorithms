#include<iostream>
#include<math.h>
using namespace std;

struct Trapezoidal
{
    float Y;
};
struct Trapezoidal arr[20];
class Method
{
    float e=2.7125,h;
public:
    float Equation(float x)
    {
        float E=pow(e,x);
        return E;
    }
    float Hvalue(float i)
    {
        h=i;
    }
    float Addition1(int i)
    {
        float add1=0;
        add1=arr[0].Y+arr[i-1].Y;
        return add1;
    }
    float Addition2(int i)
    {
        int j;
        float add2=0;
        for(j=1;j<i-1;j++)
        {
            add2=add2+arr[j].Y;
        }
        return add2;
    }
    float mainAddition(int i)
    {
        float ans;
        ans=((h/2)*((Addition1(i))+(2*(Addition2(i)))));
        return ans;
    }
};
int main()
{
    int no,y,i,j;
    float h,answer,maxi,mini;
    Method M;
    cout<<"Enter Min Value=";
    cin>>mini;
    cout<<"Enter Max Value=";
    cin>>maxi;
    cout<<"Enter h=";
    cin>>h;
    M.Hvalue(h);
    no=((mini+maxi)/h)+2;
    float X[no];
    X[0]=mini;
    for(i=1;i<no;i++)
    {
        X[i]=X[i-1]+h;
    }
    for(i=0;i<no;i++)
    {
        arr[i].Y=M.Equation(X[i]);
    }
    cout<<endl;
    cout<<"Table:-";
    cout<<endl;
    cout<<"x\t";
    for(i=0;i<no;i++)
    {
        cout<<X[i]<<"\t";
    }
    cout<<endl;
    cout<<"f(x)\t";
    for(i=0;i<no;i++)
    {
        cout<<""<<arr[i].Y<<"\t";
    }
    cout<<"\n\n";
    answer=M.mainAddition(no);
    cout<<"Answer="<<answer<<endl;
    cout<<"\n";
}
