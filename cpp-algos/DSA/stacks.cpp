#include<iostream>
using namespace std;

class stacks
{
    int i=5,j,top=-1;
    int q[5];
public:
    void push(int);
    int pop();
    void peep(int);
    void change(int,int);
    void display();
};
void stacks::push(int x)
{
    if(top>=i-1)
    {
       cout<<"STACK is OVERFLOW"<<endl;
    }
    else
    {
        top++;
        q[top]=x;
    }
}
void stacks::display()
{
    if(top<0)
    {
        cout<<"STACK is Underflow"<<endl;
    }
    else
    {
        for(j=top;j>=0;j--)
        {
            cout<<q[j]<<"\n";
        }
    }
}
int stacks::pop()
{
    int temp;
    if(top<=-1)
    {
        cout<<"STACK is Underflow"<<endl;
    }
    else
    {
        temp=q[i];
        top--;
    }
}
void stacks::peep(int y)
{
    if(top+1-y<=0)
    {
        cout<<"invalid choice"<<endl;
    }
    else
    {
        cout<<q[y]<<" at index "<<y<<endl;
    }
}
void stacks::change(int x,int y)
{
    if(x>5)
    {
        cout<<"invalid choice"<<endl;
    }
    else
    {
        int temp;
        temp=q[x];
        q[x]=y;
        y=temp;
    }
}
main()
{
    int a,b,c,d,s;
    stacks s1;
    cout<<"1:Push"<<endl;
    cout<<"2:Pop"<<endl;
    cout<<"3:Peep"<<endl;
    cout<<"4:Change"<<endl;
    cout<<"5:Display"<<endl;
    cout<<"6:Exit"<<endl;
    while(s!=6)
    {
        cout<<"Enter choice:";
        cin>>s;
        switch(s)
        {
            case 1:
                cout<<"Enter Data:";
                cin>>a;
                s1.push(a);
                break;
            case 2:
                s1.pop();
                s1.display();
                break;
            case 3:
                cout<<"Enter index:";
                cin>>b;
                s1.peep(b);
                break;
            case 4:
                cout<<"Enter index:";
                cin>>c;
                cout<<"Enter New Data:";
                cin>>d;
                s1.change(c,d);
                break;
            case 5:
                s1.display();
                break;
        }
    }
}
