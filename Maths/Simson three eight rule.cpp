#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
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
        float E=(1/(1+(x*x)));
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
        float add2=arr[1].Y;
        for(j=2;j<i-1;j=j+2)
        {
            add2=add2+arr[j].Y;
        }
        return add2;
    }
    float Addition3(int i)
    {
        int j;
        float add3=0;
        if(i>3)
        {
            for(j=3;j<i-2;j=j+3)
            {
                add3=add3+arr[j].Y;
            }
        }
        return add3;
    }
    float mainAddition(int i)
    {
        float ans;
        ans=(((3*h)/8)*((Addition1(i))+(3*(Addition2(i)))+(2*(Addition3(i)))));
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
    no=((mini+maxi)/h)+1;
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
        cout<<setprecision(5)<<X[i]<<"\t";
    }
    cout<<endl;
    cout<<"f(x)\t";
    for(i=0;i<no;i++)
    {
        cout<<setprecision(5)<<arr[i].Y<<"\t";
    }
    cout<<"\n\n";
    answer=M.mainAddition(no);
    cout<<"Answer="<<answer;
    printf("\n");
}
